#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�I�u�W�F�N�g�F�L�����N�^�[�u���b�N
class CObjMonke : public CObj
{
public:
	CObjMonke(float x, float y);
	~CObjMonke() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;	//�����q�b�g�{�b�N�X�p
	float m_y;	//�����q�b�g�{�b�N�X�p
	float m_px;		 //�ʒu
	float m_py;
};

