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
		float m_px;		//�v���C���[���W
		float m_py;
		float m_posx;	//�����ύX�p���W
		float m_posy;
		float m_r;		//���̊p�x
		float m_vr;		//�p�x�̑���
		int m_pos;		//��l���̌����i�[
};