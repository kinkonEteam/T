#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C��
class CObjstair :public CObj
{
	public:
		CObjstair(float x, float y,int c) ;
		~CObjstair() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[

		void SetTimeFlag(bool b) { m_flag_time = b; }
	private:
		float m_px;		 //�ʒu
		float m_py;
		int m_c;		//�񐔔ԍ�
		bool m_flag_time;//�V�[���؂�ւ��t���O
};