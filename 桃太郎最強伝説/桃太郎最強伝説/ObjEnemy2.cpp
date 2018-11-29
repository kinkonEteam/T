//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEnemy2.h"

//使用するネームスペース
using namespace GameL;

CObjEnemy2::CObjEnemy2(float x, float y)
{
	m_px = x;	//位置
	m_py = y;
}

//イニシャライズ
void CObjEnemy2::Init()
{
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;//正面(0.0f) 左(1.0f) 右(2.0f) 背面(3.0f)

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 4.6f;//通常速度
	m_ani_max_time = 10;	//アニメーション間隔幅

	m_movex = true;	//true=右　false=左
	m_movey = true; //true=背面　false=正面

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//アクション
void CObjEnemy2::Action()
{

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
	if (m_movex == true)
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

	//ブロックタイプ検知用の変数がないためのダミー
	int d;
	//ブロックとの当たり判定
	CObjMap1*pb = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	pb->Map1Hit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + map1->GetScrollx(), m_py + map1->GetScrolly());

	//主人公の攻撃に当たると消滅
	if (hit->CheckElementHit(ELEMENT_MAGIC) == true)
	{
		this->SetStatus(false);	//自身に削除命令を出す
		Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する。
	}
}

//ドロー
void CObjEnemy2::Draw()
{
	int AniData[4] =
	{ 1,0,2,0, };

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//切り取り位置の設定
	src.m_top = 48.0f * m_posture;	
	src.m_left = 0.0f + (AniData[m_ani_frame] * 45);
	src.m_right = 50.0f + (AniData[m_ani_frame] * 45);
	src.m_bottom = src.m_top + 48.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py + map1->GetScrolly();
	dst.m_left = 50.0f + m_px + map1->GetScrollx();

	dst.m_right = 0.0f + m_px + map1->GetScrollx();
	dst.m_bottom = 50.0f + m_py + map1->GetScrolly();

	//描画
	Draw::Draw(6, &src, &dst, c, 0.0f);
}