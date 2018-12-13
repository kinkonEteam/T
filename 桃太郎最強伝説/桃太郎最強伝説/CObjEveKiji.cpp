// GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "CObjEveKiji.h"


void CObjEveKiji::Init()
{
	m_f = true;		//�����l
	m_page = 0;

	//�O���O���t�B�b�N��ǂݍ���9�Ԃɓo�^(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);
	//�O���O���t�B�b�N��ǂݍ���4�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"kiji.png", 20, TEX_SIZE_1024);

	//�g�[�N�I�u�W�F�N�g�쐬
	CObjTalk* talk = new CObjTalk(0, 4);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(talk, OBJ_TALK, 4);		//�D��x4(��)�ɐݒ肵�o�^
	//�R�����g�̏�ɍ����摜�\��
	CObjTalk* black = new CObjTalk(1, 4);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(black, OBJ_TALK, 10);	//�D��x5(��)�ɐݒ肵�o�^
	//�����G�\��
	CObjTalk* dog = new CObjTalk(4, 4);		//�I�u�W�F�N�g�쐬
	Objs::InsertObj(dog, OBJ_TALK, 4);		//�D��x5(��)�ɐݒ肵�o�^
}

void CObjEveKiji::Action()
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

void CObjEveKiji::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//���O��ENTER�L�[	 (X), (y),(size),color
	Font::StrDraw(L"�L�W", 35, 390, 25, c);
	Font::StrDraw(L"�A�N�V�����L�[�E�E�E", 625, 560, 15, c);

	if (m_page == 0) {						//1�y�[�W
		Font::StrDraw(L"�u�����Y���񓍑��Y����I�����ɂ����L�r�c�q�A", 50, 440, 30, c);
		Font::StrDraw(L"�ЂƂ��ɂ��������ȁB������΋S�ގ��ɋ��͂���", 50, 480, 30, c);
		Font::StrDraw(L"���������܂��傤�v", 50, 520, 30, c);
	}
	else if (m_page == 1) {					//2�y�[�W
		Font::StrDraw(L"�L�r�c�q���������B", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 2) {					//3�y�[�W
		Font::StrDraw(L"�u���肪�Ƃ��������܂��B�ォ��̉���͂��܂�����", 50, 440, 30, c);
		Font::StrDraw(L"�@�������v", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 3) {					//3�y�[�W
		Font::StrDraw(L"�L�W�����ԂɂȂ����I�������U�����\�ɂȂ����I", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else {
		CObjPheasant*kiji = (CObjPheasant*)Objs::GetObj(OBJ_PHEASANT);
		kiji->Setdf(true);				//�I�u�W�F�N�g�폜�t���O
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		hero->SetYAMI(false);			//false�ňÈōX�V
		this->SetStatus(false);			//�I�u�W�F�N�g�폜
	}
}