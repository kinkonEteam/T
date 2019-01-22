//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"
#include "GameL\SceneObjManager.h"
#include"GameL\UserData.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneSell.h"
#include "GameHead.h"

//コンストラクタ
CSceneSell::CSceneSell()
{
	
}

//デストラクタ
CSceneSell::~CSceneSell()
{

}

//ゲームメイン初期化メソッド
void CSceneSell::InitScene()
{
	ObjSell*obj = new ObjSell();//換金オブジェ
	Objs::InsertObj(obj, OBJ_SELL, 10);
}

//ゲームメイン実行中メソッド
void CSceneSell::Scene()
{
	ObjSell*sell = (ObjSell*)Objs::GetObj(OBJ_SELL);
	if (sell == nullptr)
		Scene::SetScene(new CSceneClear());
}