//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjSilverBullion.h"
#include "GameHead.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSilverBullion::Init()
{
	m_x = 250.0f;
	m_y = 0.0f;

	//�A�C�e���̃q�b�g�{�b�N�X���쐬
	Hits::SetHitBox(this, m_x + 4, m_y, 24, 28, ELEMENT_ITEM, OBJ_SILVER_BULLION, 1);


}

//�A�N�V����
void CObjSilverBullion::Action()
{


	CHitBox* hit = Hits::GetHitBox(this);

	//��l���ƐڐG���Ă��邩�ǂ����𒲂ׂ�
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�A�C�e�������L����HitBox���폜����



	}
}

void CObjSilverBullion::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu


				//�؂���ʒu�̐ݒ�
	src.m_top = 164.0f;
	src.m_left = 164.0f;
	src.m_right = 188.0f;
	src.m_bottom = 188.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);

}