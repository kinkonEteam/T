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
	void SetOf(bool of) { m_Of = of; }

private:
	bool m_Af; //�t���O
	bool m_Cf;
	bool m_Of; //�t���O

};


