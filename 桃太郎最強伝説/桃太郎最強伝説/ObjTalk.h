#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�����o��
class CObjTalk : public CObj
{
public:
	CObjTalk(/*char* t*/) {/* m_pward = t; */ };//�R���X�g���N�^
	~CObjTalk() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	char* m_pward;
};