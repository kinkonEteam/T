//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjBoss.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;

CObjBoss::CObjBoss(float x, float y)
{
	m_px = x;	//位置
	m_py = y;
}

//イニシャライズ
void CObjBoss::Init()
{
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;//右向き0.0f　左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;	//アニメーション間隔幅

	m_move = true;	//true=右　false=左

					//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_BOSS, 1);
}

//アクション
void CObjBoss::Action()
{
	//落下
	if (m_py > 1000.0f)
	{
		;
	}

	//通常速度
	m_speed_power = 0.5f;
	m_ani_max_time = 4;

	//ブロック衝突で無期変更
	if (m_hit_left == true)
	{
		m_move = true;
	}
	if (m_hit_right == true)
	{
		m_move = false;
	}

	//方向
	if (m_move == false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (m_move == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//HPが0になったら破棄

}

//ドロー
void CObjBoss::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom =  50.0f;


	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 64.0f;

	//描画
	Draw::Draw(9, &src, &dst, c, 0.0f);
}

