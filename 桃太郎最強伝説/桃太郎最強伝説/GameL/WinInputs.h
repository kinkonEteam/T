#pragma once
#include <Windows.h>

namespace GameL
{
	typedef class CWinInputs
	{
		public :
			static bool WmInput(HWND hWnd,UINT* uMsg, LPARAM* lParam);//�E�B���h�E�v���W�[�V���[�R�[���o�b�N�֐��o�^�p
			static bool GetVKey(int v_key);
			static bool GetMouButtonL();
			static bool GetMouButtonR();
		
			static int GetPosX();
			static int GetPosY();

			static void Refresh();
			static void Init();
		

		private:
			static int   m_x,m_y;		//�}�E�X���W
			static bool  m_ButtonL;		//�}�E�X�N���b�N
			static bool  m_ButtonR;
			static BYTE m_KeyBoard[256];//�L�[�{�[�h�z��
	}Input;
};