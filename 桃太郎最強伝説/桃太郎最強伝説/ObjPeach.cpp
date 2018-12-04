//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"
#include"GameL\UserData.h"

#include <stdlib.h>
#include <time.h>
#include "ObjPeach.h"
#include "GameHead.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjPeach::CObjPeach(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjPeach::Init()
{
	m_x = 0.0f;
	m_y = 0.0f;

	//�A�C�e���̃q�b�g�{�b�N�X���쐬
	Hits::SetHitBox(this, m_x + 4, m_y + 6, 50, 50, ELEMENT_ITEM, OBJ_PEACH, 1);


}

//�A�N�V����
void CObjPeach::Action()
{
	//�u���b�N���������Ă���
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	if (map1 != nullptr)
		hit->SetPos(m_px + map1->GetScrollx(), m_py + map1->GetScrolly());
	if (map2 != nullptr)
		hit->SetPos(m_px + map2->GetScrollx(), m_py + map2->GetScrolly());
	if (map3 != nullptr)
		hit->SetPos(m_px + map3->GetScrollx(), m_py + map3->GetScrolly());
	if (map4 != nullptr)
		hit->SetPos(m_px + map4->GetScrollx(), m_py + map4->GetScrolly());
	if (map5 != nullptr)
		hit->SetPos(m_px + map5->GetScrollx(), m_py + map5->GetScrolly());

	//��l���ƐڐG���Ă��邩�ǂ����𒲂ׂ�
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�A�C�e�������L����HitBox���폜����
	}
}

void CObjPeach::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�u���b�N���������Ă���
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	if (map1 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map1->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map1->GetScrollx();
		dst.m_right = 50.0f + m_x + m_px + map1->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map1->GetScrolly();
	}
	if (map2 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map2->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map2->GetScrollx();
		dst.m_right = 50.0f + m_x + m_px + map2->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map2->GetScrolly();
	}
	if (map3 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map3->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map3->GetScrollx();
		dst.m_right = 50.0f + m_x + m_px + map3->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map3->GetScrolly();
	}
	if (map4 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map4->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map4->GetScrollx();
		dst.m_right = 50.0f + m_x + m_px + map4->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map4->GetScrolly();
	}
	if (map5 != nullptr)
	{
		dst.m_top = 0.0f + m_y + m_py + map5->GetScrolly();
		dst.m_left = 0.0f + m_x + m_px + map5->GetScrollx();
		dst.m_right = 50.0f + m_x + m_px + map5->GetScrollx();
		dst.m_bottom = 50.0f + m_y + m_py + map5->GetScrolly();
	}

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);

}