#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���C�x���g
class CObjText : public CObj
{
public:
	CObjText() {};	//�R���X�g���N�^
	~CObjText() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	bool m_f;		//�������ϐ���
	int m_page;		//�R�����g�̃y�[�W
};