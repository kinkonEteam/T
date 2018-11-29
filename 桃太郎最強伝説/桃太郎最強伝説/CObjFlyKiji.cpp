//�g�p����w�b�_�[�t�@�C��
#include "GameHead.h"
#include "CObjFlyKiji.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "UtilityModule.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjFlyKiji::CObjFlyKiji(float x, float y, int pos)//�n����邾���̕ϐ�
{						//�n���ꂽ�f�[�^��Draw�Ŏg���郁���o�ϐ��ɑ��
	m_x = x;
	m_y = y;
	m_pos = pos;
}

//�C�j�V�����C�Y
void CObjFlyKiji::Init()
{
	m_px = 0;			//Kiji�̍��W	
	m_py = 0;
	m_vx = 0;    //X�����̑��x�p�ϐ�
	m_vy = 0;    //Y�����̑��x�p�ϐ�
	
	m_ani_time = 0;		//�A�j���[�V�����^�C��
	m_ani_frame = 0;	//�t���[��
	m_s = 1;			//�A�j���[�V�����ɋ}*/
	m_f = false;



	Hits::SetHitBox(this, m_x, m_y, 50, 50, ELEMENT_MAGIC, OBJ_FLYKIJI, 1);
}

//�A�N�V����
void CObjFlyKiji::Action()
{
	//��l���̏����擾
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)//��l����񂪑��݂���ꍇ
	{
		m_x = obj->GetX();
		m_y = obj->GetY();
	}

	//��l�������ŕ\���ʒu�̕ύX�ppy,px
	if (m_pos == 0)     //��
	{
		m_py = 1;
	}
	else if (m_pos == 1)//��
	{
		m_px = -1;
	}
	else if (m_pos == 2)//��
	{
		m_px = 1;
	}
	else			  //��
	{
		m_py = -1;
	}

	m_vx += m_px;	//�v���C���[�̌������ƒ���1���x�N�g���ɑ��
	m_x += m_vx * 5.0f;	//�x�N�g���������āA�����𒲐�

	m_vy += m_py;
	m_y += m_vy * 5.0f;

	
	m_ani_time += 1;			//�폜�����܂ŏ�ɑ���������
	if (m_ani_time > 5)		//�A�j���[�V��������Ԋu(�������ŃA�j���[�V�������x�ύX�o����)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
		
	}

	if (m_ani_frame==8)
	{
		m_ani_frame = 0;
	}


	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + (50.0f * m_px), m_y + (50.0f * m_py));

	//ELEMENT_ENEMY�����I�u�W�F�N�g�ƐڐG������
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);  //���g���폜
		Hits::DeleteHitBox(this);//HitBox���폜
	}

	//UtilityModule�̃`�F�b�N�֐��ɏꏊ�Ɨ̈��n���A�̈�O������
	bool check = CheckWindow(m_x, m_y, 0.0f, 0.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);  //���g���폜
		Hits::DeleteHitBox(this);//HitBox���폜
	}
}

//�h���[

void CObjFlyKiji::Draw()
{
	int aniData[8]=
	{
		0,1,2,3,4,5,6,7,
	};

	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top   =  0.0f;
	src.m_left  = 96.0f + (32.0f * m_px*m_px);
	src.m_right =128.0f + (32.0f * m_px*m_px);
	src.m_bottom= 32.0f;

	//�\�� Hero�Ɠ����ʒu�Ɍ���������50.0f���炵�āA
	dst.m_top   =( 0.0f + m_y) + (50.0f * m_py) + (50.0f * (m_py + m_py * m_py) / 2);
	dst.m_left  =( 0.0f + m_x) + (50.0f * m_px) + (50.0f * (m_px + m_px * m_px) / 2);
	dst.m_right =(50.0f + m_x) + (50.0f * m_px) - (50.0f * (m_px + m_px * m_px) / 2);
	dst.m_bottom=(50.0f + m_y) + (50.0f * m_py) - (50.0f * (m_py + m_py * m_py) / 2);

	//�`��
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//�؂���ʒu�̐ݒ�@�G�t�F�N�g�p
	src.m_top = aniData[m_ani_frame]*240.0f;//��*���ӁF�E��f��0�ɂ��Ȃ����Ƃ����ꍇ�A���������Ă��O�ɂȂ�
	src.m_left = 0.0f;//��
	src.m_right = 240.0f;//�E
	src.m_bottom = 240 + aniData[m_ani_frame] * 240.0f;//��*�����F��ԍ��̐����͍ŏ��̉摜�̍ő�̕��ł���������ĈႤ���l�ɂ���

	Draw::Draw(11, &src, &dst, c, 0.0f);



}