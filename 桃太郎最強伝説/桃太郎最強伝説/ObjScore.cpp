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
extern int c, s, m;//�J�E���g�A�Z�R���h�A�~�j�b�c

//�C�j�V�����C�Y
void CObjScore::Init()
{
	
	//���_���������L���O�ŉ��ʂɓo�^
	((UserData*)Save::GetData())->m_ranking[9] = ((UserData*)Save::GetData())->m_point;

	((UserData*)Save::GetData())->m_timerank[9][0] = c;
	((UserData*)Save::GetData())->m_timerank[9][1] = s;
	((UserData*)Save::GetData())->m_timerank[9][2] = m;

	//���_���������ɕ��ѕς�����
	RankingSort(((UserData*)Save::GetData())->m_ranking);

	TimeSort(((UserData*)Save::GetData())->m_timerank);
	
	//�Z�[�u�f�[�^�H
	Save::Seve();
	
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

	swprintf_s(atk, L"�^�C�������L���O");
	Font::StrDraw(atk, 100, 0, 30, c);

	//�����ŃX�R�A��`�悵�Ă�
	for (int i = 0; i < 10;i++)
	{
		swprintf_s(atk, L" %d��:Score�E%d",rank=rank+1, ((UserData*)Save::GetData())->m_ranking[i]);//�X�R�A���Ƃ��āH
		Font::StrDraw(atk, 350, y_point=y_point+60 , 40, c);

		//swprintf_s(atk, L" %d��:Score�E%d", rank,m_ranking[i]);
		//Font::StrDraw(atk, 350, y_point, 40, c);
	}

}

//�����L���O�\�[�g���\�b�h
//����1�@int[16]:�����L���O�p�z��
//�~���Ńo�u���\�[�g���s��
void CObjScore::RankingSort(int rank[10])
{
	//�l�����p�ϐ�
	int c;

	//�o�u���\�[�g
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 11; j++)
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

void CObjScore::TimeSort(int time[10][3])
{
	//�l�����p�ϐ�
	int c;
	int rank[10];
	//		  41 +	  32 00	 +	02 00 00  (��)
	rank[9] = c + (s * 100) + (m * 1000);//�ŉ��ʂɑ��

	//�\�[�g
	for (int i = 0; i < 10; i++){//0~9(10�\�[�g����)
		for (int j = i + 1; j < 11; j++){//0~10(11��㉺�Ŕ�ׂ�)
			if (rank[i] < rank[j]){
				//c�𒇉�ɒl�̌���
				c = rank[i];
				rank[i] = rank[j];
				rank[j] = c;
			}
		}
	}

	for (int a = 0; a < 10; a++) {
		time[a][0] = rank[a] - (s * 100 + m * 10000);//s��m��������c����
		time[a][1] = rank[a] - (c       + m * 10000);//c��m��������c����
		time[a][2] = rank[a] - (c		+ s * 100  );//c��s��������c����
	}
}
