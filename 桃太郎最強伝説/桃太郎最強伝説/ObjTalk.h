#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�����o��
class CObjTalk : public CObj
{
public:
	CObjTalk(int t, int p) { m_tipe = t; m_p = p; }//�R���X�g���N�^
	~CObjTalk() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	bool m_f;		//���͐���
	int m_tipe;		//����̎��
	int m_p;		//�n���ꂽ�y�[�W��
	int m_page;		//�y�[�W��
	int m_sec;		//�Z�R���h(�b)
	int m_line;		//�s��
	int m_picture;	//�摜�ԍ�
};