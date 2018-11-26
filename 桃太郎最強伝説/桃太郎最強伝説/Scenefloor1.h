#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CScenefloor1 :public CScene
{
	public:
		CScenefloor1();
		~CScenefloor1();
		void InitScene();//初期化メソッド
		void Scene();	//実行中メソッド
		void SetScroll(float s) { m_scroll = s; }
		float GetScroll() { return m_scroll; }
	private:

		float m_scroll;		//左右スクロール用
};