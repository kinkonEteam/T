#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CScenefloor1 :public CScene
{
	public:
		CScenefloor1();
		~CScenefloor1();
		void InitScene();//���������\�b�h
		void Scene();	//���s�����\�b�h
		void SetScroll(float s) { m_scroll = s; }
		float GetScroll() { return m_scroll; }
	private:

		float m_scroll;		//���E�X�N���[���p

};