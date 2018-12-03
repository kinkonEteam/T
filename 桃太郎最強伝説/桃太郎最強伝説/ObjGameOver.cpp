//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
/*#include"GameL\UserData.h" 
#include "GameL\DrawFont.h"*/

#include"GameHead.h"
#include"ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;//キーフラグ
}

//アクション
void CObjGameOver::Action()
{
	//エンターキーを押してシーン：ゲームタイトルに移行する
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


}

//ドロー
void CObjGameOver::Draw()
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
	Draw::Draw(18, &src, &dst, c, 0.0f);
	Font::StrDraw(L"GAME OVER", 300, 250, 64, c);

	//スコアの描画
	/*float se[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"Score:%d", ((UserData*)Save::GetData())->m_point);//スコアをとって？
	Font::StrDraw(str, 630, 10, 20, se); //こちらで画面に描画する位置や文字のサイズを変える*/

}
