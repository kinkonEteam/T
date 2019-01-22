//�g�p����w�b�_�[�t�@�C��
#include "GameHead.h"
#include "CObjSword.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSword::CObjSword(float x, float y, int pos)//�n����邾���̕ϐ�
{						//�n���ꂽ�f�[�^��Draw�Ŏg���郁���o�ϐ��ɑ��
	m_px = x;
	m_py = y;
	m_pos = pos;
}

//�C�j�V�����C�Y
void CObjSword::Init()
{
	m_r = 0;
	m_vr = 15;
	m_posx = 0;			//Sword�̍��W	
	m_posy = 0;

						//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_MAGIC, OBJ_SWORD, 1);
}

//�A�N�V����
void CObjSword::Action()
{
	//��l���̏����擾
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)//��l�������݂���ꍇ
	{
		//��l���̈ʒu����Ɏ擾���A���
		m_px = obj->GetX();
		m_py = obj->GetY();
	}

	//��l�������ŕ\���ʒu�̕ύX�ppy,px
	if (m_pos == 0)     //��
	{
		m_posy = 1;
	}
	else if (m_pos == 1)//��
	{
		m_posx = -1;
	}
	else if (m_pos == 2)//��
	{
		m_posx = 1;
	}
	else			  //��
	{
		m_posy = -1;
	}
	
	
	if (m_pos == 1)
		m_r += m_vr;
	else
		m_r -= m_vr;

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + (50.0f * m_posx), m_py + (50.0f * m_posy));

	if (m_vr > 0)
		m_vr -= 1;
	else {
		this->SetStatus(false);	 //�I�u�W�F�N�g�폜
		Hits::DeleteHitBox(this);//HitBox�폜
	}
}

//�h���[
void CObjSword::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu
	/*
	//�؂���ʒu�̐ݒ�
	src.m_top	= 0.0f + (32.0f*m_pos);
	src.m_left	= 0.0f + (32.0f*m_ani_frame);
	src.m_right =32.0f + (32.0f*m_ani_frame);
	src.m_bottom=32.0f + (32.0f*m_pos);
	*/
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�	
	dst.m_top	=(  0.0f + m_py) + (50.0f * m_posy);
	dst.m_left	=(  0.0f + m_px) + (50.0f * m_posx);
	dst.m_right =( 50.0f + m_px) + (50.0f * m_posx);
	dst.m_bottom=( 50.0f + m_py) + (50.0f * m_posy);
		
	//�`��
	Draw::Draw(3, &src, &dst, c, m_r);
}