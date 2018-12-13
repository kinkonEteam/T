#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�L�����N�^�[�u���b�N
class ObjCapture : public CObj
{
public:
	ObjCapture(int n) { m_num = n; }//�R���X�g���N�^
	~ObjCapture() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

	void SetImage(int n) { m_num = n; }
	void SetAlpha(float a) { m_alpha = a; }
private:
	int m_num;	//�摜�o�^�i���o�[
	float m_alpha;//�����x
};