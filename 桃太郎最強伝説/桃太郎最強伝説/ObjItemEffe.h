#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���C�x���g
class ObjItemEffe : public CObj
{
public:
	ObjItemEffe(int i) { m_item = i; }	//�R���X�g���N�^
	~ObjItemEffe() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	int m_item;//1��, 2����, 3������, 4��, 5���̉��ז_, 6��̉��ז_, 7���_
};