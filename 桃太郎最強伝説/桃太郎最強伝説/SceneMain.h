#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[�����C��
class CSceneMain :public CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();	//�Q�[�����C���̏��������\�b�h
		void Scene();		//�Q�[�����C���̎��s�����\�b�h
		void SetScroll(float s) { m_scroll = s; }
		float GetScroll() { return m_scroll; }
	private:
		int m_time;
		float m_scroll;		//���E�X�N���[���p
};

