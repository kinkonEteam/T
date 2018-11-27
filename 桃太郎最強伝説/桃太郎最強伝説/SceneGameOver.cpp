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



//初期化メソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GAME OVER");

	Audio::LoadAudio(2, L"GameOverBGM.wav", SOUND_TYPE::BACK_MUSIC);	//ゲームオーバー用BGM

																		//ボリュームを1.0に戻す																	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//BGMスタート
	Audio::Start(0);
}

//実行中メソッド
void CSceneGameOver::Scene()
{

}