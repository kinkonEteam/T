
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
	//あらすじ用BGM
	Audio::LoadAudio(0, L"あらすじ.wav", BACK_MUSIC);		

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//BGMボリュームを下げる
	float Volume = Audio::VolumeMaster(-0.99f);

	//音楽スタート
	Audio::Start(0);

	Font::SetStrTex(L"むかしむかし、あるところに、おじいさんとおばあさんが住んでいました。");
	Font::SetStrTex(L"おじいさんは山へ芝刈りに、おばあさんは川へ洗濯に行きました");

	//あらすじオブジェクト
//	CObjSummary*obj = new CObjSummary();
//	Objs::InsertObj(obj, OBJ_SUMMARY, 10);

	//テキスト作成
	CObjSummary* summary = new CObjSummary();
	Objs::InsertObj(summary, OBJ_SUMMARY, 20);
}

//実行中メソッド
void CSceneSummary::Scene()
{

	CObjSummary* summary = (CObjSummary*)Objs::GetObj(OBJ_SUMMARY);
	if (summary == nullptr)
	{
		Scene::SetScene(new CScenefloor1());
	}
}