//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include"GameHead.h"
#include"Objstair.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjstair::CObjstair(float x, float y,int c)
{
	m_px = x;
	m_py = y;
	m_c = c;
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
	//�u���b�N���������Ă���
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);

	if(map1 != nullptr)
		hit->SetPos(m_px + 20 + map1->GetScrollx(), m_py + 20 + map1->GetScrolly());
	if (map2 != nullptr)
		hit->SetPos(m_px + 20 + map2->GetScrollx(), m_py + 20 + map2->GetScrolly());
	if (map3 != nullptr)
		hit->SetPos(m_px + 20 + map3->GetScrollx(), m_py + 20 + map3->GetScrolly());
	if (map4 != nullptr)
		hit->SetPos(m_px + 20 + map4->GetScrollx(), m_py + 20 + map4->GetScrolly());
	if (map5 != nullptr)
		hit->SetPos(m_px + 20 + map5->GetScrollx(), m_py + 20 + map5->GetScrolly());

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		if (m_c == 1 && Input::GetVKey('A') == true)
			Scene::SetScene(new CScenefloor2());
		else if (m_c == 2 && Input::GetVKey('A') == true)
			Scene::SetScene(new CScenefloor3());
		else if(m_c == 3 && Input::GetVKey('A') == true)
			Scene::SetScene(new CScenefloor4());
		else if(m_c == 4 && Input::GetVKey('A') == true)
			Scene::SetScene(new CScenefloor5());
		else if(m_c ==5 && Input::GetVKey('A') == true)
			Scene::SetScene(new CSceneClear());

		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//��l���f�[�^�擾
		hero->SaveDATA();//��l���̃f�[�^���Z�[�u
	}
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
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;	 //������-1
	src.m_left = 94.0f;
	src.m_right = 141.0f;
	src.m_bottom = 47.0f;//������-3


	if (map1 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map1->GetScrolly();
		dst.m_left = 0.0f + m_px + map1->GetScrollx();
		dst.m_right = 50.0f + m_px + map1->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map1->GetScrolly();
	}
	if (map2 != nullptr)
	{	
		float c[4] = { 1.0f,0.5f,1.0f,1.0f, };
		dst.m_top = 0.0f + m_py + map2->GetScrolly();
		dst.m_left = 0.0f + m_px + map2->GetScrollx();
		dst.m_right = 50.0f + m_px + map2->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map2->GetScrolly();
	}
	if (map3 != nullptr)
	{
		float c[4] = { 1.0f,1.0f,0.5f,1.0f, };
		dst.m_top = 0.0f + m_py + map3->GetScrolly();
		dst.m_left = 0.0f + m_px + map3->GetScrollx();
		dst.m_right = 50.0f + m_px + map3->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map3->GetScrolly();
	}
	if (map4 != nullptr)
	{
		float c[4] = { 0.5f,0.5f,1.0f,1.0f, };
		dst.m_top = 0.0f + m_py + map4->GetScrolly();
		dst.m_left = 0.0f + m_px + map4->GetScrollx();
		dst.m_right = 50.0f + m_px + map4->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map4->GetScrolly();
	}
	if (map5 != nullptr)
	{
		float c[4] = { 1.0f,0.5f,1.0f,1.0f, };
		dst.m_top = 0.0f + m_py + map5->GetScrolly();
		dst.m_left = 0.0f + m_px + map5->GetScrollx();
		dst.m_right = 50.0f + m_px + map5->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map5->GetScrolly();
	}



	Draw::Draw(1, &src, &dst, c, 0.0f);
}