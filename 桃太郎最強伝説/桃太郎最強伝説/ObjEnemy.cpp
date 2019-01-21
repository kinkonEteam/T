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
	enemy_move = 0;//�G�ړ�����
	e_time=0;//�G�s������
	m_hp = 3;        //�̗�
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0.0f;//����(0.0f) ��(1.0f) �E(2.0f) �w��(3.0f)

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���
	
	m_speed_power = 1.5f;//�ʏ푬�x
	m_ani_max_time = 5;	//�A�j���[�V�����Ԋu��

	m_movey = true; //true=�w�ʁ@false=����
	m_movex = true;	//true=�E�@false=��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_key_f = false;		//���G���ԍs������
	m_t = false;

	knock = false;
	//m_do_f=false;//�G�U���t���O

	m_ftime = 0;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 50,50, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//�A�N�V����
void CObjEnemy::Action()
{
	m_ftime++;

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
		m_vy = 1;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	if (m_movey == false)
	{
		m_vy = -1;
		m_posture = 3.0f;
		m_ani_time += 1;
	}
	if (m_movex == true)
	{
		m_vx = 1;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	if (m_movex == false)
	{
		m_vx = -1;
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

	/*//�G���������ԁQ�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q
	
	enemy_move++;//����������

	//�G�ړ����Ԃ�250�Ŋ���؂��ꍇm_do_f��true�ɂ���
	if (enemy_move % 250 == 0)
		m_do_f = true;
	
	//e_time�̏�����
	if (enemy_move > 500)
	enemy_move = 0;
	
	//�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q
	*/
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();



	//UtilityModule�̃`�F�b�N�֐��ɏꏊ�Ɨ̈��n���A�̈�O������
	bool check;
	if (map1 != nullptr)
	{
		check = CheckWindow(m_px + map1->GetScrollx(), m_py + map1->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}
	if (map2 != nullptr)
	{
		check = CheckWindow(m_px + map2->GetScrollx(), m_py + map2->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}
	if (map3 != nullptr)
	{
		check = CheckWindow(m_px + map3->GetScrollx(), m_py + map3->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}
	if (map4 != nullptr)
	{
		check = CheckWindow(m_px + map4->GetScrollx(), m_py + map4->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}
	if (map5 != nullptr)
	{
		check = CheckWindow(m_px + map5->GetScrollx(), m_py + map5->GetScrolly(), 50.0f, 50.0f, 750.0f, 550.0f);
	}

	CObjText* text = (CObjText*)Objs::GetObj(OBJ_TEXT);

	if (check == true && text == nullptr && m_ftime >= 100)
	{
		//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
		if (hero != nullptr)
		{

			float x;
			float y;

			if (map1 != nullptr)
			{
				x = 400 - (m_px + map1->GetScrollx());
				y = 300 - (m_py + map1->GetScrolly());
			}
			if (map2 != nullptr)
			{
				x = 400 - (m_px + map2->GetScrollx());
				y = 300 - (m_py + map2->GetScrolly());
			}
			if (map3 != nullptr)
			{
				x = 400 - (m_px + map3->GetScrollx());
				y = 300 - (m_py + map3->GetScrolly());
			}
			if (map4 != nullptr)
			{
				x = 400 - (m_px + map4->GetScrollx());
				y = 300 - (m_py + map4->GetScrolly());
			}
			if (map5 != nullptr)
			{
				x = 400 - (m_px + map5->GetScrollx());
				y = 300 - (m_py + map5->GetScrolly());
			}

			float ar = GetAtan2Angle(x, y);

			//�G�̌��݂̌����Ă���p�x�����
			float br = GetAtan2Angle(m_vx, m_vy);

			//�p�x�ŏ㉺���E�𔻒�
			if ((ar < 45 && ar>0) || ar > 315)
			{
				//�E
				m_posture = 1.0f;
				m_ani_time += 1;
			}

			if (ar > 45 && ar < 135)
			{
				//��
				m_posture = 0.0f;
				m_ani_time += 1;
			}
			if (ar > 135 && ar < 225)
			{
				//��
				m_posture = 2.0f;
				m_ani_time += 1;
			}
			if (ar > 225 && ar < 315)
			{
				//��
				m_posture = 3.0f;
				m_ani_time += 1;

			}

			//��l���@�ƓG�p�x������܂�ɂ��������ꂽ��
			m_vx = cos(3.14 / 180 * ar) * 2.2;
			m_vy = sin(3.14 / 180 * ar) * 2.2;


		}
	}
	else
	{
		m_vy = 0;
	}

	//�C�x���g���͓������~�߂�
	CObjTalk* talk = (CObjTalk*)Objs::GetObj(OBJ_TALK);
	if (talk != nullptr)
	{
		m_vx = 0;
		m_vy = 0;
	}


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

	//ELEMENT_MAGIC�����I�u�W�F�N�g�ƐڐG������
	if (hit->CheckElementHit(ELEMENT_MAGIC) == true)
	{
		//�G����l���Ƃǂ̊p�x�œ������Ă��邩���m�F
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

	/*//�G�U��
	if (m_do_f == true)
	{

		e_time++;//����������

		//e_time��40�ȏ�Ȃ���葱����
		if (e_time >= 50)
		{
			m_vx *= 3;
			m_vy *= 3;
		//e_time��60�Ȃ�m_do_f��false�ɁAe_time������������
		if (e_time == 60)
		{
		m_do_f = false;
		e_time = 0;
		}
		
		}
		//e_time��40�ȏ�ɂȂ�܂Ŏ~�܂�F�ːi����܂ł̗͂����߂郂�[�V�����I�ȁH
		else
		{
			
		}
	}*/

	if (m_f == false)
	{
		//�ʒu�̍X�V
		m_px += m_vx*1.8f;
		m_py += m_vy*1.8f;
	}

	if (m_f == true)
	{
		m_time--;//���G���ԊJ�n

		if (m_time == 10)
			m_key_f = false;

		alpha = 0.5f;
	}
	if (m_time <= 0)
	{
		m_f = false;
		hit->SetInvincibility(false);//���G�I�t
		alpha = 1.0f;
		m_time = 30;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjEnemy::Draw()
{
	int AniData[4] =
	{	1,0,2,0,	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,alpha };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�u���b�N���������Ă���
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f * m_posture;
	src.m_left = 0.0f + (AniData[m_ani_frame] * 64);
	src.m_right = 64.0f + (AniData[m_ani_frame] * 64);
	src.m_bottom = src.m_top+ 64.0f;

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