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



//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"桃太郎最強伝説");
	//外部グラフィックを読み込み19番に登録(512×512ピクセル)
	Draw::LoadImage(L"ゲームタイトル.png", 20, TEX_SIZE_512);

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();       //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10);    //主人公オブジェクト登録

		//BGMの読み込み
	Audio::LoadAudio(0, L"TitleBGM.wav", SOUND_TYPE::BACK_MUSIC);		//タイトル用BGM

	//BGMボリュームを0.9下げる
	float Volume = Audio::VolumeMaster(-0.9f);
	//音楽スタート
	Audio::Start(0);
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}