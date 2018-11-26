//�J���}�N��
#define SAFE_DELETE(p)       { if (p) { delete (p);        (p)=nullptr;  }  }
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);      (p)=nullptr;  }  }
#define SAFE_RELEASE(p)      { if (p) { (p)->Release();    (p)=nullptr;  }	}

#include "DirectXDevice.h"
using namespace GameL;

ID3D11Device*           CDirectXDeviec::m_pDevice;				// D3D11�f�o�C�X
ID3D11DeviceContext*    CDirectXDeviec::m_pDeviceContext;		// D3D11�f�o�C�X�R���e�L�X�g
ID3D11RasterizerState*  CDirectXDeviec::m_pRS;					// D3D11���X�^���C�U�[
ID3D11RasterizerState*  CDirectXDeviec::m_pRS3D;				// D3D11���X�^���C�U�[3D
ID3D11RenderTargetView* CDirectXDeviec::m_pRTV;					// D3D11�����_�[�^�[�Q�b�g
ID3D11DepthStencilView* CDirectXDeviec::m_pDSV;					// D3D11�[�x�X�e���V���r���[
D3D_FEATURE_LEVEL       CDirectXDeviec::m_FeatureLevel;			// D3D�@�\���x��
ID3D11BlendState*	    CDirectXDeviec::m_pBlendState;			// �u�����h�X�e�[�^�X
IDXGIAdapter*           CDirectXDeviec::m_pDXGIAdapter;			// DXGI�A�_�v�^�[
IDXGIFactory*           CDirectXDeviec::m_pDXGIFactory;			// DXGI�t�@�N�g���[
IDXGISwapChain*         CDirectXDeviec::m_pDXGISwapChain;		// DXGI�X���b�v�`�F�[��
IDXGIOutput**           CDirectXDeviec::m_ppDXGIOutputArray;	// DXGI�o�͌Q
UINT                    CDirectXDeviec::m_nDXGIOutputArraySize;	// DXGI�o�͌Q�T�C�Y
IDXGIDevice1*			CDirectXDeviec::m_pDXGIDevice;			// DXGI�f�o�C�X
int						CDirectXDeviec::m_width ;
int						CDirectXDeviec::m_height;
float*					CDirectXDeviec::m_back_color;


//��ʂ̃N���A
void CDirectXDeviec::ViewClear()
{
	// ��ʂ��w��F�ŃN���A
	m_pDeviceContext->RSSetState(m_pRS3D);
	m_pDeviceContext->OMSetRenderTargets(1, &m_pRTV,m_pDSV );

	m_pDeviceContext->ClearRenderTargetView(m_pRTV, m_back_color);
	m_pDeviceContext->ClearDepthStencilView(m_pDSV, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
}

//�`��QD�p�ɕύX
void CDirectXDeviec::ViewDraw2D()
{
	  m_pDeviceContext->RSSetState(m_pRS);
	  m_pDeviceContext->OMSetRenderTargets(1, &m_pRTV,NULL );
}

//��ʃX���b�v�`�F���W
void CDirectXDeviec::ViewFlip()
{
	m_pDXGISwapChain->Present(1, 0);//60FPS
}

//�f�o�C�X�̏�����
HRESULT APIENTRY CDirectXDeviec::InitDevice(HWND hWnd,int w,int h,float* c) 
{
	m_width		=w;
	m_height	=h;
	m_back_color=c;

    HRESULT hr = S_OK;

    // �f�o�C�X�̃C���^�[�t�F�[�X
    ID3D11Device* pDevice = NULL;
    ID3D11DeviceContext* pDeviceContext = NULL;
    D3D_FEATURE_LEVEL featureLevel = (D3D_FEATURE_LEVEL)0;
    
    IDXGIDevice1* pDXGIDevice = NULL;
    IDXGIAdapter* pDXGIAdapter = NULL;
    IDXGIFactory* pDXGIFactory = NULL;
    IDXGISwapChain* pDXGISwapChain = NULL;
    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

    // ��������
    D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0};
    

    // �f�o�C�X�̏�����
    hr = D3D11CreateDevice(NULL,D3D_DRIVER_TYPE_HARDWARE,NULL,0,featureLevels,
            sizeof(featureLevels) / sizeof(D3D_FEATURE_LEVEL),D3D11_SDK_VERSION,
            &pDevice,&featureLevel,&pDeviceContext);

    if (FAILED(hr)) 
	{
        // �������Ɏ��s�����ꍇ�A�\�t�g�E�F�A�G�~�����[�g�����s
        hr = D3D11CreateDevice(NULL,D3D_DRIVER_TYPE_SOFTWARE,NULL,0,featureLevels,
                sizeof(featureLevels) / sizeof(D3D_FEATURE_LEVEL),D3D11_SDK_VERSION,
				&pDevice,&featureLevel,&pDeviceContext);
        if (FAILED(hr)) 
            return hr;
    }

    // �f�o�C�X����C���^�[�t�F�[�X�𒊏o
    hr = pDevice->QueryInterface(__uuidof(IDXGIDevice1), (LPVOID*)&pDXGIDevice);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
    hr = pDXGIDevice->GetAdapter(&pDXGIAdapter);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
    hr = pDXGIAdapter->GetParent(__uuidof(IDXGIFactory), (LPVOID*)&pDXGIFactory);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }

    // ���X�^���C�U�[�̐ݒ�
    D3D11_RASTERIZER_DESC drd =
	{
        D3D11_FILL_SOLID,   // �`�惂�[�h
        D3D11_CULL_NONE,    // �|���S���`�����D3D11_CULL_BACK
        true,               // �O�p�`�̖ʕ��� TRUE - �����
        0,                  // �s�N�Z�����Z�[�x��
        0.0f,               // �s�N�Z���ő�k�x�o�C�A�X
        0.0f,               // �w��s�N�Z���̃X���[�v�ɑ΂���X�J���[
        TRUE,               // �����Ɋ�Â��ăN���b�s���O���邩
        FALSE,              // �V�U�[�Z�`�J�����O��L���ɂ��邩
        TRUE,               // �}���`�T���v�����O��L���ɂ��邩
        TRUE               // ���̃A���`�G�C���A�X��L���ɂ��邩
    };
    ID3D11RasterizerState* pRS = NULL;
    hr = pDevice->CreateRasterizerState(&drd, &pRS);

	// ���X�^���C�U�[3D�̐ݒ�
    D3D11_RASTERIZER_DESC drd3d =
	{
        D3D11_FILL_SOLID,   // �`�惂�[�h
        D3D11_CULL_BACK,    // �|���S���`�����
        false,               // �O�p�`�̖ʕ��� TRUE - �����
        0,                  // �s�N�Z�����Z�[�x��
        0.0f,               // �s�N�Z���ő�k�x�o�C�A�X
        0.0f,               // �w��s�N�Z���̃X���[�v�ɑ΂���X�J���[
        TRUE,               // �����Ɋ�Â��ăN���b�s���O���邩
        FALSE,              // �V�U�[�Z�`�J�����O��L���ɂ��邩
        TRUE,               // �}���`�T���v�����O��L���ɂ��邩
        TRUE               // ���̃A���`�G�C���A�X��L���ɂ��邩
    };
    ID3D11RasterizerState* pRS3D = NULL;
    hr = pDevice->CreateRasterizerState(&drd3d, &pRS3D);


    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
   
	
    // ��ʃ��[�h���
    UINT OutputCount = 0;
    for (OutputCount = 0; ; OutputCount ++)
	{
        IDXGIOutput* pDXGIOutput = NULL;
        if (FAILED(pDXGIAdapter->EnumOutputs(OutputCount, &pDXGIOutput)))
			 break;
        
        SAFE_RELEASE(pDXGIOutput);
    }
    IDXGIOutput** ppDXGIOutputArray = new IDXGIOutput*[OutputCount];
    if (ppDXGIOutputArray == NULL) 
	{
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return E_OUTOFMEMORY;
    }
    for (UINT iOutput = 0; iOutput < OutputCount; iOutput ++) 
	{
        pDXGIAdapter->EnumOutputs(iOutput, ppDXGIOutputArray + iOutput);
    }
    // �A�E�g�v�b�g�z��������o��
    m_ppDXGIOutputArray = ppDXGIOutputArray;
    m_nDXGIOutputArraySize = OutputCount;

    // �X���b�v�`�F�[���̏������Ɛ���
    swapChainDesc.BufferDesc.Width                      = m_width;
    swapChainDesc.BufferDesc.Height                     = m_height;
    swapChainDesc.BufferDesc.Format                     = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferDesc.RefreshRate.Denominator    = 1;
    swapChainDesc.BufferDesc.RefreshRate.Numerator      = 60;
    swapChainDesc.BufferDesc.Scaling                    = DXGI_MODE_SCALING_UNSPECIFIED;
    swapChainDesc.BufferDesc.ScanlineOrdering           = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE;
    swapChainDesc.SampleDesc.Count						= 1;
	swapChainDesc.SampleDesc.Quality					= 0;
    swapChainDesc.BufferUsage                           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.BufferCount                           = 1;
    swapChainDesc.OutputWindow                          = hWnd;
    swapChainDesc.Windowed                              = TRUE;
    swapChainDesc.SwapEffect                            = DXGI_SWAP_EFFECT_DISCARD;
    swapChainDesc.Flags                                 = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

    hr = pDXGIFactory->CreateSwapChain(pDevice, &swapChainDesc, &pDXGISwapChain);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }

    // D3D11�C���^�[�t�F�[�X�̏����o��
    m_pDevice           = pDevice;
    m_pDeviceContext    = pDeviceContext;
    m_pDXGIAdapter      = pDXGIAdapter;
    m_pDXGIFactory      = pDXGIFactory;
    m_pDXGISwapChain    = pDXGISwapChain;
	m_FeatureLevel      = featureLevel;
	m_pDXGIDevice		= pDXGIDevice;

  

    //---------------------------------------------------------------
    // �����_�����O�^�[�Q�b�g�𐶐�
    ID3D11DepthStencilView* pDSV = NULL;
    ID3D11RenderTargetView* pRTV = NULL;

    // �o�b�N�o�b�t�@���擾
    ID3D11Texture2D* pBackBuffer = NULL;
    hr = pDXGISwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    if (FAILED(hr))
	{
        SAFE_RELEASE(pDXGISwapChain);
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
    D3D11_TEXTURE2D_DESC BackBufferSurfaceDesc;
    pBackBuffer->GetDesc(&BackBufferSurfaceDesc);

    // �����_�����O�^�[�Q�b�g�𐶐�
    hr = pDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRTV);
	//�o�b�N�o�b�t�@���
    SAFE_RELEASE(pBackBuffer);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGISwapChain);
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }

    // �[�x�X�e���V���e�N�X�`���𐶐�
    ID3D11Texture2D* pDepthStencil = NULL;
    D3D11_TEXTURE2D_DESC DescDepth;
    DescDepth.Width             = m_width;
    DescDepth.Height            = m_height;
    DescDepth.MipLevels         = 1;
    DescDepth.ArraySize         = 1;
    DescDepth.Format            = DXGI_FORMAT_D24_UNORM_S8_UINT;
    DescDepth.Usage             = D3D11_USAGE_DEFAULT;
    DescDepth.BindFlags         = D3D11_BIND_DEPTH_STENCIL;
    DescDepth.CPUAccessFlags    = 0;
    DescDepth.MiscFlags         = 0;
	DescDepth.SampleDesc.Count   = 1;
	DescDepth.SampleDesc.Quality = 0;

    hr = pDevice->CreateTexture2D(&DescDepth, NULL, &pDepthStencil);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGISwapChain);
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }

    // �[�x�X�e���V���𐶐�
    D3D11_DEPTH_STENCIL_VIEW_DESC DescDSV;
    DescDSV.Format              = DescDepth.Format;
    DescDSV.Flags               = 0;
    DescDSV.ViewDimension       = D3D11_DSV_DIMENSION_TEXTURE2DMS;
    DescDSV.Texture2D.MipSlice  = 0;
    hr = pDevice->CreateDepthStencilView(pDepthStencil, &DescDSV, &pDSV);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGISwapChain);
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
	//�[�x�X�e���V���o�b�t�@���
	SAFE_RELEASE(pDepthStencil);
	
    // �r���[�|�[�g�̐ݒ�
    D3D11_VIEWPORT vp;
    vp.Width    = (float)m_width;
    vp.Height   = (float)m_height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0.0f;
    vp.TopLeftY = 0.0f;
    pDeviceContext->RSSetViewports(1, &vp);

	// �u�����h�X�e�[�g�𐶐�
    D3D11_BLEND_DESC BlendDesc = {FALSE,FALSE};
    for (int i = 0; i < 8; i ++)
	{
        BlendDesc.RenderTarget[i].BlendEnable           = TRUE;
        BlendDesc.RenderTarget[i].SrcBlend              = D3D11_BLEND_SRC_ALPHA;
        BlendDesc.RenderTarget[i].DestBlend             = D3D11_BLEND_INV_SRC_ALPHA;
        BlendDesc.RenderTarget[i].BlendOp               = D3D11_BLEND_OP_ADD;
        BlendDesc.RenderTarget[i].SrcBlendAlpha         = D3D11_BLEND_ONE;
        BlendDesc.RenderTarget[i].DestBlendAlpha        = D3D11_BLEND_ZERO;
        BlendDesc.RenderTarget[i].BlendOpAlpha          = D3D11_BLEND_OP_ADD;
        BlendDesc.RenderTarget[i].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    }
    m_pDevice->CreateBlendState(&BlendDesc, &m_pBlendState);
    
    // �u�����f�B���O
    m_pDeviceContext->OMSetBlendState(m_pBlendState, NULL, 0xFFFFFFFF);
													
    // �X�e�[�^�X�A�r���[�Ȃǂ������o��
    m_pRS   = pRS;
    m_pRS3D	= pRS3D;
	m_pRTV  = pRTV;
    m_pDSV  = pDSV;
    return hr;
}

//�I���֐�
void CDirectXDeviec:: ShutDown() 
{
	//�u�����h�X�e�[�^�X
	SAFE_RELEASE(m_pBlendState);


    // �[�x�X�e���V���̃e�N�X�`���[�ƃr���[�����
    SAFE_RELEASE(m_pDSV);

    // �����_�����O�^�[�Q�b�g�����
    SAFE_RELEASE(m_pRTV);

    // �X���b�v�`�F�[�������
    if(m_pDXGISwapChain != NULL) 
	{
        m_pDXGISwapChain->SetFullscreenState(FALSE, 0);
	}
    SAFE_RELEASE(m_pDXGISwapChain);
 

    // �A�E�g�v�b�g�����
    for (UINT i = 0; i < m_nDXGIOutputArraySize; i ++) 
        SAFE_RELEASE(m_ppDXGIOutputArray[i]);
    SAFE_DELETE_ARRAY(m_ppDXGIOutputArray);

	// ���X�^���C�U�[
	SAFE_RELEASE(m_pRS3D);
	SAFE_RELEASE(m_pRS);
	

	//�t�@�N�g���[�̉��
	SAFE_RELEASE(m_pDXGIFactory);

    // �A�_�v�^�[�̉��
    SAFE_RELEASE(m_pDXGIAdapter);

	// DXGI�f�o�C�X�̉��
    SAFE_RELEASE(m_pDXGIDevice);

    // D3D11�f�o�C�X�R���e�L�X�g�����
    SAFE_RELEASE(m_pDeviceContext);
 
    // D3D11�f�o�C�X�̉��
    SAFE_RELEASE(m_pDevice);

}

			
	
				
						
