#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���C�x���g
class CObjEveDog : public CObj
{
public:
	CObjEveDog() {};	//�R���X�g���N�^
	~CObjEveDog() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	char* m_pward;
	bool m_f;
};