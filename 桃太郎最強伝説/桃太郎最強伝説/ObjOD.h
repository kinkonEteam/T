#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g���ɖ߂�
class CObjOD : public CObj
{
public:
	CObjOD() {};
	~CObjOD() {};
	void Init();     //�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();     //�h���[

private:
	bool m_key_f;//�G���^�[�L�[
	bool m_Af; //�t���O

};


