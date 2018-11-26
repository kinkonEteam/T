//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "ObjItemEffe.h"
#include "GameHead.h"

void ObjItemEffe::Init()
{
	//�O���O���t�B�b�N��ǂݍ���8�Ԃɓo�^(512*512)
	Draw::LoadImage(L"talk.png", 8, TEX_SIZE_512);

	//�g�[�N�I�u�W�F�N�g�쐬
	CObjTalk* talk = new CObjTalk(0, 1);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(talk, OBJ_TALK, 3);//�D��x1(��)�ɐݒ肵�o�^
	//�R�����g�̏�ɍ����摜�\��
	CObjTalk* black = new CObjTalk(1, 1);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(black, OBJ_TALK, 5);//�D��x3(��)�ɐݒ肵�o�^
}

void ObjItemEffe::Action()
{
	//���͔���A�������ςȂ�����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		this->SetStatus(false);		//�I�u�W�F�N�g�폜
	}
	else { ; }//�����ĂȂ��ꍇ
}

void ObjItemEffe::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//���O��ENTER�L�[	 (X), (y),(size),color
	Font::StrDraw(L"", 35, 390, 25, c);
	Font::StrDraw(L"�A�N�V�����L�[�E�E�E", 625, 560, 15, c);

	//1��, 2����, 3������, 4��, 5���̉��ז_, 6��̉��ז_, 7���_
	if (m_item == 1) {							//��
		Font::StrDraw(L"�̗͂��P�񕜂����I", 50, 440, 30, c);
	}
	else if (m_item == 2) {						//����
		Font::StrDraw(L"�̗͂��R�񕜂����I", 50, 440, 30, c);
	}
	else if (m_item == 3) {						//������
		Font::StrDraw(L"����������ɓ��ꂽ�I", 50, 440, 30, c);
	}
	else if (m_item == 4) {						//��
		Font::StrDraw(L"�̂���ɓ��ꂽ�I", 50, 440, 30, c);
	}
	else if (m_item == 5) {						//���̉��ז_
		Font::StrDraw(L"���̉��ז_����ɓ��ꂽ�I", 50, 440, 30, c);
	}
	else if (m_item == 6) {						//��̉��ז_
		Font::StrDraw(L"��̉��ז_����ɓ��ꂽ�I", 50, 440, 30, c);
	}
	else {										//���_
		Font::StrDraw(L"���_����ɓ��ꂽ�I", 50, 440, 30, c);
		Font::StrDraw(L"�ړ����x���ቺ�����B", 50, 480, 30, c);
	}
}