#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[�����C��
class CSceneSell :public CScene
{
public:
	CSceneSell();
	~CSceneSell();
	void InitScene();	//�Q�[�����C���̏��������\�b�h
	void Scene();		//�Q�[�����C���̎��s�����\�b�h
private:
	extern int item_list[5];
};

