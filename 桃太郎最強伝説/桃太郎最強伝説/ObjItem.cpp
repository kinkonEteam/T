//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjItem.h"
#include "GameHead.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjItem::Init()
{
	m_x = 128; //当たり判定（場所）（仮）
	m_y = 128;	//当たり判定（場所）（仮）

	srand(time(NULL));		
	m_id = rand() % 100;	//0～100


	//アイテムのヒットボックスを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 1);


}

//アクション
void CObjItem::Action()
{
	switch (m_id)
	{
	case ITEM_PEACH:
				

		break;
	case ITEM_YELLOW_PEACH:

		break;
	case ITEM_PLUM:

		break;
	case ITEM_HORN:

		break;
	case ITEM_GOLD_BULLION:

		break;
	case ITEM_SILVER_BULLION:

		break;
	case ITEM_CLUB:

		break;
	}
}

void CObjItem::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	
	//切り取り位置の設定
	src.m_top =ITEM_RESOURCE_TOP;
	src.m_left = ITEM_RESOURCE_SIZE*(m_id-ITEM_PEACH)+ITEM_LEFT_OFF_SET;
	src.m_right = src.m_left + ITEM_SIZE + ITEM_LEFT_OFF_SET;
	src.m_bottom = src.m_top + ITEM_SIZE - ITEM_TOP_OFF_SET;

	//表示位置の設定
	dst.m_top = 128.0f ;
	dst.m_left = 128.0f;
	dst.m_right = dst.m_left+ITEM_SIZE;
	dst.m_bottom = dst.m_top+ITEM_SIZE;

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);

}