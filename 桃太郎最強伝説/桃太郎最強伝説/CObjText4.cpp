//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "CObjText4.h"
#include "GameHead.h"

void CObjText4::Init()
{
	m_f = true;		//�����l
	m_page = 0;

	//�O���O���t�B�b�N��ǂݍ���9�Ԃɓo�^(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);

	//�g�[�N�I�u�W�F�N�g�쐬
	CObjTalk* talk = new CObjTalk(0, 2);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(talk, OBJ_TALK, 4);		//�D��x4(��)�ɐݒ肵�o�^
											//�R�����g�̏�ɍ����摜�\��
	CObjTalk* black = new CObjTalk(1, 2);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(black, OBJ_TALK, 20);	//�D��x5(��)�ɐݒ肵�o�^
}

void CObjText4::Action()
{

	//���͔���A�������ςȂ�����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_f == true)
		{
			m_page += 1;
			m_f = false;
		}
	}
	else//�����Ă���ꍇ
		m_f = true;
}

void CObjText4::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//���O��ENTER�L�[	 (X), (y),(size),color
	Font::StrDraw(L"�����Y", 77, 390, 25, c);
	Font::StrDraw(L"�A�N�V�����L�[�E�E�E", 625, 560, 15, c);

	if (m_page == 0) {						//1�y�[�W
		Font::StrDraw(L"�ǂ����炩�L�W�̖���������", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 1) {					//2�y�[�W
		Font::StrDraw(L"���т��񂲂�������΂��Ƃ��ɂȂ��Ă���邾�낤��", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else
		this->SetStatus(false);			//�I�u�W�F�N�g�폜
}