#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g���ɖ߂�
class CObjPose : public CObj
{
public:
	CObjPose() {};
	~CObjPose() {};
	void Init();     //�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();     //�h���[
	void SetAf(bool af) { m_Af = af; }
private:
	bool m_CSceneposeFlag;
	bool m_Af; //�t���O
	bool m_Pf;


};

