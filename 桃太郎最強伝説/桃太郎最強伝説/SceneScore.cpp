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
#include"SceneScore.h"
#include"GameHead.h"

/*//コンストラクタ
CSceneScore::CSceneScore()
{

}

//デストラクタ
CSceneScore::~CSceneScore()
{

}*/

//初期化メソッド
void CSceneScore::InitScene()
{
	Font::SetStrTex(L"ゲームクリア。");
	Font::SetStrTex(L"一つ伝説が刻まれた…");

	//クリアオブジェクト


}

//ゲームメイン実行中メソッド
void CSceneScore::Scene()
{

}