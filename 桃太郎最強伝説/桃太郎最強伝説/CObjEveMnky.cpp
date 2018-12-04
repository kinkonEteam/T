// GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "CObjEveMnky.h"
#include "GameHead.h"

void CObjEveMnky::Init()
{
	m_f = true;		//�����l
	m_page = 0;

	//�O���O���t�B�b�N��ǂݍ���9�Ԃɓo�^(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);
	//�O���O���t�B�b�N��ǂݍ���18�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"mnky.png", 18, TEX_SIZE_1024);

	//�g�[�N�I�u�W�F�N�g�쐬
	CObjTalk* talk = new CObjTalk(0, 4);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(talk, OBJ_TALK, 4);		//�D��x4(��)�ɐݒ肵�o�^
	//�R�����g�̏�ɍ����摜�\��
	CObjTalk* black = new CObjTalk(1, 4);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(black, OBJ_TALK, 10);	//�D��x5(��)�ɐݒ肵�o�^
	//�����G�\��
	CObjTalk* mnky = new CObjTalk(2, 4);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(mnky, OBJ_TALK, 4);	//�D��x4(��)�ɐݒ肵�o�^
}


void CObjEveMnky::Action()
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

void CObjEveMnky::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//���O��ENTER�L�[	 (X), (y),(size),color
	Font::StrDraw(L"��", 55, 390, 25, c);
	Font::StrDraw(L"�A�N�V�����L�[�E�E�E", 625, 560, 15, c);

	if (m_page == 0) {						//1�y�[�W
		Font::StrDraw(L"�u�����Y���񓍑��Y����I�����ɂ����L�r�c�q�A", 50, 440, 30, c);
		Font::StrDraw(L"�ЂƂI���ɂ��������ȁI��������΋S�ގ��ɋ���", 50, 480, 30, c);
		Font::StrDraw(L"���Ă�邼�I�v", 50, 520, 30, c);
	}
	else if (m_page == 1) {					//2�y�[�W
		Font::StrDraw(L"�L�r�c�q���������B", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 2) {					//3�y�[�W
		Font::StrDraw(L"�u�T���L���[�I�I���͑������I�����čs�����Ȃ�I�v", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 3) {					//3�y�[�W
		Font::StrDraw(L"�T�������ԂɂȂ����I�ړ����x���㏸�����I", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else {
		CObjMonke*monke = (CObjMonke*)Objs::GetObj(OBJ_MONKE);
		monke->Setdf(true);
		this->SetStatus(false);		//�I�u�W�F�N�g�폜
	}
}