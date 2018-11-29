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
#include"SceneGameOver.h"
#include"GameHead.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//初期化メソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GAME OVER");

	Audio::LoadAudio(0, L"GameOverBGM.wav", SOUND_TYPE::BACK_MUSIC);	//ゲームオーバー用BGM

	//ボリュームを1.0に戻す																	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//BGMスタート
	Audio::Start(0);
	Font::SetStrTex(L"GAME OVER");
	//外部グラフィックを読み込み18番に登録(512×512ピクセル)
	Draw::LoadImage(L"ゲームオーバー.png", 18, TEX_SIZE_512);
	
	//ゲームオーバーオジェクト作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);

}

//実行中メソッド
void CSceneGameOver::Scene()
{

}