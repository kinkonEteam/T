#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CSceneOD : public CScene
{
public:
	CSceneOD() {};
	~CSceneOD() {};
	void InitScene(); //操作説明の初期化メソッド
	void Scene();     //操作説明の実行中メソッド
private:

}; 
