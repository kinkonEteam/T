#pragma once
#include <Windows.h>
#include <D3D11.h> 
#include <d3dCompiler.h>

namespace GameL
{

	//DirectXDevice�̏������E�폜�N���X
	typedef class CDirectXDeviec
	{
		public :
			static void ViewClear();								// ��ʂ̃N���A
			static void ViewDraw2D();								// ��ʂ��QD���[�h�ɐ؂�ւ���
			static void ViewFlip();									// ��ʃX���b�v�`�F���W
			static HRESULT APIENTRY  InitDevice(HWND hWnd,int w,int h,float* c);	// �f�o�C�X���������\�b�h
			static void ShutDown();													// �f�o�C�X�V���b�g�_�E��

			static ID3D11Device*		GetDevice()		   { return m_pDevice;		  }
			static ID3D11DeviceContext* GetDeviceContext() { return m_pDeviceContext; }

		private:

			static ID3D11Device*           m_pDevice;				// D3D11�f�o�C�X
			static ID3D11DeviceContext*    m_pDeviceContext;		// D3D11�f�o�C�X�R���e�L�X�g
			static ID3D11RasterizerState*  m_pRS;					// D3D11���X�^���C�U�[
			static ID3D11RasterizerState*  m_pRS3D;					// D3D11���X�^���C�U�[3D
			static ID3D11RenderTargetView* m_pRTV;					// D3D11�����_�[�^�[�Q�b�g
			static ID3D11DepthStencilView* m_pDSV;					// D3D11�[�x�X�e���V���r���[
			static D3D_FEATURE_LEVEL       m_FeatureLevel;			// D3D�@�\���x��
			static ID3D11BlendState*	   m_pBlendState;			// �u�����h�X�e�[�^�X
			static IDXGIAdapter*           m_pDXGIAdapter;			// DXGI�A�_�v�^�[
			static IDXGIFactory*           m_pDXGIFactory;			// DXGI�t�@�N�g���[
			static IDXGISwapChain*         m_pDXGISwapChain;		// DXGI�X���b�v�`�F�[��
			static IDXGIOutput**           m_ppDXGIOutputArray;		// DXGI�o�͌Q
			static UINT                    m_nDXGIOutputArraySize;	// DXGI�o�͌Q�T�C�Y
			static IDXGIDevice1*		   m_pDXGIDevice;			// DXGI�f�o�C�X
			static int m_width ;
			static int m_height;
			static float* m_back_color;
	}Deviec;

};

