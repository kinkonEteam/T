#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームメイン
class CSceneSell :public CScene
{
public:
	CSceneSell();
	~CSceneSell();
	void InitScene();	//ゲームメインの初期化メソッド
	void Scene();		//ゲームメインの実行中メソッド
private:
	extern int item_list[5];
};

