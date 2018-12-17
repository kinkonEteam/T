//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"ScenePose.h"
#include"GameHead.h"



//ゲームメイン初期化メソッド
void CScenePose::InitScene()
{
	//タイトルオブジェクト作成
	CObjPose* obj = new CObjPose();       //ポーズオブジェクト作成
	Objs::InsertObj(obj, OBJ_POSE, 10);    //ポーズオブジェクト登録
}

//ゲームメイン実行中メソッド
void CScenePose::Scene()
{

}