#include <process.h>
#include "MultiThread.h"


using namespace GameL;
atomic<bool>  execution;							//�X���b�h���s�t���O
thread*		  CMultiThread::m_handoru_game;			//�Q�[���X���b�h


bool CMultiThread::GetEnd()
{
	return  execution.load(std::memory_order_acquire);
}

//������
void CMultiThread::Init( void(*game_sub)() )
{
	m_handoru_game = new thread(GameThread, (void *)game_sub);
}

//�폜
void CMultiThread::Delete()
{
	//�X���b�h�I���t���O�𗧂Ă�
	End();
	//�X���b�h�I���m�F
	m_handoru_game->join();
	delete m_handoru_game;

}

//�Q�[���X���b�h��~���\�b�h
void CMultiThread::End()
{	
	execution.store(false);	
}

//�Q�[���X���b�h�p���\�b�h
unsigned __stdcall CMultiThread::GameThread(void *p)
{
	execution.store(true);
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	

	void (*sub)() = (void(*)()) p;
	

	//�Q�[�����[�v
	while(execution.load(std::memory_order_acquire))
	{
		sub();
	}

	CoUninitialize();//�b�n�l����
    return 0;
}