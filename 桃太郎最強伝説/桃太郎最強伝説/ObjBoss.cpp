//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjBoss.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBoss::CObjBoss(float x, float y)
{
	m_x = x;	//�ʒu
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBoss::Init()
{
	m_hp = 40;        //�{�X�̗̑�
	m_firetime = 0;      //�l�̏�����
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0.0f;

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 12;	//�A�j���[�V�����Ԋu��

	m_movex = true;	//true=�E�@false=��
	m_movey = true; //true=�w�ʁ@false=����

	m_key_f = false;		//���G���ԍs������
	m_t = false;

	knock = false;

	alpha = 1.0f;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_BOSS, 1);
}

//�A�N�V����
void CObjBoss::Action()
{
	if (knock == true)
	{

	}

	m_vx = 0;
	m_vy = 0;

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	m_firetime++;

	//�U���e
	if (m_firetime % 200 == 0)
	{
		//�U���e�쐬
		CObjHomingfire* obj_homing_fire = new CObjHomingfire(m_x, m_y);
		Objs::InsertObj(obj_homing_fire, OBJ_HOMING_FIRE, 10);
	}

	//m_time�̏�����
	if (m_firetime > 1000)
	{
		m_firetime = 0;
	}

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//���x
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;

	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//BOSS�Ǐ]
	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (hero != nullptr)
	{
		float x = 400 - (m_x + map5->GetScrollx());
		float y = 300 - (m_y + map5->GetScrolly());
		float ar = GetAtan2Angle(x, y);

		//BOSS�̌��݂̌����Ă���p�x�����
		float br = GetAtan2Angle(m_vx, m_vy);

		if (ar < 0)
		{
			ar = 360 + ar;
		}

		//�p�x�ŏ㉺���E�𔻒�
		if ((ar < 45 && ar>0) || ar > 315)
		{
			//�E
			m_vx += m_speed_power;
			m_posture = 2.0f;
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
			m_vy -= m_speed_power;
			m_posture = 1.0f;
			m_ani_time += 1;
		}
		if (ar > 225 && ar < 315)
		{
			//��
			m_vy -= m_speed_power;
			m_posture = 3.0f;
			m_ani_time += 1;

		}

		//��l���@��BOSS�p�x������܂�ɂ��������ꂽ��
		m_vx = cos(3.14 / 180 * ar);
		m_vy = sin(3.14 / 180 * ar);

		UnitVec(&m_vx, &m_vy);
	}

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + map5->GetScrollx(), m_y + map5->GetScrolly());

	//ELEMENT_MAGIC�����I�u�W�F�N�g�ƐڐG������
	if (hit->CheckElementHit(ELEMENT_MAGIC) == true)
	{
		//��l�����G�Ƃǂ̊p�x�œ������Ă��邩���m�F
		HIT_DATA**hit_data;							//�����������ׂ̍��ȏ������邽�߂̍\����
		hit_data = hit->SearchElementHit(ELEMENT_MAGIC);//hit_data�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//�U���̍��E�ɓ���������
			if (hit_data[i] == nullptr)
				continue;

			float r = hit_data[i]->r;
			if ((r < 45 && r >= 0) || r > 315)
			{
				m_vx = -10.0f;//���Ɉړ�������
			}
			if (r >= 45 && r < 135)
			{
				m_vy = 10.0f;//��Ɉړ�������
			}
			if (r >= 135 && r < 225)
			{
				m_vx = 10.0f;//�E�Ɉړ�������
			}
			if (r >= 225 && r < 315)
			{
				m_vy = -10.0f;//�����Ɉړ�������
			}
		}
		m_hp -= 1;
		m_f = true;
		m_key_f = true;
		hit->SetInvincibility(true);//���G�I��
	}

	//�ʒu�̍X�V
	m_x += m_vx;
	m_y += m_vy;

	if (m_f == true)
	{
		m_time--;//���G���ԊJ�n

		if (m_time == 30)
			m_key_f = false;

		alpha = 0.5f;
	}
	if (m_time <= 0)
	{
		m_f = false;
		hit->SetInvincibility(false);//���G�I�t
		alpha = 1.0f;
		m_time = 70;
	}

	//�u���b�N�Ƃ̓����蔻��
	map5->Map5Hit(&m_x, &m_y, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//�ʏ푬�x
	m_speed_power = 0.5f;

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		CObjMap5* map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);
		map5->Setwall(true);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

	}
}

//�h���[
void CObjBoss::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};

	//�`��J���[���4
	float c[4] = { 1.0f,1.0f,1.0f,alpha, };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//�؂���ʒu�̐ݒ�
	src.m_top = 48.0f * m_posture;
	src.m_left = 0.0f + (AniData[m_ani_frame] * 45);
	src.m_right = 50.0f + (AniData[m_ani_frame] * 45);
	src.m_bottom = src.m_top + 48.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y + map5->GetScrolly();
	dst.m_left = 0.0f + m_x + map5->GetScrollx();
	dst.m_right = 64.0f + m_x + map5->GetScrollx();
	dst.m_bottom = 64.0f + m_y + map5->GetScrolly();

	float r = 0.0f;
	//��l���@��BOSS�Ŋp�x�����
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (obj != nullptr)
	{
		float x = 375 - dst.m_top;
		float y = 275 - dst.m_left;
		r = GetAtan2Angle(x, y) + 30;

	}

	//�`��
	Draw::Draw(9, &src, &dst, c, 0.0f);
}

