#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define ITEM_TOP	(111.0f)
#define ITEM_LEFT	(256.0f)

//�I�u�W�F�N�g�F�L�����N�^�[�u���b�N
class CObjHone : public CObj
{
public:
	CObjHone() {};
	~CObjHone() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;	//�A�C�e���q�b�g�{�b�N�X�p
	float m_y;	//�A�C�e���q�b�g�{�b�N�X�p
	bool m_del;	//�폜�`�F�b�N


};




