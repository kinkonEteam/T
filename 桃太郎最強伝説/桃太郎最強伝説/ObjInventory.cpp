//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include <stdlib.h>
#include "ObjInventory.h"
#include "GameHead.h"
#include "SceneMain.h"
#include "GameL\UserData.h"

extern int item_list[7];

void CObjInventory::Init()
{
	m_Ef = false;

	Draw::LoadImage(L"item_window.png", 19, TEX_SIZE_512);
}

void CObjInventory::Action()
{


}

void CObjInventory::Draw()
{
	if (m_Ef == true)
	{
		this->SetStatus(false);	//自身に削除命令を出す
	}
	float c[4] = { 1.0f,1.0f,1.0f,1 };

	float wc[4] = { 1.0f,1.0f,1.0f,1 };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

				//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 450.0;
	src.m_bottom = 1500.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 800.0f;
	dst.m_right = 570.0f;
	dst.m_bottom = 600.0f;


	Draw::Draw(19, &src, &dst, wc, 0.0f);

	Font::StrDraw(L"もちもの", RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE, c);
	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		wchar_t str[STR_MAX];
		if (i == 0)
		{
			swprintf_s(str, L"桃　　　  %d個", item_list[0]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 1)
		{
			swprintf_s(str, L"黄桃　　　%d個", item_list[1]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 2)
		{
			swprintf_s(str, L"すもも　　%d個", item_list[2]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 3)
		{
			swprintf_s(str, L"つの　　　%d個", item_list[3]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 4)
		{
			swprintf_s(str, L"金塊　　　%d個", item_list[4]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 5)
		{
			swprintf_s(str, L"銀塊　　　%d個", item_list[5]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}

		if (i == 6)
		{
			swprintf_s(str, L"棍棒　　　%d個", item_list[6]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
	}
}
