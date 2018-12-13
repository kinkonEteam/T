//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

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
	//Zを押してゲーム画面に移行する
	if (Input::GetVKey('Z') == true)
	{
		Scene::SetScene(new CScenefloor1());
	}
	else{}

	//Xを押して操作説明画面に移行する
	if (Input::GetVKey('X') == true)
	{
		Scene::SetScene(new CSceneSosasetsumei());
	}
	else{}

	//Cを押してアイテム説明画面に移行する
	if (Input::GetVKey('C') == true)
	{
		Scene::SetScene(new CSceneItemsetsumei());
	}
	else{}

	//Vを押してTitleに移行する
	if (Input::GetVKey('V') == true)
	{
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
