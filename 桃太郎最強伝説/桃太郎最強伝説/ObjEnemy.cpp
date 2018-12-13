//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"
#include"GameL\UserData.h" 

#include"GameHead.h"
#include"ObjEnemy.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjEnemy::CObjEnemy(float x, float y)
{
	m_px = x;	//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjEnemy::Init()
{
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0.0f;//����(0.0f) ��(1.0f) �E(2.0f) �w��(3.0f)

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���
	
	m_speed_power = 4.0f;//�ʏ푬�x
	m_ani_max_time = 10;	//�A�j���[�V�����Ԋu��

	m_movey = true; //true=�w�ʁ@false=����
	m_movex = true;	//true=�E�@false=��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//�A�N�V����
void CObjEnemy::Action()
{

	//�u���b�N�Փ˂Ō����ύX
	if (m_hit_up == true)
	{
		m_movey = true;
	}
	if (m_hit_down == true)
	{
		m_movey = false;
	}
	if (m_hit_left == true)
	{
		m_movex = false;
	}
	if (m_hit_right == true)
	{
		m_movex = true;
	}

	//����
	if (m_movey == true)
	{
		m_vy = m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	if (m_movey == false)
	{
		m_vy = -m_speed_power;
		m_posture = 3.0f;
		m_ani_time += 1;
	}
	if (m_movex == true)
	{
		m_vx = m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	if (m_movex == false)
	{
		m_vx = -m_speed_power;
		m_posture = 2.0f;
		m_ani_time += 1;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;
	//�u���b�N�Ƃ̓����蔻��
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	if (map1 != nullptr)
	{
		map1->Map1Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
	if (map2 != nullptr)
	{
		map2->Map2Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
	if (map3 != nullptr)
	{
		map3->Map3Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
	if (map4 != nullptr)
	{
		map4->Map4Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
	if (map5 != nullptr)
	{
		map5->Map5Hit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();



	//UtilityModule�̃`�F�b�N�֐��ɏꏊ�Ɨ̈��n���A�̈�O������
	bool check;
	if (map1 != nullptr)
	{
		check = CheckWindow(m_px + map1->GetScrollx(), m_py + map1->GetScrolly(), -50.0f, -50.0f, 850.0f, 650.0f);
	}
	if (map2 != nullptr)
	{
		check = CheckWindow(m_px + map2->GetScrollx(), m_py + map2->GetScrolly(), -50.0f, -50.0f, 850.0f, 650.0f);
	}
	if (map3 != nullptr)
	{
		check = CheckWindow(m_px + map3->GetScrollx(), m_py + map3->GetScrolly(), -50.0f, -50.0f, 850.0f, 650.0f);
	}
	if (map4 != nullptr)
	{
		check = CheckWindow(m_px + map4->GetScrollx(), m_py + map4->GetScrolly(), -50.0f, -50.0f, 850.0f, 650.0f);
	}
	if (map5 != nullptr)
	{
		check = CheckWindow(m_px + map5->GetScrollx(), m_py + map5->GetScrolly(), -50.0f, -50.0f, 850.0f, 650.0f);
	}

	if (check == true)
	{
		//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
		if (hero != nullptr)
		{

			float x;
			float y;
			float ar;

			if (map1 != nullptr)
			{
				x = 400 - (m_px + map1->GetScrollx());
				y = 300 - (m_py + map1->GetScrolly());
				ar = GetAtan2Angle(x, y);
			}
			if (map2 != nullptr)
			{
				x = 400 - (m_px + map2->GetScrollx());
				y = 300 - (m_py + map2->GetScrolly());
				ar = GetAtan2Angle(x, y);
			}
			if (map3 != nullptr)
			{
				x = 400 - (m_px + map3->GetScrollx());
				y = 300 - (m_py + map3->GetScrolly());
				ar = GetAtan2Angle(x, y);
			}
			if (map4 != nullptr)
			{
				x = 400 - (m_px + map4->GetScrollx());
				y = 300 - (m_py + map4->GetScrolly());
				ar = GetAtan2Angle(x, y);
			}
			if (map5 != nullptr)
			{
				x = 400 - (m_px + map5->GetScrollx());
				y = 300 - (m_py + map5->GetScrolly());
				ar = GetAtan2Angle(x, y);
			}

			//�G�̌��݂̌����Ă���p�x�����
			float br = GetAtan2Angle(m_vx, m_vy);

			if (ar < 0)
			{
				ar = 360 + ar;
			}

			//�p�x�ŏ㉺���E�𔻒�
			if ((ar < 45 && ar>0) || ar > 315)
			{
				//�E
				m_vx -= m_speed_power;
				m_posture = 1.0f;
				m_ani_time += 1;
			}

			if (ar > 45 && ar < 135)
			{
				//��
				m_vy += m_speed_power;
				m_posture = 0.0f;
				m_ani_time += 1;
			}
			if (ar > 135 && ar < 225)
			{
				//��
				m_vx += m_speed_power;
				m_posture = 2.0f;
				m_ani_time += 1;
			}
			if (ar > 225 && ar < 315)
			{
				//��
				m_vy -= m_speed_power;
				m_posture = 3.0f;
				m_ani_time += 1;

			}

			//��l���@�ƓG�p�x������܂�ɂ��������ꂽ��
			m_vx = cos(3.14 / 180 * ar);
			m_vy = sin(3.14 / 180 * ar);

			UnitVec(&m_vx, &m_vy);
		}
	}
	else
	{
		m_vy = 0;
	}

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	if (map1 != nullptr)
	hit->SetPos(m_px + map1->GetScrollx(), m_py + map1->GetScrolly());
	if (map2 != nullptr)
		hit->SetPos(m_px + map2->GetScrollx(), m_py + map2->GetScrolly());
	if (map3 != nullptr)
		hit->SetPos(m_px + map3->GetScrollx(), m_py + map3->GetScrolly());
	if (map4 != nullptr)
		hit->SetPos(m_px + map4->GetScrollx(), m_py + map4->GetScrolly());
	if (map5 != nullptr)
		hit->SetPos(m_px + map5->GetScrollx(), m_py + map5->GetScrolly());

	//��l���̍U���ɓ�����Ə���
	if (hit->CheckElementHit(ELEMENT_MAGIC) == true)
	{
		this->SetStatus(false);	//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����B

		//((UserData*)Save::GetData())->m_point += 100;
	}
}

//�h���[
void CObjEnemy::Draw()
{
	int AniData[4] =
	{	1,0,2,0,	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�u���b�N���������Ă���
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//�؂���ʒu�̐ݒ�
	src.m_top = 48.0f * m_posture;
	src.m_left = 0.0f + (AniData[m_ani_frame] * 45);
	src.m_right = 50.0f + (AniData[m_ani_frame] * 45);
	src.m_bottom = src.m_top+ 48.0f;

	if (map1 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map1->GetScrolly();
		dst.m_left = 50.0f + m_px + map1->GetScrollx();
		dst.m_right = 0.0f + m_px + map1->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map1->GetScrolly();
	}
	if (map2 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map2->GetScrolly();
		dst.m_left = 50.0f + m_px + map2->GetScrollx();
		dst.m_right = 0.0f + m_px + map2->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map2->GetScrolly();
	}
	if (map3 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map3->GetScrolly();
		dst.m_left = 50.0f + m_px + map3->GetScrollx();
		dst.m_right = 0.0f + m_px + map3->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map3->GetScrolly();
	}
	if (map4 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map4->GetScrolly();
		dst.m_left = 50.0f + m_px + map4->GetScrollx();
		dst.m_right = 0.0f + m_px + map4->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map4->GetScrolly();
	}
	if (map5 != nullptr)
	{
		dst.m_top = 0.0f + m_py + map5->GetScrolly();
		dst.m_left = 50.0f + m_px + map5->GetScrollx();
		dst.m_right = 0.0f + m_px + map5->GetScrollx();
		dst.m_bottom = 50.0f + m_py + map5->GetScrolly();
	}

	//�`��
	Draw::Draw(5, &src, &dst, c, 0.0f);
}