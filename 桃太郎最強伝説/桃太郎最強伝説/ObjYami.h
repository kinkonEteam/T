#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�L�����N�^�[�u���b�N
class ObjYami : public CObj
{
public:
	ObjYami(int n) { m_num = n; }//�R���X�g���N�^
	~ObjYami() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	int m_num;
};