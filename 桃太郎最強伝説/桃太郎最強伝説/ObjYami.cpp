//�g�p����w�b�_�[�t�@�C��
//#include"GameL\DrawFont.h"
//#include"GameL\WinInputs.h"

#include"GameHead.h"
#include"ObjYami.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void ObjYami::Init()
{

}

//�A�N�V����
void ObjYami::Action()
{

}

void ObjYami::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	if (m_num == 1) { m_num = 15; }
	else if (m_num == 2) { m_num = 16; }
	else if (m_num == 3) { m_num = 17; }
	else { ; }

	//�`��
	Draw::Draw(m_num, &src, &dst, c, 0.0f);

}