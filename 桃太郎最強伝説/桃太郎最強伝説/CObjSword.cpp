//使用するヘッダーファイル
#include "GameHead.h"
#include "CObjSword.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjSword::CObjSword(float x, float y, int pos)//渡されるだけの変数
{						//渡されたデータをDrawで使えるメンバ変数に代入
	m_px = x;
	m_py = y;
	m_pos = pos;
	m_f = true;//加速時true
}

//イニシャライズ
void CObjSword::Init()
{
	m_r = 0;
	m_vr = 0;
	m_posx = 0;			//Swordの座標	
	m_posy = 0;

	//主人公向きで表示位置の変更用py,pxと剣画像の初期角度設定
	if (m_pos == 0)     //↓
	{
		m_posy = 0.5;
		m_r = -30;//剣初期角度
	}
	else if (m_pos == 1)//←
	{
		m_posx = -0.4;
		m_posy = 0.2;
		m_r = -40;
	}
	else if (m_pos == 2)//→
	{
		m_posx = 0.4;
		m_posy = 0.2;
		m_r = 40;
	}
	else			  //↑
	{
		m_posy = -0.5;
		m_r = 130;
	}

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人公の情報を取得
	if (obj != nullptr)//主人公が存在する場合
	{
		//主人公の位置を取得し、代入
		m_px = obj->GetX();
		m_py = obj->GetY();
	}

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_MAGIC, OBJ_SWORD, 1);
}

//アクション
void CObjSword::Action()
{
	
	
	
	if (m_pos == 1)//←の時だけ逆回転
		m_r += m_vr;
	else
		m_r -= m_vr;

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + (50.0f * m_posx), m_py + (50.0f * m_posy));

	if (m_vr < 30 && m_f == true)//30より小さく、フラグがtrue
		m_vr += 12.0f;			//加速
	else
		m_f = false;

	if (m_vr > 0 && m_f == false)//0より大きく、フラグがfalse
		m_vr -= 5.0f;			//減速
	else if (m_vr <= 0 && m_f == false) {
		this->SetStatus(false);	 //オブジェクト削除
		Hits::DeleteHitBox(this);//HitBox削除
	}
}

//ドロー
void CObjSword::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置
	/*
	//切り取り位置の設定
	src.m_top	= 0.0f + (32.0f*m_pos);
	src.m_left	= 0.0f + (32.0f*m_ani_frame);
	src.m_right =32.0f + (32.0f*m_ani_frame);
	src.m_bottom=32.0f + (32.0f*m_pos);
	*/
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top	=(  0.0f + m_py) + (50.0f * m_posy);
	dst.m_left	=(  0.0f + m_px) + (50.0f * m_posx);
	dst.m_right =( 50.0f + m_px) + (50.0f * m_posx);
	dst.m_bottom=( 50.0f + m_py) + (50.0f * m_posy);
		
	//描画
	Draw::Draw(3, &src, &dst, c, m_r);
}