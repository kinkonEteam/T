#pragma once
#include <crtdbg.h>
#include <Windows.h>

namespace GameL
{
	//�E�B���h�E�쐬
	typedef class LSetWindow
	{
		public:
			static void NewWindow(int w,int h,wchar_t* name,HINSTANCE hInstance);
			static void DeleteWindow();
			static HWND GethWnd()	{return m_hWnd;}
		private:
			static HWND m_hWnd;			//�E�B���h�E�n���h��
			static int  m_width;
			static int  m_height;
	}Window;

};