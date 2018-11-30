//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include "ObjDog.h"
#include "GameHead.h"


//使用するネームスペース
using namespace GameL;

CObjDog::CObjDog(float x, float y)
{//オブジェ作成時に渡されたx,y座標をメンバ変数に代入
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjDog::Init()
{
	//お供のヒットボックスを作成
	Hits::SetHitBox(this, 0, 0, 50, 50, ELEMENT_RED, OBJ_DOG, 1);
}

//アクション
void CObjDog::Action()
{
	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + map1->GetScrollx(), m_py + map1->GetScrolly());
}

void CObjDog::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 31.0f;

	//表示位置の設定
	dst.m_top = m_py + map1->GetScrolly();
	dst.m_left = m_px + map1->GetScrollx();
	dst.m_right = 50.0f  + m_px + map1->GetScrollx();
	dst.m_bottom = 50.0f + m_py + map1->GetScrolly();

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);

}