//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\UserData.h"

#include"GameHead.h"
#include"ObjTitle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	//得点の初期化
	((UserData*)Save::GetData())->m_point = 0;

	m_key_flag = false;
}
//アクション
void CObjTitle::Action()
{
	//エンターキーを押してシーン：ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneSummary());
			m_key_flag = false;
		}
		
	}
	else
	{
		m_key_flag = true;
	}

}
//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,2.5f };

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
	Draw::Draw(20, &src, &dst, c, 0.0f);

	float b[4] = { 1.0f,0.0f,0.0f,1.0f };
	Font::StrDraw(L"桃太郎最強伝説", 230, 250, 50, b);
	Font::StrDraw(L"START", 350, 350, 45, b);
}
