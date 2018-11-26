#include <wincodec.h>
#include "DrawTexture.h"
using namespace GameL;

#define SAFE_RELEASE(p)      { if (p) { (p)->Release();    (p)=nullptr;  }	}
#define SAFE_RESET(p)		 { if (p) { (p).reset(nullptr);				 }  }


//�|���S���\����
struct DRAW_POLYGON
{
	float		   pos[3];	//x-y-z���_���
	unsigned int   id[2];	//�t�u�̂h�c
};

//Draw2DTex.hlsl�O���[�o��
struct DRAW_2D_TEX
{
	float size[4];		//��ʃT�C�Y
	float color[4];		//�J���[���
	float rect_in[4];	//�؂���ʒu
	float rect_out[4];	//�\��t���ʒu
	float rotation[4];	//��]���
};


//�f�o�C�X
ID3D11DeviceContext*CDrawTexture::m_pDeviceContext;
ID3D11Device*		CDrawTexture::m_pDevice; 

//�e�N�X�`�����
vector< shared_ptr<C_TEX_DATA> > CDrawTexture::vec_tex_data;

//�E�B���h�E���
int CDrawTexture::m_width ;
int CDrawTexture::m_height; 

//�擾�C���[�W�ő吔
int CDrawTexture::m_img_max;

//�V�F�[�_�֌W
ID3D11VertexShader* CDrawTexture::m_pVertexShader;		//�o�[�e�b�N�X�V�F�[�_�[
ID3D11PixelShader*  CDrawTexture::m_pPixelShader;		//�s�N�Z���V�F�[�_�[
ID3D11SamplerState* CDrawTexture::m_pSampleLinear;		//�e�N�X�`���[�T���v���[
ID3D11InputLayout*  CDrawTexture::m_pVertexLayout;		//���_���̓��C�A�E�g
//�o�b�t�@
ID3D11Buffer*		CDrawTexture::m_pVertexBuffer;		//�Q�c�|���S���p�o�[�e�B�N�X�o�b�t�@
ID3D11Buffer*		CDrawTexture::m_pConstantBuffer;	//�A�v�������V�F�[�_�[�˂��� �R���X�^���g�o�b�t�@
ID3D11Buffer*		CDrawTexture::m_pIndexBuffer;		//�C���f�b�N�X�o�b�t�@

//�QD�`��pHLSL������
extern const char* g_hlsl_str;

//�e�N�X�`���ۑ��p�N���X���\�b�h�S----------------
C_TEX_DATA::C_TEX_DATA()
{	
	m_pSRV			= nullptr;
	m_tex_size_h	= 128;
	m_tex_size_w    = 128;
}


C_TEX_DATA::~C_TEX_DATA()
{
	SAFE_RELEASE(m_pSRV);
	m_tex_size_h	= 128;
	m_tex_size_w    = 128;
}

ID3D11ShaderResourceView** C_TEX_DATA::GetTexData()
{
	return &m_pSRV;
}

float C_TEX_DATA::GetTexSizeH()
{
	return m_tex_size_h;
}

float C_TEX_DATA::GetTexSizeW()
{
	return m_tex_size_w;
}

void C_TEX_DATA::SetTexData(ID3D11ShaderResourceView* tex)
{
	m_pSRV=tex;
}

void C_TEX_DATA::SetTexSize(float  size_w, float size_h)
{
	m_tex_size_h = size_h;
	m_tex_size_w = size_w;
}
	
//�e�N�X�`���ǂݍ��݁E�\���N���X���\�b�h�S-------
//�QD�g�p�ݒ�
void  CDrawTexture::Set2DDraw()
{
	//���_���C�A�E�g
	m_pDeviceContext->IASetInputLayout( m_pVertexLayout );

	//�A���o�b�t�@�Œ�
	m_pDeviceContext->VSSetConstantBuffers(0,1,&m_pConstantBuffer );
	m_pDeviceContext->PSSetConstantBuffers(0,1,&m_pConstantBuffer );

	//�g�p����V�F�[�_�[�̓o�^
	m_pDeviceContext->VSSetShader(m_pVertexShader,NULL,0);
	m_pDeviceContext->PSSetShader(m_pPixelShader,NULL,0);

	//�v���~�e�B�u�E�g�|���W�[���Z�b�g
	m_pDeviceContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP  );

	//�e�N�X�`���[���V�F�[�_�[�ɓn��
	m_pDeviceContext->PSSetSamplers(0,1,&m_pSampleLinear);

	//�o�[�e�b�N�X�o�b�t�@�o�^
	UINT stride = sizeof( DRAW_POLYGON ),offset = 0;
	m_pDeviceContext->IASetVertexBuffers( 0, 1, &m_pVertexBuffer, &stride, &offset );

	//�C���f�b�N�X�o�b�t�@�o�^
	m_pDeviceContext->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);
}

//�����蔻��`��
void CDrawTexture::DrawHitBox(float x,float y,float h,float w,float col[4])
{
	//�QD�g�p�ݒ�
	Set2DDraw();
	//�V�F�[�_�f�[�^�A��
	D3D11_MAPPED_SUBRESOURCE pData;
	if( SUCCEEDED( m_pDeviceContext->Map( m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData ) ) )
	{
		DRAW_2D_TEX  data;
		data.color[0]=col[0];	data.color[1]=col[1];	data.color[2]=col[2];	data.color[3]=col[3];

		data.size[0]=0.0f;				data.size[1]=0.0f;
		data.size[2]=(float)m_width;	data.size[3]=(float)m_height;

		data.rect_out[0]=(float)x;		data.rect_out[1]=(float)y;
		data.rect_out[2]=(float)x+w;	data.rect_out[3]=(float)y+h;

		data.rect_in[0]=0.0f;			data.rect_in[1]=0.0f;
		data.rect_in[2]=0.0f;			data.rect_in[3]=0.0f;
		

		data.rotation[0] = 0.0f;		data.rotation[1] = 0.0f;
		data.rotation[2] = 0.0f;		data.rotation[3] = 0.0f;
		memcpy_s(pData.pData, pData.RowPitch, (void*)&data, sizeof(DRAW_2D_TEX));
		m_pDeviceContext->Unmap( m_pConstantBuffer, 0 );
	}

	//�v���~�e�B�u�������_�����O
	m_pDeviceContext->DrawIndexed(4, 0, 0);
}

//�����`��
void CDrawTexture::DrawStr(ID3D11ShaderResourceView* ptex_res_view,float x,float y,float size,float col[4])
{
	//�QD�g�p�ݒ�
	Set2DDraw();
	//�V�F�[�_�f�[�^�A��
	D3D11_MAPPED_SUBRESOURCE pData;
	if( SUCCEEDED( m_pDeviceContext->Map( m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData ) ) )
	{
		DRAW_2D_TEX  data;
		data.color[0]=col[0];	data.color[1]=col[1];	data.color[2]=col[2];	data.color[3]=col[3];

		data.size[0]=1.0f;				data.size[1]=1.0f;
		data.size[2]=(float)m_width;	data.size[3]=(float)m_height;

		data.rect_out[0]=(float)x;		data.rect_out[1]=(float)y;
		data.rect_out[2]=(float)x+size;	data.rect_out[3]=(float)y+size;

		data.rect_in[0]=0.0f;			data.rect_in[1]=0.0f;
		data.rect_in[2]=1.0f;			data.rect_in[3]=1.0f;

		data.rotation[0] = 0.0f;		data.rotation[1] = 0.0f;
		data.rotation[2] = 0.0f;		data.rotation[3] = 0.0f;

		memcpy_s( pData.pData, pData.RowPitch, (void*)&data, sizeof( DRAW_2D_TEX  ) );

		m_pDeviceContext->Unmap( m_pConstantBuffer, 0 );
	}

	//�e�N�X�`���ݒ�
	m_pDeviceContext->PSSetShaderResources(0,1, &ptex_res_view);

	//�v���~�e�B�u�������_�����O
	m_pDeviceContext->DrawIndexed(4, 0, 0);
}

//�`��
void CDrawTexture:: Draw(int id,RECT_F* src,RECT_F* dst,float col[4],float r)
{
	if(m_img_max < id ) return ;
	if(vec_tex_data[id]->GetTexData()==nullptr) return ; 

	//�QD�g�p�ݒ�
	Set2DDraw();

	//�V�F�[�_�f�[�^�A��
	D3D11_MAPPED_SUBRESOURCE pData;
	if( SUCCEEDED( m_pDeviceContext->Map( m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData ) ) )
	{
		DRAW_2D_TEX  data;
		data.color[0]=col[0];	data.color[1]=col[1];	
		data.color[2]=col[2];	data.color[3]=col[3];

		data.size[0]=(float)vec_tex_data[id]->GetTexSizeW();	data.size[1]= (float)vec_tex_data[id]->GetTexSizeH();
		data.size[2]=(float)m_width;							data.size[3]=(float)m_height;

		data.rect_out[0]=dst->m_left;		data.rect_out[1]=dst->m_top;
		data.rect_out[2]=dst->m_right;		data.rect_out[3]=dst->m_bottom;

		data.rect_in[0]=src->m_left;		data.rect_in[1]=src->m_top;
		data.rect_in[2]=src->m_right;		data.rect_in[3]=src->m_bottom;

		data.rotation[0] = r;		data.rotation[1] = r;
		data.rotation[2] = r;		data.rotation[3] = r;
		memcpy_s( pData.pData, pData.RowPitch, (void*)&data, sizeof( DRAW_2D_TEX  ) );

		m_pDeviceContext->Unmap( m_pConstantBuffer, 0 );
	}

	//�e�N�X�`���ݒ�
	m_pDeviceContext->PSSetShaderResources(0,1,vec_tex_data[id].get()->GetTexData());

	//�v���~�e�B�u�������_�����O
	m_pDeviceContext->DrawIndexed(4, 0, 0);

}


//�`����\�z����
void CDrawTexture::InitDraw(ID3D11Device* p_device,ID3D11DeviceContext* p_device_context,int w,int h,int img_max)
{

	m_pDevice		= p_device;
	m_pDeviceContext= p_device_context;

	//�E�B���h�E���擾
	m_width =w;
	m_height=h; 

	//�擾�C���[�W�ő吔�����ɋ��e�ʂƗv�f����ݒ�
	m_img_max=img_max;
	vec_tex_data.reserve(m_img_max);//�z��̋��e�ʐݒ�
	vec_tex_data.resize(m_img_max);	//�z��̗v�f���ݒ�
	

	//�擾�e�N�X�`���������m��
	for(int i=0; i<m_img_max;i++)
	{
		vec_tex_data[i].reset(new C_TEX_DATA());
	}

	//hlsl�t�@�C����
	wchar_t* hlsl_name=L"GameL\\Draw2DTex.hlsl";
	
	//hlsl�t�@�C���ǂݍ��� �u���u�쐬�@�u���u�Ƃ̓V�F�[�_�[�̉�݂����Ȃ��́B
	//XX�V�F�[�_�[�Ƃ��ē����������Ȃ��B��Ŋe��V�F�[�_�[�ƂȂ�
	ID3DBlob *pCompiledShader=NULL;
	ID3DBlob *pErrors		 =NULL;
	//�u���u����o�[�e�b�N�X�V�F�[�_�[�쐬
	if (FAILED(D3DCompile(g_hlsl_str, strlen(g_hlsl_str), 0, 0, D3D_COMPILE_STANDARD_FILE_INCLUDE, "vs", "vs_4_0", 0,0, &pCompiledShader, &pErrors)))
	{
		char* c = (char*)pErrors->GetBufferPointer();
		MessageBox(0, L"hlsl�ǂݍ��ݎ��s", NULL, MB_OK);
		return;
	}
	SAFE_RELEASE(pErrors);
	
	if(FAILED(m_pDevice->CreateVertexShader(pCompiledShader->GetBufferPointer(),pCompiledShader->GetBufferSize(),NULL,&m_pVertexShader)))
	{
		SAFE_RELEASE(pCompiledShader);
		MessageBox(0,L"�o�[�e�b�N�X�V�F�[�_�[�쐬���s",NULL,MB_OK);
		return ;
	}
	
	//���_�C���v�b�g���C�A�E�g���`	
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }, 
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_UINT	, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }, 
	};
	UINT numElements = sizeof(layout)/sizeof(layout[0]);
	//���_�C���v�b�g���C�A�E�g���쐬�E���C�A�E�g���Z�b�g
	if( FAILED(m_pDevice->CreateInputLayout( layout, numElements, pCompiledShader->GetBufferPointer(), pCompiledShader->GetBufferSize(), &m_pVertexLayout ) ) )
		return ;
	SAFE_RELEASE(pCompiledShader);

	//�u���u����s�N�Z���V�F�[�_�[�쐬
	if (FAILED(D3DCompile(g_hlsl_str, strlen(g_hlsl_str), 0, 0, D3D_COMPILE_STANDARD_FILE_INCLUDE, "ps", "ps_4_0", 0, 0, &pCompiledShader, &pErrors)))
	{
		char* c = (char*)pErrors->GetBufferPointer();
		MessageBox(0, L"hlsl�ǂݍ��ݎ��s", NULL, MB_OK);
		return;
	}
	SAFE_RELEASE(pErrors);
	if(FAILED(m_pDevice->CreatePixelShader(pCompiledShader->GetBufferPointer(),pCompiledShader->GetBufferSize(),NULL,&m_pPixelShader)))
	{
		SAFE_RELEASE(pCompiledShader);
		MessageBox(0,L"�s�N�Z���V�F�[�_�[�쐬���s",NULL,MB_OK);
		return ;
	}
	SAFE_RELEASE(pCompiledShader);


	//�o�[�e�b�N�X�o�b�t�@�쐬
	DRAW_POLYGON vertices[] =
	{
		{ 1.0f, 1.0f, 0.0f,		1,3},	//���_1
		{ 1.0f, 0.0f, 0.0f,		1,2},	//���_2
		{ 0.0f, 1.0f, 0.0f,		0,3},	//���_3
		{ 0.0f, 0.0f, 0.0f,		0,2},	//���_4	
	};

	D3D11_BUFFER_DESC bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof( DRAW_POLYGON ) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = vertices;
	if( FAILED( m_pDevice->CreateBuffer( &bd, &InitData, &m_pVertexBuffer ) ) )
		return ;

	//�C���f�b�N�X�o�b�t�@�쐬
	unsigned short hIndexData[4] = 
	{
		0,1,2,3,
	};

	D3D11_BUFFER_DESC hBufferDesc;
	hBufferDesc.ByteWidth = sizeof(hIndexData);
	hBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	hBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	hBufferDesc.CPUAccessFlags = 0;
	hBufferDesc.MiscFlags = 0;
	hBufferDesc.StructureByteStride = sizeof(unsigned short);

	D3D11_SUBRESOURCE_DATA hSubResourceData;
	hSubResourceData.pSysMem = hIndexData;
	hSubResourceData.SysMemPitch = 0;
	hSubResourceData.SysMemSlicePitch = 0;

	//���̃C���f�b�N�X�o�b�t�@���쐬
	m_pDevice->CreateBuffer(&hBufferDesc, &hSubResourceData, &m_pIndexBuffer);

	//�R���X�^���g�o�b�t�@�[�쐬 �V�F�[�_�Ƀf�[�^�󂯓n���p
	D3D11_BUFFER_DESC cb;
	cb.BindFlags			=D3D11_BIND_CONSTANT_BUFFER;
	cb.ByteWidth			=sizeof( DRAW_2D_TEX );
	cb.CPUAccessFlags		=D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags			=0;
	cb.StructureByteStride	=0;
	cb.Usage				=D3D11_USAGE_DYNAMIC;
	if( FAILED(m_pDevice->CreateBuffer( &cb,NULL,&m_pConstantBuffer)))
	{
		return ;
	}

	//�e�N�X�`���[�p�T���v���[�쐬
	D3D11_SAMPLER_DESC SamDesc;
	ZeroMemory(&SamDesc,sizeof(D3D11_SAMPLER_DESC));

	SamDesc.Filter   = D3D11_FILTER_ANISOTROPIC;
    SamDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.BorderColor[0] = 0.0f;
	SamDesc.BorderColor[1] = 0.0f;
	SamDesc.BorderColor[2] = 0.0f;
	SamDesc.BorderColor[3] = 0.0f;
	SamDesc.MipLODBias = 0.0f;
	SamDesc.MaxAnisotropy = 2;
	SamDesc.MinLOD = 0.0f;
	SamDesc.MaxLOD = D3D11_FLOAT32_MAX;
	SamDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    m_pDevice->CreateSamplerState( &SamDesc, &m_pSampleLinear);
}

//�e�N�X�`�����[�h
void  CDrawTexture::LoadImage(wchar_t* name,int id,TEX_SIZE hw)
{
	if( 0  > id) 
		return ; 
	
	if(m_img_max < id) 
		return ; 
	
	if(vec_tex_data[id]->GetTexData()!=nullptr)
	{
		vec_tex_data[id].reset(new C_TEX_DATA());
	}

	//�e�N�X�`���[�쐬
	ID3D11ShaderResourceView* tex;
	DirectX::CreateWICTextureFromFile(m_pDevice, m_pDeviceContext, name, nullptr, &tex, 0U);
	
	//�傫���擾
	float h,w;
	GetLoadImageFileSizeHW(name, &w, &h);
	vec_tex_data[id]->SetTexData(tex);
	vec_tex_data[id]->SetTexSize(w, h);

	return ;
}

//�C���[�W���j��
void  CDrawTexture::DeleteImage()
{
	//�e�N�X�`���������̃��Z�b�g
	for(int i=0; i<m_img_max;i++)
	{
		vec_tex_data[i].reset(new C_TEX_DATA());
	}
}

//�`��p�I�u�W�F�N�g�j��
void  CDrawTexture::DeleteDrawTexture()
{
	DeleteImage();
	//�x�N�^�[���j��
	vec_tex_data.clear();
	vec_tex_data.shrink_to_fit();

	//�\���f�[�^�j��
	SAFE_RELEASE(m_pConstantBuffer);
	SAFE_RELEASE(m_pVertexShader);		
	SAFE_RELEASE(m_pPixelShader);	
	SAFE_RELEASE(m_pSampleLinear);
	SAFE_RELEASE(m_pVertexLayout);
	SAFE_RELEASE(m_pVertexBuffer);
	SAFE_RELEASE(m_pIndexBuffer);
}