//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjSell.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int item_list[7];//�A�C�e�����X�g�������Ă���

//�C�j�V�����C�Y
void ObjSell::Init()
{

}
//�A�N�V����
void ObjSell::Action()
{

}
//�h���[
void ObjSell::Draw()
{
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
	Draw::Draw(20, &src, &dst, c, 0.0f);
}