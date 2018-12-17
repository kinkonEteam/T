//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneItemsetsumei.h"
#include"GameHead.h"



//ゲームメイン初期化メソッド
void CSceneItemsetsumei::InitScene()
{
	//タイトルオブジェクト作成
	CObjItemsetsumei* obj = new CObjItemsetsumei(); //アイテム説明オブジェクト作成
	Objs::InsertObj(obj, OBJ_ITEMSETSUMEI, 10);    //アイテム説明登録
	
}

//ゲームメイン実行中メソッド
void CSceneItemsetsumei::Scene()
{

}