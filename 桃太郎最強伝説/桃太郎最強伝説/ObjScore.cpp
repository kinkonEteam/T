//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameL\UserData.h" 
#include "GameL\DrawFont.h"

#include"GameHead.h"
#include"ObjScore.h"

//使用するネームスペース
using namespace GameL;

void CObjScore::RankingSort(int rank[16])
{
	/*//値交換用変数
	int w;

	//バブルソート
	for (int i = 0; i < 15; i++)
	{
		for (int j = i + 1; j < 16; j++)
		{
			if (rank[i] < rank[j])
			{
				//値の交換
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;
			}
		}
	}
	CObjScore*obj = new CObjScore();
	Objs::InsertObj(obj, OBJ_SCORE, 10);*/
}

//イニシャライズ
void CObjScore::Init()
{
	/*m_key_flag = false;*/
	
}

//アクション
void CObjScore::Action()
{
	

	//エンターキーを押してシーン：タイトル移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	/*
	//ゲーム実行して一回のみ
	/*static bool init_point = false;
	if (init_point == false)
	{
	//得点の初期化
	((UserData*)Save::GetData())->m_point = 0;

	//ランキング初期化
	for (int i = 0; i < 16; i++)
	{
	((UserData*)Save::GetData())->m_point = 0;
	}
	init_point = true;
	}

	//得点情報をランキング最下位（描画圏外）に登録
	((UserData*)Save::GetData())->m_ranking[15] = ((UserData*)Save::GetData())->m_point;

	//得点が高い順に並び替えをする
	RankingSort(((UserData*)Save::GetData())->m_ranking);*/
}

//ドロー
void CObjScore::Draw()
{
	int a_top=0;
	int a_bottom=0;
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;


	//表示位置の設定
	dst.m_top = a_top+0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = a_bottom+600.0f;

	//ランキング
	Font::StrDraw(L"ランキング",230, 250, 50,c);

	/*for (int i = 0; i <16; i++)
	{
		printf( "%d位%d点", i + 1, ((UserData*)Save::GetData())->m_ranking[i]);
		a_top += 100;
		a_bottom += 100;
	
	}*/

}