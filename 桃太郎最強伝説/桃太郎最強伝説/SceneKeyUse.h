#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームメイン
class SceneKeyUse :public CScene
{
public:
	SceneKeyUse();
	~SceneKeyUse();
	void InitScene();	//ゲームメインの初期化メソッド
	void Scene();		//ゲームメインの実行中メソッド
private:
	int m_time;
};

