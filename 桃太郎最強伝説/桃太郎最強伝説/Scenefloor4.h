#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CScenefloor4 :public CScene
{
public:
	CScenefloor4();
	~CScenefloor4();
	void InitScene();//初期化メソッド
	void Scene();	//実行中メソッド
private:
};