#pragma once

#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjEnemy3 :public CObj
{
	public:
		CObjEnemy3(float x, float y);
		~CObjEnemy3() {};
		void Init();
		void Action();
		void Draw();
	private:
		float m_x;
		float m_y;
		float m_px;		 //ˆÊ’u
		float m_py;
		float m_vx;
		float m_vy;
}; 
