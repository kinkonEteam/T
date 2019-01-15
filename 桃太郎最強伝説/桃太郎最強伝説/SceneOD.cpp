//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneOD.h"
#include"GameHead.h"



//初期化メソッド
void CSceneOD::InitScene()
{
	//タイトルオブジェクト作成
	CObjOD* obj = new CObjOD();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_OD, 10);    //主人公オブジェクト登録

	//外部グラフィックを読み込み30番に登録(512×512ピクセル)
	Draw::LoadImage(L"操作説明ペイント.png", 30, TEX_SIZE_512);

	
}

//実行中メソッド
void CSceneOD::Scene()
{

}