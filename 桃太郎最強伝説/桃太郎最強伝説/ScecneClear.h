#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：クリア
class CSceneClear :public CScene
{
public:
	CSceneClear();
	~CSceneClear();
	void InitScene();
	void Scene();
private:
};