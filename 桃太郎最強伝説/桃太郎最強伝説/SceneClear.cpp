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
	Font::SetStrTex(L"ゲームクリア。");
		Font::SetStrTex(L"一つ伝説が刻まれた…");

		//クリアオブジェクト
		CObjClear*obj = new CObjClear();
		Objs::InsertObj(obj, OBJ_CLEAR, 10);

		Audio::LoadAudio(0, L"BossBGM.wav", BACK_MUSIC);

		//ボリュームを1.0に戻す
		float v = Audio::VolumeMaster(0);
		v = Audio::VolumeMaster((1.0 - v));

		Audio::Start(0);
}

//実行中メソッド
void CSceneClear::Scene()
{

}