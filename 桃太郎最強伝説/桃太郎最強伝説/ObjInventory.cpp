//GameL�Ŏg�p����w�b�_�[
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
}

void CObjInventory::Action()
{


}

void CObjInventory::Draw()
{
	if (m_Ef == true)
	{
		this->SetStatus(false);	//���g�ɍ폜���߂��o��
	}
	float c[4] = { 0.0f,1.0f,0.0f,1 };

	Font::StrDraw(L"��������", RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE, c);
	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		wchar_t str[STR_MAX];
		if (i == 0)
		{
			swprintf_s(str, L"���@�@�@%d", item_list[0]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 1)
		{
			swprintf_s(str, L"�����@�@�@%d", item_list[1]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 2)
		{
			swprintf_s(str, L"�������@�@�@%d", item_list[2]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 3)
		{
			swprintf_s(str, L"�́@�@�@%d", item_list[3]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 4)
		{
			swprintf_s(str, L"����@�@�@%d", item_list[4]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 5)
		{
			swprintf_s(str, L"���@�@�@%d", item_list[5]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
		if (i == 5)
		{
			swprintf_s(str, L"���@�@�@%d", item_list[6]);
			Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
		}
	}
}
