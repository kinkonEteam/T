#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��
class CObjSword :public CObj
{
	public:	    //�����ňʒu�ƌ�����n�����
		CObjSword(float x, float y,int m_pos);//�R���X�g���N�^
		~CObjSword() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
	private:
		float m_x;		//�n���ꂽ�ʒu�i�[
		float m_y;
		float m_px;
		float m_py;
		int m_pos;		//��l���̌����i�[
		int m_sx;		//�����ɂ��ʒu�ύX�px,y
		int m_sy;

		int m_ani_time; //�A�j���[�V�����^�C��
		int m_ani_frame;//�t���[��
		int m_s;		//ani_time�����X�ɉ���������ϐ�
};