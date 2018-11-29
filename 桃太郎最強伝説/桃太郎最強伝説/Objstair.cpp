//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Objstair.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjstair::CObjstair(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjstair::Init()
{

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px+20, m_py+20, 10, 10, ELEMENT_FIELD, OBJ_STAIR, 1);
}

//�A�N�V����
void CObjstair::Action()
{
	//Scene::SetScene(new CScenefloor2());


	//�u���b�N���������Ă���
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + 20 + map1->GetScrollx(), m_py + 20 + map1->GetScrolly());
}
//�h���[
void CObjstair::Draw()
{
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f,};

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

				//�u���b�N���������Ă���
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;	 //������-1
	src.m_left = 94.0f;
	src.m_right = 141.0f;
	src.m_bottom = 47.0f;//������-3

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py + map1->GetScrolly();
	dst.m_left = 0.0f + m_px + map1->GetScrollx();
	dst.m_right = 50.0f + m_px + map1->GetScrollx();
	dst.m_bottom = 50.0f + m_py + map1->GetScrolly();

	Draw::Draw(1, &src, &dst, c, 0.0f);
}