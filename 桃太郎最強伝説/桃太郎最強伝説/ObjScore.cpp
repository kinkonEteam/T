//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameL\UserData.h" 
#include "GameL\DrawFont.h"

#include"GameHead.h"
#include"ObjScore.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

void CObjScore::RankingSort(int rank[16])
{
	/*//�l�����p�ϐ�
	int w;

	//�o�u���\�[�g
	for (int i = 0; i < 15; i++)
	{
		for (int j = i + 1; j < 16; j++)
		{
			if (rank[i] < rank[j])
			{
				//�l�̌���
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;
			}
		}
	}
	CObjScore*obj = new CObjScore();
	Objs::InsertObj(obj, OBJ_SCORE, 10);*/
}

//�C�j�V�����C�Y
void CObjScore::Init()
{
	/*m_key_flag = false;*/
	
}

//�A�N�V����
void CObjScore::Action()
{
	

	//�G���^�[�L�[�������ăV�[���F�^�C�g���ڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	/*
	//�Q�[�����s���Ĉ��̂�
	/*static bool init_point = false;
	if (init_point == false)
	{
	//���_�̏�����
	((UserData*)Save::GetData())->m_point = 0;

	//�����L���O������
	for (int i = 0; i < 16; i++)
	{
	((UserData*)Save::GetData())->m_point = 0;
	}
	init_point = true;
	}

	//���_���������L���O�ŉ��ʁi�`�挗�O�j�ɓo�^
	((UserData*)Save::GetData())->m_ranking[15] = ((UserData*)Save::GetData())->m_point;

	//���_���������ɕ��ёւ�������
	RankingSort(((UserData*)Save::GetData())->m_ranking);*/
}

//�h���[
void CObjScore::Draw()
{
	int a_top=0;
	int a_bottom=0;
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = a_top+0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = a_bottom+600.0f;

	//�����L���O
	Font::StrDraw(L"�����L���O",230, 250, 50,c);

	/*for (int i = 0; i <16; i++)
	{
		printf( "%d��%d�_", i + 1, ((UserData*)Save::GetData())->m_ranking[i]);
		a_top += 100;
		a_bottom += 100;
	
	}*/

}