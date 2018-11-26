#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHero :public CObj
{
	public:
		CObjHero(float x, float y) ;
		~CObjHero() {};
		void Init();	 //�C�j�V�����C�Y
		void Action();	 //�A�N�V����
		void Draw();	 //�h���[

		float GetX() { return m_px; }
		float GetY() { return m_py; }
		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }
		float Gethp() { return m_hp; }

		void SetX(float x) { m_px = x; }
		void SetY(float y) { m_py = y; }
		void SetVY(float vy) { m_vy = vy; }
		void SetVX(float vx) { m_vx = vx; }

		void SetKf(float f) { m_Kf = f; }
	private:

	//��l���̈ʒu�ƈړ��p
		float m_px;		 //�ʒu
		float m_py;
		float m_vx;		 //�ړ��x�N�g���p�ϐ�
		float m_vy;
		float alpha;


		float m_posture; //�p��

		int m_hp;		 //HP
		int m_map[56][56];//�}�b�v���
		int m_time;//���G���ԑ���
		int m_f;//���G����
		int m_key_f;//���G���ԍs������
		int m_t;
		int count;

		int m_ani_time;  //�A�j���[�V�����t���[������Ԋu
		int m_ani_frame;	//�`��t���[��
		bool m_Sf;			//�\�[�h�U������
		bool m_Kf;			//�L�W�U������
		//block�Ƃ̏Փˏ�Ԋm�F�p
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

		int item_num[5];	//�A�C�e���̏������m�F�p
		//����ł���block�̎�ނ��m�F�p
		int m_block_type;


};