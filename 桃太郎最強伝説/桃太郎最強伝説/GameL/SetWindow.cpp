#include "SetWindow.h"
using namespace GameL;

//�폜����Ă��Ȃ����������o�͂Ƀ_���v����
#ifdef _DEBUG
   #ifndef DBG_NEW
      #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
      #define new DBG_NEW
   #endif
#endif  // _DEBUG
HWND LSetWindow:: m_hWnd;
int  LSetWindow:: m_width;
int  LSetWindow:: m_height;

//�E�B���h�E�쐬
void LSetWindow::NewWindow(int w,int h,wchar_t* name,HINSTANCE hInstance)
{
	m_width =w;
	m_height=h;

	int width  = m_width + GetSystemMetrics(SM_CXDLGFRAME) * 2;
	int height = m_height + GetSystemMetrics(SM_CYDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION);

	//�E�B���h�E�쐬
	if( !( m_hWnd = CreateWindow( name, name, 
		WS_OVERLAPPEDWINDOW & ~( WS_MAXIMIZEBOX | WS_SIZEBOX ),
		CW_USEDEFAULT, 0,  width, height, 0, 0, hInstance, 0) ) )
	{
		 return ;
	}

	ShowWindow( m_hWnd, SW_SHOW );

}

//�E�B���h�E�j��
void LSetWindow::DeleteWindow()
{

	DestroyWindow(m_hWnd);	// �E�B���h�E��j�����o�^������
}