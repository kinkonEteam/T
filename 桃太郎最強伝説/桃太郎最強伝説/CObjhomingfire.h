#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�z�[�~���O�e��
class CObjHomingfire : public CObj
{
public:
	CObjHomingfire(float x, float y);
	~CObjHomingfire() {};
	void Init();     //�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();     //�h���[
private:
	float m_x;  //�I�u�W�F�N�g�̈ʒux
	float m_y;  //�I�u�W�F�N�g�̈ʒuy
	float m_vx; //�I�u�W�F�N�g�̈ړ��p�x�N�g��x
	float m_vy; //�I�u�W�F�N�g�̈ړ��p�x�N�g��y
};