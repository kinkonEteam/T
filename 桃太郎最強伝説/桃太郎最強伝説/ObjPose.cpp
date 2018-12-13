//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjPose.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjPose::Init()
{
	
	
}

//アクション
void  CObjPose::Action()
{
	Audio::LoadAudio(0, L"ButtonSE.wav", EFFECT);	//コマンドSE

	//Zを押してゲーム画面に移行する
	if (Input::GetVKey('Z') == true)
	{
		//コマンド用SEを鳴らす
		Audio::Start(0);
		Sleep(100);
		Scene::SetScene(new CScenefloor1());
	}
	else{}

	//Xを押して操作説明画面に移行する
	if (Input::GetVKey('X') == true)
	{
		//コマンド用SEを鳴らす
		Audio::Start(0);
		Sleep(100);
		Scene::SetScene(new CSceneSosasetsumei());
	}
	else{}

	//Cを押してアイテム説明画面に移行する
	if (Input::GetVKey('C') == true)
	{
		//コマンド用SEを鳴らす
		Audio::Start(0);
		Sleep(100);
		Scene::SetScene(new CScenefloor1());
	}
	else{}

	//Vを押してTitleに移行する
	if (Input::GetVKey('V') == true)
	{
		//コマンド用SEを鳴らす
		Audio::Start(0);
		Sleep(100);
		Scene::SetScene(new CSceneTitle());
	}
	else{}
	
}

//ドロー
void  CObjPose::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"ポーズメニュー", 350, 120, 45, c);
	Font::StrDraw(L"ゲームに戻る(Z)", 300, 200, 30, c);
	Font::StrDraw(L"操作説明(X)", 300, 250, 30, c);
	Font::StrDraw(L"アイテム説明(C)", 300, 300, 30, c);
	Font::StrDraw(L"タイトルに戻る(V)", 300, 350, 30, c);
}
