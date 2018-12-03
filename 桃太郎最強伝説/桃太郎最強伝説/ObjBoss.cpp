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
	m_hp = 13;        //ボスの体力
	m_firetime = 0;      //値の初期化
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 10;	//アニメーション間隔幅

	m_movex = true;	//true=右　false=左
	m_movey = true; //true=背面　false=正面

	m_key_f = false;		//無敵時間行動制御
	m_t = false;

	knock = false;

	alpha = 1.0f;

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
	if (knock == true)
	{

	}

	m_vx = 0;
	m_vy = 0;

	//ブロック衝突で向き変更
	if (m_hit_up == true)
	{
		m_movey = true;
	}
	if (m_hit_down == true)
	{
		m_movey = false;
	}
	if (m_hit_left == true)
	{
		m_movex = false;
	}
	if (m_hit_right == true)
	{
		m_movex = true;
	}

	//方向
	if (m_movey == true)
	{
		m_vy = m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (m_movey == false)
	{
		m_vy = -m_speed_power;
		m_posture = 3.0f;
		m_ani_time += 1;
	}
	else if (m_movex == true)
	{
		m_vx = m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (m_movex == false)
	{
		m_vx = -m_speed_power;
		m_posture = 2.0f;
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

	m_firetime++;

	//誘導弾
	if (m_firetime % 200 == 0)
	{
		//誘導弾作成
		CObjHomingfire* obj_homing_fire = new CObjHomingfire(m_px, m_py);
		Objs::InsertObj(obj_homing_fire, OBJ_HOMING_FIRE, 10);
	}

	//m_timeの初期化
	if (m_firetime > 1000)
	{
		m_firetime = 0;
	}

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//ブロックタイプ検知用の変数がないためのダミー
	int d;
	//ブロックとの当たり判定
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);



	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + map5->GetScrollx(), m_py + map5->GetScrolly());

	//ELEMENT_MAGICを持つオブジェクトと接触したら
	if (hit->CheckElementHit(ELEMENT_MAGIC) == true)
	{
		//主人公が敵とどの角度で当たっているかを確認
		HIT_DATA**hit_data;							//当たった時の細かな情報を入れるための構造体
		hit_data = hit->SearchElementHit(ELEMENT_MAGIC);//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//攻撃の左右に当たったら
			if (hit_data[i] == nullptr)
				continue;

			float r = hit_data[i]->r;
			if ((r < 45 && r >= 0) || r > 315)
			{
				m_vx = -10.0f;//左に移動させる
			}
			if (r >= 45 && r < 135)
			{
				m_vy = 10.0f;//上に移動させる
			}
			if (r >= 135 && r < 225)
			{
				m_vx = 10.0f;//右に移動させる
			}
			if (r >= 225 && r < 315)
			{
				m_vy = -10.0f;//したに移動させる
			}
		}
		m_hp -= 1;
		m_f = true;
		m_key_f = true;
		hit->SetInvincibility(true);//無敵オン
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	if (m_f == true)
	{
		m_time--;//無敵時間開始

		if (m_time == 30)
			m_key_f = false;

		alpha = 0.5f;
	}
	if (m_time <= 0)
	{
		m_f = false;
		hit->SetInvincibility(false);//無敵オフ
		alpha = 1.0f;
		m_time = 70;
	}

	map5->Map5Hit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//主人公の攻撃が接触しているかどうか確認
	//if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	//{
	//	this->SetStatus(false);
	//	Hits::DeleteHitBox(this);
	//}

	//通常速度
	m_speed_power = 0.5f;
	m_ani_max_time = 4;

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

	}
}

//ドロー
void CObjBoss::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};

	//描画カラー情報4
	float c[4] = { 1.0f,1.0f,1.0f,alpha, };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//切り取り位置の設定
	src.m_top = 48.0f * m_posture;
	src.m_left = 0.0f + (AniData[m_ani_frame] * 45);
	src.m_right = 50.0f + (AniData[m_ani_frame] * 45);
	src.m_bottom = src.m_top + 48.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py + map5->GetScrolly();
	dst.m_left = 0.0f + m_px + map5->GetScrollx();
	dst.m_right = 64.0f + m_px + map5->GetScrollx();
	dst.m_bottom = 64.0f + m_py + map5->GetScrolly();

	//描画
	Draw::Draw(9, &src, &dst, c, 0.0f);
}

