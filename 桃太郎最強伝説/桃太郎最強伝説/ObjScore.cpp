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
	
	//�Z�[�u
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
	int y_point = -10;//y��
	int rank= 0;//���ʕϐ�
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	//�`��
	Draw::Draw(18, &src, &dst, c, 0.0f);
	wchar_t atk[128];

	//�`��
	swprintf_s(atk, L"�Q�[�������L���O");
	Font::StrDraw(atk, 100, 0 , 30, c);

	swprintf_s(atk, L"�^�C�������L���O");
	Font::StrDraw(atk, 450, 0, 30, c);

	//�����ŃX�R�A��`�悵�Ă�
	for (int i = 0; i < 10; i++)
	{
		swprintf_s(atk, L" %2d��:%d�K", rank = rank + 1, ((UserData*)Save::GetData())->m_ranking[i]);//�X�R�A���Ƃ��āH
		Font::StrDraw(atk, 0, y_point = y_point + 55, 40, c);

		swprintf_s(atk, L"%2d��:Time   �F �F", rank);
		Font::StrDraw(atk, 350, y_point, 40, c);

		for (int n = 0; n < 3; n++) {
			swprintf_s(atk, L" %02d", ((UserData*)Save::GetData())->m_timerank[i][n]);
			Font::StrDraw(atk, 660 - (n * 60), y_point, 40, c);
			if (((UserData*)Save::GetData())->m_timerank[i][n] == s) {
				s = 0;
			}
			if (((UserData*)Save::GetData())->m_timerank[i][n] == m) {
				if (s == 0) {
					//swprintf_s(atk, L"New!");
					//Font::StrDraw(atk, 700, y_point, 40, c);
				}
			}
		}
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
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
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
	for (int m = 0; m < 10; m++)
		if (time[m][0] == 0 && time[m][1] == 0) {
			time[m][0] = 99, time[m][1] = 99, time[m][2] = 99;
		}

	//�l�����p�ϐ�
	int n;
	for (int a = 0; a < 3; a++) {
		//�\�[�g
		for (int i = 0; i < 9; i++) {//0~8(10�\�[�g����)
			for (int j = i + 1; j < 10; j++) {//i+1~9(i�ȏ�Ŕ�ׂ�)
				if (time[i][a] > time[j][a]) {
					for (int b = 0; b < 3; b++) {
						n = time[i][b];
						time[i][b] = time[j][b];
						time[j][b] = n;
					}//b�l�����~3
				}//if�召��r
			}//j
		}//i
	}//a

	for (int m = 0; m < 10; m++)
		if (time[m][0] == 99 && time[m][1] == 99) {
			time[m][0] = 0, time[m][1] = 0, time[m][2] = 0;
		}
}
