//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjPlum.h"
#include "GameHead.h"


//使用するネームスペース
using namespace GameL;

CObjPlum::CObjPlum(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjPlum::Init()
{
	m_x = 100.0f;
	m_y = 0.0f;

	//アイテムのヒットボックスを作成
	Hits::SetHitBox(this, m_x + 12, m_y + 9, 50, 50, ELEMENT_ITEM, OBJ_PLUM, 1);


}

//アクション
void CObjPlum::Action()
{


	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

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

	//主人公と接触しているかどうかを調べる
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//アイテムが所有するHitBoxを削除する

	}
}

void CObjPlum::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//切り取り位置の設定
	src.m_top = 60.0f;
	src.m_left = 64.0f;
	src.m_right = 96.0f;
	src.m_bottom = 96.0f;

	//表示位置の設定
	if (map1 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map1->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map1->GetScrollx();;
		dst.m_right = 50.0f + m_x + m_px + map1->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map1->GetScrolly();
	}
	if (map2 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map2->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map2->GetScrollx();;
		dst.m_right = 50.0f + m_x + m_px + map2->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map2->GetScrolly();
	}
	if (map3 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map3->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map3->GetScrollx();;
		dst.m_right = 50.0f + m_x + m_px + map3->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map3->GetScrolly();
	}
	if (map4 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map4->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map4->GetScrollx();;
		dst.m_right = 50.0f + m_x + m_px + map4->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map4->GetScrolly();
	}
	if (map5 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map5->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map5->GetScrollx();;
		dst.m_right = 50.0f + m_x + m_px + map5->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map5->GetScrolly();
	}

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);

}