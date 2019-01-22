#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G
class CObjEnemy :public CObj
{
public:
	CObjEnemy(float x, float y);
	~CObjEnemy() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

	float GetVx() { return m_vx; }

private:
	float m_px;		//�ʒu
	float m_py;
	float m_vx;		//�ړ��x�N�g��
	float m_vy;
	float m_posture;//�p��
	float alpha;

	int m_ani_time;	//�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;//�`��t���[��
	int m_hp;//�̗�

	int m_time;//���G���ԑ���
	int m_f;//���G����
	int m_key_f;//���G���ԍs������
	int count;
	int e_time;//�G�s������
	int enemy_move;//�G�ړ�

	int m_ftime;//�K�w�˓���̎��ԑ���

	float m_speed_power;	//�ʏ푬�x
	float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//�ړ��p�̌�������p
	bool m_movex;//���E
	bool m_movey;//�㉺

	bool m_do_f;//�G�U���t���O
};