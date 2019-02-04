//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\UserData.h" 

#include"GameHead.h"
#include"ObjSell.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int item_list[5];//�A�C�e�����X�g�������Ă���

//�C�j�V�����C�Y
void ObjSell::Init()
{
	m_keyf = true;		//�����l
	m_page = 0;
	m_count = 0;
	m_f = true;

	//�O���O���t�B�b�N��ǂݍ���29�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"������.png", 29, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���9�Ԃɓo�^(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);

	//�g�[�N�I�u�W�F�N�g�쐬
	CObjTalk* talk = new CObjTalk(0, 2);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(talk, OBJ_TALK, 4);		//�D��x4(��)�ɐݒ肵�o�^

	//�R�����g�̏�ɍ����摜�\��
	CObjTalk* black = new CObjTalk(1, 2);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(black, OBJ_TALK, 20);	//�D��x20(��)�ɐݒ肵�o�^
}
//�A�N�V����
void ObjSell::Action()
{
	int p = 0;
	//�����ł̓A�C�e�����ƂɃX�R�A���v�Z��'��'�ɃX�R�A�̐��l��n���Ă���
	for (int i = 0; i<7; i++)
	{
		if (i == 0)
		{
			p += item_list[i] * 100;//�����@40��
		}
		else if (i == 1)
		{
			p += item_list[i] * 1000;//�����@20��
		}
		else if (i == 2)
		{
			p += item_list[i] * 1;//�������@25��
		}
		else if (i == 3)
		{
			p += item_list[i] * 3000;//�p
		}
		else if (i == 4)
		{
			p += item_list[i] * 10000;//����@5��
		}
		else if (i == 5)
		{
			p += item_list[i] * 5000;//���@10��
		}
		else if (i == 6)
		{
			p += item_list[i] * 500;//���_
		}

	}

	//�����ŃX�R�A�����肷��
	((UserData*)Save::GetData())->m_point = p;

	//���͔���A�������ςȂ�����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_keyf == true)
		{
			m_page += 1;
			m_keyf = false;
		}
	}
	else//�����Ă���ꍇ
		m_keyf = true;
}
//�h���[
void ObjSell::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	if (m_count == 0)
	{
		//���O��ENTER�L�[	 (X), (y),(size),color
		Font::StrDraw(L"�����Y", 55, 390, 25, c);
		Font::StrDraw(L"�A�N�V�����L�[�E�E�E", 625, 560, 15, c);
	}
	else if (m_count == 110) {
		//�g�[�N�I�u�W�F�N�g�쐬
		CObjTalk* talk2 = new CObjTalk(0, 5);	//�I�u�W�F�N�g�쐬
		Objs::InsertObj(talk2, OBJ_TALK, 4);		//�D��x4(��)�ɐݒ肵�o�^
		//�R�����g�̏�ɍ����摜�\��
		CObjTalk* black2 = new CObjTalk(1, 5);	//�I�u�W�F�N�g�쐬
		Objs::InsertObj(black2, OBJ_TALK, 20);	//�D��x10(��)�ɐݒ肵�o�^
	}
	else if (m_count == 111) {
		m_f = false;
		m_page = 0;
		m_count++;
		ObjCapture* cap = new ObjCapture(29);		//29�Ԃ̉摜�\��
		Objs::InsertObj(cap, OBJ_CAPTURE, 1);		//�o�^
	}

	if (m_f == true) {
		if (m_page == 0) {						//1�y�[�W
			Font::StrDraw(L"�S��|������A���̂��܂�L���������B����", 50, 440, 30, c);
			Font::StrDraw(L"�����ςȖ��������C������B�B�B", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else if (m_page == 1) {					//2�y�[�W
			Font::StrDraw(L"�E�@�E�@�E", 50, 440, 30, c);
			Font::StrDraw(L"", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else {
			m_count++;//�g�[�N�I�u�W�F���Ō�J�E���g
		}
	}
		 /*�e�ԍ�
		0,		//����
		1,		//����
		2,		//������
		3,		//��
		4,		//����
		5,		//���
		6,		//���_
			*/
	if (m_f == false)//�������V�[��
	{
	float c[4] = { 1.0f,1.0f,1.0f,0.65f };//�����ۂ����𓧉�
	wchar_t a[128];
	
	if (0 <= m_page && m_page <= 2) {
			Font::StrDraw(L"���l", 55, 390, 25, c);
			Font::StrDraw(L"�A�N�V�����L�[�E�E�E", 625, 560, 15, c);
		}
		else {
			Font::StrDraw(L"�����Y", 55, 390, 25, c);
			Font::StrDraw(L"�A�N�V�����L�[�E�E�E", 625, 560, 15, c);
		}

		if (m_page == 0) {						//1�y�[�W
			swprintf_s(a, L"������%d��%d�K�I", item_list[0],item_list[0]*100);
			Font::StrDraw(a, 50, 440, 30, c);
			swprintf_s(a, L"������%d��%d�K�I", item_list[1], item_list[1] * 1000);
			Font::StrDraw(a, 50, 480, 30, c);
			swprintf_s(a, L"��������%d��%d�K�I", item_list[2], item_list[2] * 1);
			Font::StrDraw(a, 50, 520, 30, c);
		}
		else if (m_page == 1) {					//2�y�[�W
			swprintf_s(a, L"��%d��%d�K�I", item_list[3], item_list[3] * 3000);
			Font::StrDraw(a, 50, 440, 30, c);
			swprintf_s(a, L"����%d��%d�K�I", item_list[4], item_list[4] * 10000);
			Font::StrDraw(a, 50, 480, 30, c);
			swprintf_s(a, L"���%d��%d�K�I", item_list[5], item_list[5] * 5000);
			Font::StrDraw(a, 50, 520, 30, c);
		}
		else if (m_page == 2) {					//3�y�[�W
			swprintf_s(a, L"���_��%d��%d�K�I", item_list[6], item_list[6] * 500);
			Font::StrDraw(a, 50, 440, 30, c);
			Font::StrDraw(L"", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else if (m_page == 3)//4�y�[�W
		{
			swprintf_s(a, L"���v%d�K�I", ((UserData*)Save::GetData())->m_point);
			Font::StrDraw(a, 50, 440, 30, c);
			Font::StrDraw(L"", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else if (m_page == 4) {					//5�y�[�W
			Font::StrDraw(L"���̑��l���A�F�ɓn���Ă���邾�낤���B�B�B", 50, 440, 30, c);
			Font::StrDraw(L"", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else 
		{
			this->SetStatus(false);		//���ȍ폜
		}
	}
}