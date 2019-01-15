//�g�p����w�b�_�[�t�@�C��
#include <stdlib.h>
#include <time.h>
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include <Windows.h>
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjMap5.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjMap5::CObjMap5(int map[56][56])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(56 * 56));
}

void CObjMap5::Setwall(bool type)
{
	if (type == true)
		for (int i = 0; i < 56; i++)
		{
			for (int j = 0; j < 56; j++)
			{
				if (m_map[i][j] == 3)
					m_map[i][j] = 13;
			}
		}
}

//�C�j�V�����C�Y
void CObjMap5::Init()
{
	m_f = 0;

	srand(time(NULL));

//	setstair();
//	setenemy();
//	sethero();


	//�A�C�e���o��
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 5)
			{
				//�A�C�e���I�u�W�F�N�g�쐬
				CObjPeach* p = new CObjPeach(j * 50.0f, i * 50.0f);		//�I�u�W�F�N�g�쐬
				Objs::InsertObj(p, OBJ_PEACH, 2);	//�}�l�[�W���ɓo�^

			}
		}
	}

/*	//�G�o��
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 10)
			{
				//�S�I�u�W�F�N�g�쐬
				CObjEnemy* e = new CObjEnemy(j*50.0f, i*50.0f);
				Objs::InsertObj(e, OBJ_ENEMY, 2);
			}
			if (m_map[i][j] == 11)
			{
				//���S�I�u�W�F�N�g�쐬
				CObjEnemy2* e2 = new CObjEnemy2(j*50.0f, i*50.0f);
				Objs::InsertObj(e2, OBJ_ENEMY2, 2);
			}
					else if (m_map[i][j] == 12)
			{
			//�΋S�I�u�W�F�N�g�쐬
			CObjEnemy3* e3 = new CObjEnemy3(j*50.0f, i*50.0f);
			Objs::InsertObj(e3, OBJ_ENEMY3, 5);
			}
		}
	}*/

	//BOSS�o��
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 13)
			{
				//�{�X�I�u�W�F�N�g
				CObjBoss*obj_boss_enemy = new CObjBoss(j*50.0f,i*50.0f);
				Objs::InsertObj(obj_boss_enemy, OBJ_BOSS, 2); 
			}
		}
	}

	//��l���o��
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 27)
			{
				//��l���I�u�W�F�N�g�쐬
				CObjHero* obj = new CObjHero(j*50.0f, i*50.0f);//�I�u�W�F�N�g�쐬
				Objs::InsertObj(obj, OBJ_HERO, 10);//�}�l�[�W���ɓo�^

				m_scrollx = -j * 50.0f + 400;
				m_scrolly = -i * 50.0f + 300;
			}
		}
	}




}
//�A�N�V����
void CObjMap5::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//�V�[���؂�ւ�
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 4)
			{
				//�K�i�I�u�W�F�N�g�쐬
				CObjstair* s = new CObjstair(j * 50.0f, i * 50.0f,5);		//�I�u�W�F�N�g�쐬
				Objs::InsertObj(s, OBJ_STAIR, 2);	//�}�l�[�W���ɓo�^
				m_map[i][j] = 0;
			}
		}
	}
	if (m_f == 0)
	{
		//��l���̈ʒu���擾
		float hx = hero->GetX();
		float hy = hero->GetY();

		//�X�N���[��
		hero->SetX(375);
		m_scrollx -= hero->GetVX() * 4;

		hero->SetY(275);
		m_scrolly -= hero->GetVY() * 4;
	}
}
//�h���[
void CObjMap5::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,0.5f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

			   //�}�b�v�`�b�v�ɂ��block�z�u
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] >= 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*50.0f + m_scrolly;				//�}�b�v�T�C�Y,�����ʒu
				dst.m_left = j*50.0f + m_scrollx;
				dst.m_right = dst.m_left + 50.0f;
				dst.m_bottom = dst.m_top + 50.0f;
			}
			if (m_map[i][j] == 1)
			{
				//��
				BlockDraw(47.0f, 0.0f, &dst, c);
			}
			else if (m_map[i][j] == 0 || m_map[i][j] == 2 || m_map[i][j] >= 5)
			{
				//��
				BlockDraw(0.0f, 0.0f, &dst, c);
			}
			else
			{
				//��
				BlockDraw(47.0f, 0.0f, &dst, c);
			}
		}
	}
}

//BlockDrawMethod�֐�
//�����P�@float	x	:���\�[�X�؂���ʒuX
//�����Q�@float	y	:���\�[�X�؂���ʒuY
//�����R�@RECT_F* dst :�`��ʒu
//�����S�@float	c[]	:�J���[���
//�u���b�N��64*64����`��p�B���\�[�X�؂���ʒu�̂�x,y��
//�ݒ�ł���
void CObjMap5::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 47.0f;
	src.m_bottom = src.m_top + 47.0f;
	//�`��
	Draw::Draw(1, &src, dst, c, 0.0f);
}

//BlockHit�ϐ�
//�����P�@float* x			�F������s��object��X�ʒu
//�����Q�@float* y			�F������s��object��Y�ʒu
//�����R�@bool  scroll		�F������s��object�̓X�N���[���̉e���^���邩�ǂ����itrue=�^����Afalse=�^���Ȃ��j
//�����S�@bool* up			�F�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//�����T�@bool* down		�F�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//�����U�@bool*left			�F�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//�����V�@bool*right		�F�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//�����W�@float* vx			�F���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//�����X�@float* vy			�F�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l��ς��ĕԂ�
//����10�@int* bt			�F���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N50*50����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈����S�`10�ɕԂ�
void CObjMap5::Map5Hit
(
	float *x, float *y, bool scroll_on,
	bool*up, bool* down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 1 || m_map[i][j] == 3)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*50.0f;
				float by = i*50.0f;

				//�X�N���[���̉e��
				float scrollx = scroll_on ? m_scrollx : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scrollx) + 50.0f > bx) && (*x + (-scrollx) < bx + 50.0f) && (*y + (-scrolly) + 50.0f > by) && (*y + (-scrolly) < by + 50.0f))
				{
					//�㉺���E����

					//Vector�̍쐬
					float rvx = (*x + (-scrollx)) - bx;
					float rvy = (*y + (-scrolly)) - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r >= 0) || r > 315)
						{
							*right = true;//�I�u�W�F�N�g�̍��������Փ˂��Ă���
							*x = bx + 50.0f + (scrollx);//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
							*vx = 0.5f;//-VX*�����W��
						}

						if (r > 45 && r < 135)
						{
							*down = true;//�I�u�W�F�N�g�̉��̕������Փ˂��Ă���
							*y = by - 50.0f + (scrolly);//�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
							*vy = -0.5f;
						}
						if (r > 135 && r < 225)
						{
							*left = true;//�I�u�W�F�N�g�̉E�������Փ˂��Ă���
							*x = bx - 50.0f + (scrollx);//�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
							*vx = -0.5f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							*up = true;//�I�u�W�F�N�g�̏�̕������Փ˂��Ă���
							*y = by + 50.0f + (scrolly);//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�							
							*vy = 0.5f;

						}
					}
				}
			}
		}
	}
}

/*void CObjMap5::setenemy()
{
	//�G�o���ʒu�̐ݒ�
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			//15�𔭌�
			if (m_map[i][j] == 15)
			{
				//15�̒�����o���ꏊ�����肷��
				int herop = 0;
				herop = rand() % 2;
				if (herop == 0)
				{
					m_map[i][j] = 10;//�S
				}
				else if (herop == 1)
				{
					m_map[i][j] = 11;//���S
				}
				/*				else if (herop == 2)
				{
				m_map[i][j] = 12;//�΋S
				}
			}
		}
	}
}*/