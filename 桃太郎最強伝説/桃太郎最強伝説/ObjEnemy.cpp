//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"
#include"GameL\UserData.h" 

#include"GameHead.h"
#include"ObjEnemy.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

CObjEnemy::CObjEnemy(float x, float y)
{
	m_px = x;	//位置
	m_py = y;
}

//イニシャライズ
void CObjEnemy::Init()
{
	enemy_move = 0;//敵移動時間
	e_time=0;//敵行動時間
	m_hp = 3;        //体力
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;//正面(0.0f) 左(1.0f) 右(2.0f) 背面(3.0f)

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする
	
	m_speed_power = 1.5f;//通常速度
	m_ani_max_time = 5;	//アニメーション間隔幅

	m_movey = true; //true=背面　false=正面
	m_movex = true;	//true=右　false=左

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_key_f = false;		//無敵時間行動制御
	m_t = false;

	knock = false;
	//m_do_f=false;//敵攻撃フラグ

	m_ftime = 0;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 50,50, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//アクション
void CObjEnemy::Action()
{
	m_ftime++;

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
		m_vy = 1;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	if (m_movey == false)
	{
		m_vy = -1;
		m_posture = 3.0f;
		m_ani_time += 1;
	}
	if (m_movex == true)
	{
		m_vx = 1;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	if (m_movex == false)
	{
		m_vx = -1;
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

	//ブロックタイプ検知用の変数がないためのダミー
	int d;
	//ブロックとの当たり判定
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	if (map1 != nullptr)
	{
		map1->Map1Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
	if (map2 != nullptr)
	{
		map2->Map2Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
	if (map3 != nullptr)
	{
		map3->Map3Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
	if (map4 != nullptr)
	{
		map4->Map4Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
	if (map5 != nullptr)
	{
		map5->Map5Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}

	/*//敵が動く時間＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿
	
	enemy_move++;//足し続ける

	//敵移動時間が250で割り切れる場合m_do_fをtrueにする
	if (enemy_move % 250 == 0)
		m_do_f = true;
	
	//e_timeの初期化
	if (enemy_move > 500)
	enemy_move = 0;
	
	//＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿
	*/
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();



	//UtilityModuleのチェック関数に場所と領域を渡し、領域外か判定
	bool check;
	if (map1 != nullptr)
	{
		check = CheckWindow(m_px + map1->GetScrollx(), m_py + map1->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}
	if (map2 != nullptr)
	{
		check = CheckWindow(m_px + map2->GetScrollx(), m_py + map2->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}
	if (map3 != nullptr)
	{
		check = CheckWindow(m_px + map3->GetScrollx(), m_py + map3->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}
	if (map4 != nullptr)
	{
		check = CheckWindow(m_px + map4->GetScrollx(), m_py + map4->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}
	if (map5 != nullptr)
	{
		check = CheckWindow(m_px + map5->GetScrollx(), m_py + map5->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}

	CObjText* text = (CObjText*)Objs::GetObj(OBJ_TEXT);

	if (check == true && text == nullptr && m_ftime >= 100)
	{
		//主人公機が存在する場合、誘導角度の計算する
		if (hero != nullptr)
		{

			float x;
			float y;

			if (map1 != nullptr)
			{
				x = 400 - (m_px + map1->GetScrollx());
				y = 300 - (m_py + map1->GetScrolly());
			}
			if (map2 != nullptr)
			{
				x = 400 - (m_px + map2->GetScrollx());
				y = 300 - (m_py + map2->GetScrolly());
			}
			if (map3 != nullptr)
			{
				x = 400 - (m_px + map3->GetScrollx());
				y = 300 - (m_py + map3->GetScrolly());
			}
			if (map4 != nullptr)
			{
				x = 400 - (m_px + map4->GetScrollx());
				y = 300 - (m_py + map4->GetScrolly());
			}
			if (map5 != nullptr)
			{
				x = 400 - (m_px + map5->GetScrollx());
				y = 300 - (m_py + map5->GetScrolly());
			}

			float ar = GetAtan2Angle(x, y);

			//敵の現在の向いている角度を取る
			float br = GetAtan2Angle(m_vx, m_vy);

			//角度で上下左右を判定
			if ((ar < 45 && ar>0) || ar > 315)
			{
				//右
				m_posture = 1.0f;
				m_ani_time += 1;
			}

			if (ar > 45 && ar < 135)
			{
				//上
				m_posture = 0.0f;
				m_ani_time += 1;
			}
			if (ar > 135 && ar < 225)
			{
				//左
				m_posture = 2.0f;
				m_ani_time += 1;
			}
			if (ar > 225 && ar < 315)
			{
				//下
				m_posture = 3.0f;
				m_ani_time += 1;

			}

			//主人公機と敵角度があんまりにもかけ離れたら
			m_vx = cos(3.14 / 180 * ar) * 2.2;
			m_vy = sin(3.14 / 180 * ar) * 2.2;


		}
	}
	else
	{
		m_vy = 0;
	}

	//イベント中は動きを止める
	CObjTalk* talk = (CObjTalk*)Objs::GetObj(OBJ_TALK);
	if (talk != nullptr)
	{
		m_vx = 0;
		m_vy = 0;
	}


	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	if (map1 != nullptr)
		hit->SetPos(m_px + map1->GetScrollx(), m_py + map1->GetScrolly());
	if (map2 != nullptr)
		hit->SetPos(m_px + map2->GetScrollx(), m_py + map2->GetScrolly());
	if (map3 != nullptr)
		hit->SetPos(m_px + map3->GetScrollx(), m_py + map3->GetScrolly());
	if (map4 != nullptr)
		hit->SetPos(m_px + map4->GetScrollx(), m_py + map4->GetScrolly());
	if (map5 != nullptr)
		hit->SetPos(m_px + map5->GetScrollx(), m_py + map5->GetScrolly());

	//ELEMENT_MAGICを持つオブジェクトと接触したら
	if (hit->CheckElementHit(ELEMENT_MAGIC) == true)
	{
		//敵が主人公とどの角度で当たっているかを確認
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

	/*//敵攻撃
	if (m_do_f == true)
	{

		e_time++;//足し続ける

		//e_timeが40以上なら入り続ける
		if (e_time >= 50)
		{
			m_vx *= 3;
			m_vy *= 3;
		//e_timeが60ならm_do_fをfalseに、e_timeを初期化する
		if (e_time == 60)
		{
		m_do_f = false;
		e_time = 0;
		}
		
		}
		//e_timeが40以上になるまで止まる：突進するまでの力をためるモーション的な？
		else
		{
			
		}
	}*/

	if (m_f == false)
	{
		//位置の更新
		m_px += m_vx*1.8f;
		m_py += m_vy*1.8f;
	}

	if (m_f == true)
	{
		m_time--;//無敵時間開始

		if (m_time == 10)
			m_key_f = false;

		alpha = 0.5f;
	}
	if (m_time <= 0)
	{
		m_f = false;
		hit->SetInvincibility(false);//無敵オフ
		alpha = 1.0f;
		m_time = 30;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjEnemy::Draw()
{
	int AniData[4] =
	{	1,0,2,0,	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,alpha };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//切り取り位置の設定
	src.m_top = 64.0f * m_posture;
	src.m_left = 0.0f + (AniData[m_ani_frame] * 64);
	src.m_right = 64.0f + (AniData[m_ani_frame] * 64);
	src.m_bottom = src.m_top+ 64.0f;

	if (map1 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map1->GetScrolly();
		dst.m_left = 50.0f + m_px + map1->GetScrollx();
		dst.m_right = 0.0f + m_px + map1->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map1->GetScrolly();
	}
	if (map2 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map2->GetScrolly();
		dst.m_left = 50.0f + m_px + map2->GetScrollx();
		dst.m_right = 0.0f + m_px + map2->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map2->GetScrolly();
	}
	if (map3 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map3->GetScrolly();
		dst.m_left = 50.0f + m_px + map3->GetScrollx();
		dst.m_right = 0.0f + m_px + map3->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map3->GetScrolly();
	}
	if (map4 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map4->GetScrolly();
		dst.m_left = 50.0f + m_px + map4->GetScrollx();
		dst.m_right = 0.0f + m_px + map4->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map4->GetScrolly();
	}
	if (map5 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map5->GetScrolly();
		dst.m_left = 50.0f + m_px + map5->GetScrollx();
		dst.m_right = 0.0f + m_px + map5->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map5->GetScrolly();
	}

	//描画
	Draw::Draw(5, &src, &dst, c, 0.0f);
}