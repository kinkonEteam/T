#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：剣
class CObjSword :public CObj
{
	public:	    //ここで位置と向きを渡される
		CObjSword(float x, float y,int m_pos);//コンストラクタ
		~CObjSword() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		float m_x;		//渡された位置格納
		float m_y;
		float m_px;
		float m_py;
		int m_pos;		//主人公の向き格納
		int m_sx;		//向きによる位置変更用x,y
		int m_sy;

		int m_ani_time; //アニメーションタイム
		int m_ani_frame;//フレーム
		int m_s;		//ani_timeを徐々に加速させる変数
};