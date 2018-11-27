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

CObjSilverBullion::CObjSilverBullion(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjSilverBullion::Init()
{
	m_x = 250.0f;
	m_y = 0.0f;

	//�A�C�e���̃q�b�g�{�b�N�X���쐬
	Hits::SetHitBox(this, m_x + 4, m_y, 50, 50, ELEMENT_ITEM, OBJ_SILVER_BULLION, 1);


}

//�A�N�V����
void CObjSilverBullion::Action()
{

	//�u���b�N���������Ă���
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + map1->GetScrollx(), m_py + map1->GetScrolly());

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

	//�u���b�N���������Ă���
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//�؂���ʒu�̐ݒ�
	src.m_top = 164.0f;
	src.m_left = 164.0f;
	src.m_right = 188.0f;
	src.m_bottom = 188.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y + m_py + map1->GetScrolly();
	dst.m_left = 0.0f + m_x + m_px + map1->GetScrollx();;
	dst.m_right = 50.0f + m_x + m_px + map1->GetScrollx();
	dst.m_bottom = 50.0f + m_y + m_py + map1->GetScrolly();

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);

}