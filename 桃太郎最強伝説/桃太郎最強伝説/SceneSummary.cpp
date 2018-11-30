//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)


//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneSummary.h"
#include"GameHead.h"



//初期化ソメッド
void CSceneSummary::InitScene()
{
	Audio::LoadAudio(0, L"あらす時.wav", BACK_MUSIC);		//ダンジョン用BGM

	//音量を0.9下げる
	float Volume = Audio::VolumeMaster(0.1f);
	//音楽スタート
	Audio::Start(0);

	Font::SetStrTex(L"むかしむかし、あるところに、おじいさんとおばあさんが住んでいました。");
	Font::SetStrTex(L"おじいさんは山へ芝刈りに、おばあさんは川へ洗濯に行きました");

	//あらすじオブジェクト
	CObjSummary*obj = new CObjSummary();
	Objs::InsertObj(obj, OBJ_SUMMARY, 10);
}

//実行中メソッド
void CSceneSummary::Scene()
{

}