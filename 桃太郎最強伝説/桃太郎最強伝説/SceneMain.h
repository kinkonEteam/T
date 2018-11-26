#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームメイン
class CSceneMain :public CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();	//ゲームメインの初期化メソッド
		void Scene();		//ゲームメインの実行中メソッド
		void SetScroll(float s) { m_scroll = s; }
		float GetScroll() { return m_scroll; }
	private:
		int m_time;
		float m_scroll;		//左右スクロール用
};

