#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���C�x���g
class CObjText4 : public CObj
{
public:
	CObjText4() {};	//�R���X�g���N�^
	~CObjText4() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	bool m_f;		//�������ϐ���
	int m_page;		//�R�����g�̃y�[�W
};