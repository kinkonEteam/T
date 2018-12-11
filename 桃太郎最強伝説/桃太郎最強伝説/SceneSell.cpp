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
	//外部グラフィックを読み込み29番に登録(512×512ピクセル)
	Draw::LoadImage(L".png", 29, TEX_SIZE_512);
}

//デストラクタ
CSceneSell::~CSceneSell()
{

}

//ゲームメイン初期化メソッド
void CSceneSell::InitScene()
{
	
}

//ゲームメイン実行中メソッド
void CSceneSell::Scene()
{

}