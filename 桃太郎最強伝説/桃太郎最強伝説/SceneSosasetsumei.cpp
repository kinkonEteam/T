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
#include"SceneSosasetsumei.h"
#include"GameHead.h"



//初期化メソッド
void CSceneSosasetsumei::InitScene()
{
	//タイトルオブジェクト作成
	CObjSosasetsumei* obj = new CObjSosasetsumei();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_SOSASETSUMEI, 10);    //主人公オブジェクト登録

	//外部グラフィックを読み込み29番に登録(512×512ピクセル)
	Draw::LoadImage(L"操作説明ペイント.png", 30, TEX_SIZE_512);

	
}

//実行中メソッド
void CSceneSosasetsumei::Scene()
{

}