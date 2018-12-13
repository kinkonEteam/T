//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"ScecneClear.h"
#include"GameHead.h"

//コンストラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//初期化ソメッド
void CSceneClear::InitScene()
{

		//クリアオブジェクト
		CObjClear*obj = new CObjClear();
		Objs::InsertObj(obj, OBJ_CLEAR, 10);

		//外部グラフィックを読み込み19番に登録(512×512ピクセル)
		Draw::LoadImage(L"ゲームクリア.png", 19, TEX_SIZE_512);

		Audio::LoadAudio(1, L"エンディング.wav", BACK_MUSIC);

		Audio::Start(1);
}

//実行中メソッド
void CSceneClear::Scene()
{

}