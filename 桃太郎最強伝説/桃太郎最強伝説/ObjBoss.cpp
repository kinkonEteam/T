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
	m_x = x;	//位置
	m_y = y;
}

//イニシャライズ
void CObjBoss::Init()
{
	m_hp = 40;        //ボスの体力
	m_firetime = 0;      //値の初期化
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 12;	//アニメーション間隔幅

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
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_BOSS, 1);
}

//アクション
void CObjBoss::Action()
{
	if (knock == true)
	{

	}

	m_vx = 0;
	m_vy = 0;

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
		CObjHomingfire* obj_homing_fire = new CObjHomingfire(m_x, m_y);
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

	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//BOSS追従
	//主人公機が存在する場合、誘導角度の計算する
	if (hero != nullptr)
	{
		float x = 400 - (m_x + map5->GetScrollx());
		float y = 300 - (m_y + map5->GetScrolly());
		float ar = GetAtan2Angle(x, y);

		//BOSSの現在の向いている角度を取る
		float br = GetAtan2Angle(m_vx, m_vy);

		if (ar < 0)
		{
			ar = 360 + ar;
		}

		//角度で上下左右を判定
		if ((ar < 45 && ar>0) || ar > 315)
		{
			//右
			m_vx += m_speed_power;
			m_posture = 2.0f;
			m_ani_time += 1;
		}

		if (ar > 45 && ar < 135)
		{
			//上
			m_vy += m_speed_power;
			m_posture = 0.0f;
			m_ani_time += 1;
		}
		if (ar > 135 && ar < 225)
		{
			//左
			m_vy -= m_speed_power;
			m_posture = 1.0f;
			m_ani_time += 1;
		}
		if (ar > 225 && ar < 315)
		{
			//下
			m_vy -= m_speed_power;
			m_posture = 3.0f;
			m_ani_time += 1;

		}

		//主人公機とBOSS角度があんまりにもかけ離れたら
		m_vx = cos(3.14 / 180 * ar);
		m_vy = sin(3.14 / 180 * ar);

		UnitVec(&m_vx, &m_vy);
	}

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + map5->GetScrollx(), m_y + map5->GetScrolly());

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
	m_x += m_vx;
	m_y += m_vy;

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

	//ブロックとの当たり判定
	map5->Map5Hit(&m_x, &m_y, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//通常速度
	m_speed_power = 0.5f;

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		CObjMap5* map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);
		map5->Setwall(true);
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
	dst.m_top = 0.0f + m_y + map5->GetScrolly();
	dst.m_left = 0.0f + m_x + map5->GetScrollx();
	dst.m_right = 64.0f + m_x + map5->GetScrollx();
	dst.m_bottom = 64.0f + m_y + map5->GetScrolly();

	float r = 0.0f;
	//主人公機とBOSSで角度を取る
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//主人公機が存在する場合、誘導角度の計算する
	if (obj != nullptr)
	{
		float x = 375 - dst.m_top;
		float y = 275 - dst.m_left;
		r = GetAtan2Angle(x, y) + 30;

	}

	//描画
	Draw::Draw(9, &src, &dst, c, 0.0f);
}

