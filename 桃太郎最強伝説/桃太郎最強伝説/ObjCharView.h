#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

extern int c;
extern int s;
extern int m;

//�I�u�W�F�N�g:�^�C�g��
class ObjCharView : public CObj
{
public:
	ObjCharView() {};
	~ObjCharView() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	void SaveSM() { c = count; s = sec, m = min; }//�Z�[�u�A�Z�R���h�~�j�b�c
private:
	int count;			//�J�E���g�p
	int sec;			//�Z�R���h(�b)
	int min;			//�~�j�b�c(��)
};