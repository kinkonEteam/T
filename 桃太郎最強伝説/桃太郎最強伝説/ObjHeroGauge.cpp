//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include <stdlib.h>
#include "ObjHeroGauge.h"
#include "GameHead.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

extern int HP;				//HP

//�C�j�V�����C�Y
void CObjHeroGauge::Init()
{
	change = 6 - HP;
	ad = HP - 1;
	ac = HP + 1;
	ab = HP + 2;
}

//�A�N�V����
void CObjHeroGauge::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		gethp = obj->Gethp();
		//�̗͂�ad���ꏏ�̒l�ɂȂ����ꍇ�̂ݔ���
		if (gethp == ad)
		{
			change++;//�n�[�g��1���炷
			ad--;//�����l��1���炷
			ac--;//���p�̒l�𒲐�����
			ab--;
		}
		else if (gethp == ac)
		{
			change--;//�n�[�g��1���₷
			ac++;//�����l��1���炷
			ad++;//���p�̒l�𒲐�����
			ab++;
		}
		else if (gethp >= ab)
		{
			change-=2;//�n�[�g��1���₷
			ac+=2;//�����l��1���炷
			ad+=2;//���p�̒l�𒲐�����
			ab += 2;
		}

	}
}

void CObjHeroGauge::Draw()
{

	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 192.0f - 32.0f * change;
	src.m_bottom = 28.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right =192.0f - 32.0f * change;
	dst.m_bottom = 28.0f;


	Draw::Draw(8, &src, &dst, c, 0.0f);
}