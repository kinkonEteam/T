//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "CObjEveDog.h"
#include "GameHead.h"

void CObjEveDog::Init()
{
	m_f = true;

	//�O���O���t�B�b�N��ǂݍ���7�Ԃɓo�^(512*512)
	Draw::LoadImage(L"talk.png", 8, TEX_SIZE_512);

	//�I�u�W�F�N�g�쐬
	CObjTalk* t = new CObjTalk();
	Objs::InsertObj(t, OBJ_TALK, 1);
}

void CObjEveDog::Action()
{
	//�U���̓��͔���A�������ςȂ�����
	if (Input::GetVKey('\n') == true)
	{
		if (m_f == true)
		{
			
			

			m_f = false;
		}
	}
	else//�����Ă���ꍇ
		m_f = true;
}

void CObjEveDog::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	Font::StrDraw(L"�R�����g", 30, 410, 25, c);

	Font::StrDraw(L"a", 30, 410, 25, c);
}