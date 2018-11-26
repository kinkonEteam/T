//�폜����Ă��Ȃ����������o�͂Ƀ_���v����
#include <crtdbg.h>
#ifdef _DEBUG
   #ifndef DBG_NEW
      #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

      #define new DBG_NEW
   #endif
#endif  // _DEBUG

//LIB
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d11.lib") 
#pragma comment(lib, "d3dCompiler.lib")
#pragma comment(lib, "XAudio2.lib")

//���C���w�b�_
#include <stdio.h>
#include <process.h>
#include <Windows.h>

#include "SetWindow.h"
#include "DirectXDevice.h"
#include "DrawTexture.h"
#include "WinInputs.h"
#include "Audio.h"
#include "MultiThread.h"
#include "DrawFont.h"
#include "SceneManager.h"
#include "SceneObjManager.h"
#include "HitBoxManager.h"
#include "UserData.h"

#include "..\GameHead.h"
#include "..\main.h"

using namespace GameL;

//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//Main�֐�
int APIENTRY wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR szCmdLine,int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	wchar_t  name []={GAME_NAME};	//�E�B���h�E���^�C�g���l�[��
	MSG  msg;						//���b�Z�[�W�n���h��
	
	//�b�n�l������
	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	//�E�B���h�E�X�e�[�^�X
	WNDCLASSEX wcex = {
	   sizeof(WNDCLASSEX),
	   CS_HREDRAW | CS_VREDRAW,
	   WndProc,0, 0,hInstance,
	   NULL, NULL,(HBRUSH)(COLOR_WINDOW+1),
	   NULL,name,NULL
	};

	//�E�B���h�E�N���X�쐬
	RegisterClassEx( &wcex );

	//�E�B���h�E�쐬������
	LSetWindow::NewWindow(WINDOW_SIZE_W,WINDOW_SIZE_H,name,hInstance);
	
	//DirectX�f�o�C�X�쐬������
	float color[]=BACK_COLOR;
	CDirectXDeviec::InitDevice(LSetWindow::GethWnd(), PIXEL_SIZE_W, PIXEL_SIZE_H,color);

	//�Q�c�p�e�N�X�`���C���[�W�ǂݍ��ݏ�����
	CDrawTexture::InitDraw(CDirectXDeviec::GetDevice(),CDirectXDeviec::GetDeviceContext(),
		PIXEL_SIZE_W, PIXEL_SIZE_H,SCENE_IMG_MAX);
	
	//�C���v�b�g������
	CWinInputs::Init();

	//�I�[�f�B�I������
	CAudio::Init(SCENE_AUDIO_MAX);

	//�t�H���g������
	CDrawFont::Init(CDirectXDeviec::GetDevice(),CDirectXDeviec::GetDeviceContext());

	//�I�u�W�F�N�g�}�l�[�W���[
	CSceneObjManager::Init();

	//�����蔻�菉����
	CHitBoxManager::Init();

	//���[�U�[�f�[�^
	UserData user_data;
	memset(&user_data,0x00,sizeof(CUserData));
	CUserData::Init(&user_data,sizeof(UserData));

	//�����V�[���ǂݍ���
	#ifdef SET_GAME_START
		CSceneManager::SetScene(new SET_GAME_START() );
	#else
		CSceneManager::SetScene(nullptr);
	#endif

	//�}���`�X���b�h�N��
	CMultiThread::Init(&CSceneManager::GameLoop);

	//���b�Z�[�W���[�v
	do
	{

		if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			
			TranslateMessage( &msg );
			DispatchMessage(&msg);
		}
		
		//�V�[�������ŋ����I��
		if(CMultiThread::GetEnd()==false)
		{
			break;
		}

	}while( msg.message != WM_QUIT );
	

	CMultiThread::Delete();
	CUserData::Delete();
	CHitBoxManager::Delete();
	CSceneObjManager::Delete();
	CSceneManager::Delete();
	CDrawFont::Delete();
	CDrawTexture::DeleteDrawTexture();
	CAudio::Delete();
	CDirectXDeviec::ShutDown();
	CoUninitialize();//�b�n�l����
	
	//���̎��_�ŊJ������Ă��Ȃ��������̏��̕\��
	_CrtDumpMemoryLeaks();
	
	return true;
}

//�R�[���o�b�N�֐�
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//�}�E�X���擾�p
	CWinInputs::WmInput(hWnd, &uMsg, &lParam);
    
	switch (uMsg)
	{
		case WM_KEYDOWN:		//ESC�L�[�ŏI��
			switch (wParam)
			{
				case VK_ESCAPE:
					CMultiThread::End();
					LSetWindow::DeleteWindow();
					PostQuitMessage(0);	
				break;
			}
		break;
		case WM_CLOSE:			// �E�B���h�E�����ꍇ
			CMultiThread::End();
			PostQuitMessage(0);	
			break;
		case WM_DESTROY:		// �I������ꍇ
        return 0;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


