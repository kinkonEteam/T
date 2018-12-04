//使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\UserData.h" 

#include"GameHead.h"
#include"ObjEnemy3.h"

//使用するネームスペース
using namespace GameL;

CObjEnemy3::CObjEnemy3(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjEnemy3::Init()
{
	m_x = 600;
	m_y = 300;

	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY3, 1);
}
//アクション
void CObjEnemy3::Action()
{

	m_vx = -1.0f;
	m_vy = 0.0f;

	float r = 0.0f;
	r = m_vx*m_vx + m_vy*m_vy;
	r = sqrt(r);
	if (r == 0.0f)
	{
		;
	}
	else
	{
		m_vx = 1.0f / r*m_vx;
		m_vy = 1.0f / r*m_vy;
	}
	m_vx *= 3.0f;
	m_vy *= 3.0f;

	m_x += m_vx;
	m_y *= m_vy;

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公の攻撃に当たると消滅
	if (hit->CheckElementHit(ELEMENT_MAGIC) == true)
	{
		this->SetStatus(false);	//自身に削除命令を出す
		Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する。

		//((UserData*)Save::GetData())->m_point += 100;
	}

}
//ドロー
void CObjEnemy3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//切り取り位置
	RECT_F dst;//表示位置

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 50.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(7, &src, &dst, c, 0.0f);
}