#pragma once
//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0) 

#include <thread>
#include <vector>
#include <atomic>
#include <Windows.h>


using namespace std;

namespace GameL
{
	typedef class CMultiThread
	{
		public:
			static void Init(void(*game_sub)());
			static void Delete();
			static void End();
			static bool GetEnd();
		private:

			static unsigned __stdcall GameThread(void *p);	//�Q�[���X���b�h�p���\�b�h
			
			static thread*		 m_handoru_game;			//�Q�[���X���b�h
	}GameLoop;
};