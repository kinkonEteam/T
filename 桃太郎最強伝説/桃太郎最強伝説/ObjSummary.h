#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���炷��
class CObjSummary : public CObj
{
public:
	CObjSummary(){};
	~CObjSummary(){};
	void Init();
	void Action();
	void Draw();
	
private:
	int m_time;     //����
	bool m_key_f;//�G���^�[�L�[
	float m_y;//�X�N���[���p
	int m_ky;//��s�̊Ԋu
	
	
};
