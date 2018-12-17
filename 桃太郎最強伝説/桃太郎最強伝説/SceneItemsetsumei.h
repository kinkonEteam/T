#pragma once
//使用するヘッダー
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CSceneItemsetsumei : public CScene
{
public:
	CSceneItemsetsumei() {};
	~CSceneItemsetsumei() {};
	void InitScene(); //操作説明の初期化メソッド
	void Scene();     //操作説明の実行中メソッド
private:


};


