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

	Draw::LoadImage(L"windows.png", 25, TEX_SIZE_512);
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
	//�����p
	float c[4] = { 1.0f,1.0f,1.0f,1 };
	//�g�p
	float wc[4] = { 1.0f,1.0f,1.0f,1 };
	//����������
	float bgwc[4] = { 1.0f,1.0f,1.0f,0.4 };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 450.0;
	src.m_bottom = 1500.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 800.0f;
	dst.m_right = 570.0f;
	dst.m_bottom = 500.0f;
	
	Draw::Draw(25, &src, &dst, wc, 0.0f);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 450.0f;
	src.m_right = 900.0;
	src.m_bottom = 1500.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 800.0f;
	dst.m_right = 570.0f;
	dst.m_bottom = 500.0f;

	Draw::Draw(25, &src, &dst, bgwc, 0.0f);

	Font::StrDraw(L"��������", RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE, c);
	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		wchar_t str[STR_MAX];
		switch (i)
		{
		case 0:	
				swprintf_s(str, L"���@�@�@  %d��", item_list[i]);
				Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
				break;
		case 1:
				swprintf_s(str, L"�����@�@�@%d��", item_list[i]);
				Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
				break;
		case 2:
				swprintf_s(str, L"�������@�@%d��", item_list[i]);
				Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
				break;
		case 3:
				swprintf_s(str, L"�́@�@�@%d��", item_list[i]);
				Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
				break;
		case 4:
				swprintf_s(str, L"����@�@�@%d��", item_list[i]);
				Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
				break;
		case 5:
				swprintf_s(str, L"���@�@�@%d��", item_list[i]);
				Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
				break;
		case 6:
				swprintf_s(str, L"���_�@�@�@%d��", item_list[i]);
				Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
				break;
		}
	}
}
