#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�L�W
class CObjFlyKiji :public CObj
{
public:	    //�����ňʒu�ƌ�����n�����
	CObjFlyKiji(float x, float y, int m_pos);//�R���X�g���N�^
	~CObjFlyKiji() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

	float GetF() { return m_f; }
private:
	bool m_f = true;//�U������

	int m_pos;		//��l���̌����i�[
	int m_px;		//�����ɂ��ʒu�ύX�px,y
	int m_py;

	float m_x;		//�n���ꂽ�ʒu�i�[
	float m_y;
	float m_vx;    //X�����̑��x�p�ϐ�
	float m_vy;    //Y�����̑��x�p�ϐ�

	
	int m_ani_time; //�A�j���[�V�����^�C��
	int m_ani_frame;//�t���[��
	int m_s;		//ani_time�����X�ɉ���������ϐ�
	
};