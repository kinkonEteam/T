//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjTalk.h"
#include "GameHead.h"

void CObjTalk::Init()
{
	
}

void CObjTalk::Action()
{

}

void CObjTalk::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top  =   0.0f;
	src.m_left =   0.0f;
	src.m_right =128.0f;
	src.m_bottom= 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top   =400.0f;
	dst.m_left  = 20.0f;
	dst.m_right =780.0f;
	dst.m_bottom=580.0f;

	//�`��
	Draw::Draw(8, &src, &dst, c, 0.0f);

	Font::StrDraw(L"�R�����g", 30, 410, 25, c);
}