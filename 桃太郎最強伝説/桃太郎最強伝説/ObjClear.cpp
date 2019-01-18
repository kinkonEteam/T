//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\UserData.h" 
#include "GameL\DrawFont.h"

#include"GameHead.h"
#include"ObjClear.h"

//使用するネームスペース
using namespace GameL;
extern int item_list[5];

//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = false;
}

//アクション
void CObjClear::Action()
{
	//ゲームスコアの初期化
	static bool init_point = false;
	if (init_point == false)
	{

		//ランキングも初期化する
		for (int i = 0; i < 10; i++)
		{
			((UserData*)Save::GetData())->m_ranking[i] = 0;
		}

		//ロード
		Save::Open();//同フォルダ「UserData」からデータ取得。

		((UserData*)Save::GetData())->m_point = 0;//点数を初期化する
		init_point = true;
	}

	int p = 0;
	//ここではアイテムごとにスコアを計算し'ｐ'にスコアの数値を渡している
	for (int i = 0; i<7;i++) 
	{
		if (i == 0)
		{
			p+=item_list[i] * 100;//白桃
		}
		else if (i==1)
		{
			p += item_list[i] * 1000;//黄桃
		}
		else if (i==2)
		{
			p += item_list[i] * 1;//すもも
		}
		else if (i==3)
		{
			p += item_list[i] * 3000;//角
		}
		else if (i==4)
		{
			p += item_list[i] * 10000;//金塊
		}
		else if (i==5)
		{
			p += item_list[i] * 5000;//銀塊
		}
		else if (i==6)
		{
			p += item_list[i] * 500;//棍棒
		}
	
	}
	
	//ここでスコアを決定する
	((UserData*)Save::GetData())->m_point = p;

	//エンターキーを押してシーン：タイトル移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneScore());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//ドロー
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;


	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//描画
	Draw::Draw(19, &src, &dst, c, 0.0f);

	//スコアの描画
	float se[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"Score:%d", ((UserData*)Save::GetData())->m_point);//スコアをとって？
	Font::StrDraw(str, 200, 400, 64, se); //こちらで画面に描画する位置や文字のサイズを変える
}