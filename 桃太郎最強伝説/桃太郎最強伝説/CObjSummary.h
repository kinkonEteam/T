#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���C�x���g
class CObjSummary : public CObj
{
public:
	CObjSummary() {};	//�R���X�g���N�^
	~CObjSummary() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	bool m_f;		//�������ϐ���
	bool m_key_f;//�G���^�[�L�[
	int m_page;		//�R�����g�̃y�[�W
};