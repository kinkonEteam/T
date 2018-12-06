//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjSosasetsumei.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjSosasetsumei::Init()
{


}

//アクション
void CObjSosasetsumei::Action()
{

	//Zを押してポーズに移行する
	if (Input::GetVKey('Z') == true)
	{
		Scene::SetScene(new CScenePose());
	}
	else {}
}

//ドロー
void CObjSosasetsumei::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"↑↓←→で移動だ", 300, 150, 30, c);
	Font::StrDraw(L"Aで剣攻撃だ", 300, 200, 30, c);
	Font::StrDraw(L"Sで雉攻撃だ", 300, 250, 30, c);
	Font::StrDraw(L"（雉入手後可能）", 300, 300, 30, c);
	Font::StrDraw(L"Mで戻るんじゃ", 300, 350, 30, c);

}
