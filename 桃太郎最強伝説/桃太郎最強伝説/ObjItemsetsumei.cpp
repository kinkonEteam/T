//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjItemsetsumei.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjItemsetsumei::Init()
{


}

//アクション
void CObjItemsetsumei::Action()
{

	//Dを押してポーズに移行する 
	if (Input::GetVKey('D') == true)
	{
		Scene::SetScene(new CScenePose());
	}
	else {}
}

//ドロー
void CObjItemsetsumei::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	

}
