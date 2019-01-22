//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjOD.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjOD::Init()
{
	m_Af = false;
}

//アクション
void CObjOD::Action()
{


	Audio::LoadAudio(0, L"ButtonSE.wav", EFFECT);	//コマンドSE

	//Dを押してポーズに移行する 
	if (Input::GetVKey('H') == true)
	{
		//コマンド用SEを鳴らす
		Audio::Start(0);
		Sleep(100);
		
	}
	else {}
	//エンターキーを押してシーン：メイン移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_f == true)
		{
			Scene::SetScene(new CScenefloor1());
			m_key_f = false;
		}
	}
	else
	{
		m_key_f = true;
	}

}


//ドロー
void CObjOD::Draw()
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
	Draw::Draw(40, &src, &dst, c, 0.0f);

	
}
