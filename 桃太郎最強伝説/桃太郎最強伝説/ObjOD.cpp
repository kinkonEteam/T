//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjOD.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjOD::Init()
{
	m_Of = false;
}

//�A�N�V����
void CObjOD::Action()
{




	
}


//�h���[
void CObjOD::Draw()
{

	if (m_Of == true)
	{
		this->SetStatus(false);	//���g�ɍ폜���߂��o��
	}
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

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

	//�`��
	Draw::Draw(40, &src, &dst, c, 0.0f);

}
