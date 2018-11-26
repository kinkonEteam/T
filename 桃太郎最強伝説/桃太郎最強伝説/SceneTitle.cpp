//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneTitle.h"
#include"GameHead.h"



//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"桃太郎最強伝説");

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();       //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10);    //主人公オブジェクト登録
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}
