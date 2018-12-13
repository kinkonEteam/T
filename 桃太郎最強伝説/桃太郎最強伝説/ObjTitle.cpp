//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\UserData.h"

#include"GameHead.h"
#include"ObjTitle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	
	//�Q�[���X�R�A�̏�����
	static bool init_point = false;
	if (init_point == false)
	{
		((UserData*)Save::GetData())->m_point = 0;//�_��������������
		init_point = true;
		//�����L���O������������
		for (int i = 0; i < 16; i++)
		{
			((UserData*)Save::GetData())->m_ranking[i] = 0;
		}
		init_point = true;
	}

	m_key_flag = false;
}

//�A�N�V����
void CObjTitle::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneSummary());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

}
//�h���[
void CObjTitle::Draw()
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
