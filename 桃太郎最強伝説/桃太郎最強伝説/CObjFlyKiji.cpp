//使用するヘッダーファイル
#include "GameHead.h"
#include "CObjFlyKiji.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "UtilityModule.h"


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjFlyKiji::CObjFlyKiji(float x, float y, int pos)//渡されるだけの変数
{						//渡されたデータをDrawで使えるメンバ変数に代入
	m_x = x;
	m_y = y;
	m_pos = pos;
}

//イニシャライズ
void CObjFlyKiji::Init()
{
	m_px = 0;			//Kijiの座標	
	m_py = 0;
	m_vx = 0;    //X方向の速度用変数
	m_vy = 0;    //Y方向の速度用変数
	
	m_ani_time = 0;		//アニメーションタイム
	m_ani_frame = 0;	//フレーム
	m_s = 1;			//アニメーション緩急*/
	m_f = false;



	Hits::SetHitBox(this, m_x, m_y, 50, 50, ELEMENT_MAGIC, OBJ_FLYKIJI, 1);
}

//アクション
void CObjFlyKiji::Action()
{
	//主人公の情報を取得
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)//主人公情報が存在する場合
	{
		m_x = obj->GetX();
		m_y = obj->GetY();
	}

	//主人公向きで表示位置の変更用py,px
	if (m_pos == 0)     //↓
	{
		m_py = 1;
	}
	else if (m_pos == 1)//←
	{
		m_px = -1;
	}
	else if (m_pos == 2)//→
	{
		m_px = 1;
	}
	else			  //↑
	{
		m_py = -1;
	}

	m_vx += m_px;	//プレイヤーの向き情報と長さ1をベクトルに代入
	m_x += m_vx * 5.0f;	//ベクトルをかけて、速さを調整

	m_vy += m_py;
	m_y += m_vy * 5.0f;

	
	m_ani_time += 1;			//削除されるまで常に足し続ける
	if (m_ani_time > 5)		//アニメーション動作間隔(※ここでアニメーション速度変更出来る)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
		
	}

	if (m_ani_frame==8)
	{
		m_ani_frame = 0;
	}


	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + (50.0f * m_px), m_y + (50.0f * m_py));

	//ELEMENT_ENEMYを持つオブジェクトと接触したら
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);  //自身を削除
		Hits::DeleteHitBox(this);//HitBoxを削除
	}

	//UtilityModuleのチェック関数に場所と領域を渡し、領域外か判定
	bool check = CheckWindow(m_x, m_y, 0.0f, 0.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);  //自身を削除
		Hits::DeleteHitBox(this);//HitBoxを削除
	}
}

//ドロー

void CObjFlyKiji::Draw()
{
	int aniData[8]=
	{
		0,1,2,3,4,5,6,7,
	};

	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

				//切り取り位置の設定
	src.m_top   =  0.0f;
	src.m_left  = 96.0f + (32.0f * m_px*m_px);
	src.m_right =128.0f + (32.0f * m_px*m_px);
	src.m_bottom= 32.0f;

	//表示 Heroと同じ位置に向き方向に50.0fずらして、
	dst.m_top   =( 0.0f + m_y) + (50.0f * m_py) + (50.0f * (m_py + m_py * m_py) / 2);
	dst.m_left  =( 0.0f + m_x) + (50.0f * m_px) + (50.0f * (m_px + m_px * m_px) / 2);
	dst.m_right =(50.0f + m_x) + (50.0f * m_px) - (50.0f * (m_px + m_px * m_px) / 2);
	dst.m_bottom=(50.0f + m_y) + (50.0f * m_py) - (50.0f * (m_py + m_py * m_py) / 2);

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//切り取り位置の設定　エフェクト用
	src.m_top = aniData[m_ani_frame]*240.0f;//上*注意：右のfは0にしないことした場合、何をかけても０になる
	src.m_left = 0.0f;//左
	src.m_right = 240.0f;//右
	src.m_bottom = 240 + aniData[m_ani_frame] * 240.0f;//下*説明：一番左の数字は最初の画像の最大の幅でそれをかけて違う数値にする

	Draw::Draw(11, &src, &dst, c, 0.0f);



}