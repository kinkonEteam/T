#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイム
class CObjstair :public CObj
{
	public:
		CObjstair(float x, float y,int c) ;
		~CObjstair() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー

		void SetTimeFlag(bool b) { m_flag_time = b; }
	private:
		float m_px;		 //位置
		float m_py;
		int m_c;		//回数番号
		bool m_flag_time;//シーン切り替えフラグ
};