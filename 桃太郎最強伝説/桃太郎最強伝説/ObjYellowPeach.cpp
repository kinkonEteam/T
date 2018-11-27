//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjYellowPeach.h"
#include "GameHead.h"


//使用するネームスペース
using namespace GameL;

CObjYellowPeach::CObjYellowPeach(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjYellowPeach::Init()
{
	m_x = 50.0f;
	m_y = 0.0f;

	//アイテムのヒットボックスを作成
	Hits::SetHitBox(this, m_x + 4, m_y + 6, 50, 50, ELEMENT_ITEM, OBJ_YELLOW_PEACH, 1);


}

//アクション
void CObjYellowPeach::Action()
{

	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + map1->GetScrollx(), m_py + map1->GetScrolly());

	//主人公と接触しているかどうかを調べる
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//アイテムが所有するHitBoxを削除する

	}
}

void CObjYellowPeach::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置


	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//切り取り位置の設定
	src.m_top = 32.0f;
	src.m_left = 32.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y + m_py + map1->GetScrolly();
	dst.m_left = 0.0f + m_x + m_px + map1->GetScrollx();;
	dst.m_right = 50.0f + m_x + m_px + map1->GetScrollx();
	dst.m_bottom = 50.0f + m_y + m_py + map1->GetScrolly();

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);

}