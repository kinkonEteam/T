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
#include"SceneTitle.h"
#include"GameHead.h"

//アイテム初期化用
extern int item_list[7];

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//アイテム所持数初期化
	for (int i = 0; i < 7; i++)
	{
		item_list[i] = 0;
		
	}
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	hero->SetDATA();//主人公HPとお供データリセット関数

	//外部グラフィックを読み込み19番に登録(512×512ピクセル)
	Draw::LoadImage(L"ゲームタイトル.png", 20, TEX_SIZE_512);

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();       //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10);    //主人公オブジェクト登録

	//BGMの読み込み
	Audio::LoadAudio(0, L"タイトル.wav", BACK_MUSIC);		//タイトル用BGM

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//BGMボリュームを下げる
	float Volume = Audio::VolumeMaster(-0.95f);
	//音楽スタート
	Audio::Start(0);
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}