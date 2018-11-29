//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Objstair.h"

//使用するネームスペース
using namespace GameL;

CObjstair::CObjstair(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjstair::Init()
{

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px+20, m_py+20, 10, 10, ELEMENT_FIELD, OBJ_STAIR, 1);
}

//アクション
void CObjstair::Action()
{
	//Scene::SetScene(new CScenefloor2());


	//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + 20 + map1->GetScrollx(), m_py + 20 + map1->GetScrolly());
}
//ドロー
void CObjstair::Draw()
{
	//描画カラー情報　R=RED　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f,};

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

				//ブロック情報を持ってくる
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//切り取り位置の設定
	src.m_top = 0.0f;	 //微調整-1
	src.m_left = 94.0f;
	src.m_right = 141.0f;
	src.m_bottom = 47.0f;//微調整-3

	//表示位置の設定
	dst.m_top = 0.0f + m_py + map1->GetScrolly();
	dst.m_left = 0.0f + m_px + map1->GetScrollx();
	dst.m_right = 50.0f + m_px + map1->GetScrollx();
	dst.m_bottom = 50.0f + m_py + map1->GetScrolly();

	Draw::Draw(1, &src, &dst, c, 0.0f);
}