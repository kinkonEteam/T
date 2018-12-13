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

	//Dを押してポーズに移行する 
	if (Input::GetVKey('D') == true)
	{
		Scene::SetScene(new CScenePose());
	}
	else {}
}

//ドロー
void CObjSosasetsumei::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"操作説明", 300, 80, 50, c);
	
	Font::StrDraw(L"D:戻る", 250, 300, 30, c);

}
