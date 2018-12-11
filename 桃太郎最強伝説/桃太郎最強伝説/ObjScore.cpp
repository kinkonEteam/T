//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\UserData.h"
/*#include "GameL\DrawFont.h"*/

#include"GameHead.h"
#include"ObjScore.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int item_list[5];

//�C�j�V�����C�Y
void CObjScore::Init()
{
	
	//���_���������L���O�ŉ��ʂɓo�^
	((UserData*)Save::GetData())->m_ranking[15] = ((UserData*)Save::GetData())->m_point;

	//���_���������ɕ��ѕς�����
	RankingSort(((UserData*)Save::GetData())->m_ranking);

	m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjScore::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[���^�C�g���Ɉڍs����
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


}

//�h���[
void CObjScore::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	int y_point = -40;//y��
	int rank= 0;//���ʕϐ�
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	//�`��
	Draw::Draw(18, &src, &dst, c, 0.0f);
	wchar_t atk[128];

	//�`��
	swprintf_s(atk, L"�Q�[�������L���O");
	Font::StrDraw(atk, 0, 0 , 30, c);

	//�����ŃX�R�A��`�悵�Ă�
	for (int i = 0; i < 15;i++)
	{
		swprintf_s(atk, L"%d��:Score�E%d",rank=rank+1, ((UserData*)Save::GetData())->m_ranking[i]);//�X�R�A���Ƃ��āH
		Font::StrDraw(atk, 300, y_point=y_point+40 , 40, c);
	}

}

//�����L���O�\�[�g���\�b�h
//����1�@int[16]:�����L���O�p�z��
//�~���Ńo�u���\�[�g���s��
void CObjScore::RankingSort(int rank[16])
{
	//�l�����p�ϐ�
	int c;

	//�o�u���\�[�g
	for (int i = 0; i < 15; i++)
	{
		for (int j = i + 1; j < 16; j++)
		{
			if (rank[i] < rank[j])
			{
				//�l�̌���
				c = rank[i];
				rank[i] = rank[j];
				rank[j] = c;
			}
		}
	}
}