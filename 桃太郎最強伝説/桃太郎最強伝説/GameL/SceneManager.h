#pragma once

namespace GameL
{
	//�p�����ۗp�@�V�[���N���X
	class CScene
	{
		public:
			CScene(){}
			virtual ~CScene(){};
			virtual void InitScene()=0;
			virtual void Scene()=0;
		private:
	};

	//�V�[���}�l�[�W���[�N���X
	typedef class CSceneManager
	{
		public:
			static void Delete();
			static void SetScene(CScene* scene);	//�V�����V�[���̃Z�b�g���āA�Â��V�[����j������B
			static void GameLoop();					//�o�^���Ă�V�[�������s����
			static void Init();						//������
			static CScene* GetScene();

		private:
			static CScene* m_NewScene;			//�V�����V�[�����
			static CScene*	m_Scene;			//���݂̃V�[�����
			static unsigned long m_TimeStart;
			static unsigned long m_TimeEnd;
			static unsigned long m_Time;
			static int m_TimeCount;

			static void SceneAction();
			static void SceneDraw();
			static void Swap();
	}Scene;

};
