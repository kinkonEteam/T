//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjPlum.h"
#include "GameHead.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjPlum::Init()
{
	m_x = 100.0f;
	m_y = 0.0f;

	//�A�C�e���̃q�b�g�{�b�N�X���쐬
	Hits::SetHitBox(this, m_x + 12, m_y + 9, 15, 15, ELEMENT_ITEM, OBJ_PLUM, 1);


}

//�A�N�V����
void CObjPlum::Action()
{


	CHitBox* hit = Hits::GetHitBox(this);

	//��l���ƐڐG���Ă��邩�ǂ����𒲂ׂ�
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�A�C�e�������L����HitBox���폜����

	}
}

void CObjPlum::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu


				//�؂���ʒu�̐ݒ�
	src.m_top = 60.0f;
	src.m_left = 64.0f;
	src.m_right = 96.0f;
	src.m_bottom = 96.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);

}