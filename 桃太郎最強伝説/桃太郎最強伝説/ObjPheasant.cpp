//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include "ObjPheasant.h"
#include "GameHead.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjPheasant::Init()
{
	m_x = 100; //当たり判定（場所）（仮）
	m_y = 200;	//当たり判定（場所）（仮）

				//お供のヒットボックスを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_RED, OBJ_MONKE, 1);

}

//アクション
void CObjPheasant::Action()
{

}

void CObjPheasant::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 32.0f;
	src.m_right = 64.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top = 200.0f;
	dst.m_left = 100.0f;
	dst.m_right = 32.0f + 100.0f;
	dst.m_bottom = 32.0f + 200.0f;

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);

}