#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：キジ
class CObjFlyKiji :public CObj
{
public:	    //ここで位置と向きを渡される
	CObjFlyKiji(float x, float y, int m_pos);//コンストラクタ
	~CObjFlyKiji() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

	float GetF() { return m_f; }
private:
	bool m_f = true;//攻撃制御

	int m_pos;		//主人公の向き格納
	int m_px;		//向きによる位置変更用x,y
	int m_py;

	float m_x;		//渡された位置格納
	float m_y;
	float m_vx;    //X方向の速度用変数
	float m_vy;    //Y方向の速度用変数

	/*
	int m_ani_time; //アニメーションタイム
	int m_ani_frame;//フレーム
	int m_s;		//ani_timeを徐々に加速させる変数
	*/
};