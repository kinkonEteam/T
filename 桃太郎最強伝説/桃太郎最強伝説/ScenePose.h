#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ポーズ
class CScenePose : public CScene
{
public:
	CScenePose() {};
	~CScenePose() {};
	void InitScene(); //ゲームポーズの初期化メソッド
	void Scene();     //ゲームポーズの実行中メソッド
private:
}; 
