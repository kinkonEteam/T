#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���C�x���g
class CObjEveMnky : public CObj
{
public:
	CObjEveMnky() {};	//�R���X�g���N�^
	~CObjEveMnky() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	bool m_f;		//�������ϐ���
	int m_page;		//�R�����g�̃y�[�W
	bool m_df;	//���폜�p
};