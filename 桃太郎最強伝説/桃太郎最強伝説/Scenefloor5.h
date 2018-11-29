#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CScenefloor5 :public CScene
{
public:
	CScenefloor5();
	~CScenefloor5();
	void InitScene();//初期化メソッド
	void Scene();	//実行中メソッド
	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }
private:

	float m_scroll;		//左右スクロール用
};