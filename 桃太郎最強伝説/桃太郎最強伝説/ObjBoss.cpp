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
	m_px = x;	//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjBoss::Init()
{
	m_hp = 13;        //�{�X�̗̑�
	m_time = 0;      //�l�̏�����
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;//�E����0.0f�@������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;	//�A�j���[�V�����Ԋu��

	m_move = true;	//true=�E�@false=��

					//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_BOSS, 1);
}

//�A�N�V����
void CObjBoss::Action()
{
	m_time++;

	//�U���e
	if (m_time % 200 == 0)
	{
		//�U���e�쐬
		CObjHomingfire* obj_homing_fire = new CObjHomingfire(m_vx, m_vy);
		Objs::InsertObj(obj_homing_fire, OBJ_HOMING_FIRE, 1);
	}

	//m_time�̏�����
	if (m_time > 1000)
	{
		m_time = 0;
	}

	//�ړ�����
	m_vx = -1.0f;
	m_vy = 0.0f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//���x
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//�ړ��x�N�g�����W�ɉ��Z
	m_vx += m_vx;
	m_vy += m_vy;

	//HitBox�̓��e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_vx, m_vy);

	//��l���̍U�����ڐG���Ă��邩�ǂ����m�F
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//����
	if (m_py > 1000.0f)
	{
		;
	}

	//�ʏ푬�x
	m_speed_power = 0.5f;
	m_ani_max_time = 4;

	//�u���b�N�Փ˂Ŗ����ύX
	if (m_hit_left == true)
	{
		m_move = true;
	}
	if (m_hit_right == true)
	{
		m_move = false;
	}

	//����
	if (m_move == false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (m_move == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
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

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//���łŃV�[�����Q�[���N���A�Ɉڍs
		Scene::SetScene(new CSceneClear());

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
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 64.0f;

	//�`��
	Draw::Draw(9, &src, &dst, c, 0.0f);
}

