#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：スコア
class CSceneScore :public CScene
{
public:
	CSceneScore() {};
	~CSceneScore() {};
	void InitScene();
	void Scene();
private:
};