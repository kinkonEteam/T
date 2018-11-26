#pragma once
//�g�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjBullet : public CObj
{
public:
	CObjBullet(float x, float);//�R���g���N�^
	~CObjBullet() {};
	void Init();     //�C�j�V�����C�Y�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();     //�h���[
private:
	float  m_x;       //�e�ۂ�x�����̈ʒu�p�ϐ�
	float  m_y;       //�e�ۂ̂x�����̈ʒu�p�ϐ�
	float  m_vx;      //�e�ۂ̂������̑��x�p�ϐ�
	float  m_vy;

	int    m_ani;     //���e�A�j���[�V�����p
	int    m_ani_time;//���e�A�j���[�V�����ԃ^�C��
	bool   m_del;     //�폜�`�F�b�N
	RECT_F m_eff;     //���e�G�t�F�N�g�`��p
};