#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class ObjSell : public CObj
{
public:
	ObjSell() {};
	~ObjSell() {};
	void Init();      //�C�j�V�����C�Y
	void Action();    //�A�N�V����
	void Draw();      //�h���[
private:
	int m_page;
	int m_count;
	bool m_f;		//���ڂ̃g�[�N�쐬�p
	bool m_keyf;	//�������ςȂ�����
};