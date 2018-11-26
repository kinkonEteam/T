//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)


//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"ScecneClear.h"
#include"GameHead.h"

//初期化ソメッド
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"ゲームクリア。");
		Font::SetStrTex(L"一つ伝説が刻まれた…");

		//クリアオブジェクト
		CObjClear*obj = new CObjClear();
		Objs::InsertObj(obj, OBJ_CLEAR, 10);
}

//実行中メソッド
void CSceneClear::Scene()
{

}