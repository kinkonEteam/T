//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include <stdlib.h>
#include "ObjHeroGauge.h"
#include "GameHead.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHeroGauge::Init()
{
	change = 1;
	ad = 4;
}

//アクション
void CObjHeroGauge::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		gethp = obj->Gethp();
		//体力とadが一緒の値になった場合のみ反応
		if (gethp == ad)
		{
			change++;//ハートを1減らす
			ad--;//調整値を1ずらす
		}
	}
}

void CObjHeroGauge::Draw()
{

	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 192.0f - 32.0f * change;
	src.m_bottom = 28.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right =192.0f - 32.0f * change;
	dst.m_bottom = 28.0f;


	Draw::Draw(8, &src, &dst, c, 0.0f);
}