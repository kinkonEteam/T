//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjPeach.h"
#include "GameHead.h"
#include "SceneMain.h"

void CObjInventory::Init()
{
	item_list[20] = 0;

}

void CObjInventory::Action()
{



}

void CObjInventory::Draw()
{
	float c[4] = { 1,1,1,1 };

	Font::StrDraw(L"ランキング", RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE, c);
	for (int i = 0; i < 20; i++)
	{
		wchar_t str[STR_MAX];
		swprintf_s(str, L"%s", item_list);
		Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
	}
}
