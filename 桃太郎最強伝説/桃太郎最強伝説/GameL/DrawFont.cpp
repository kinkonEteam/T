#include <wchar.h>
#include <locale.h>
#include "DrawFont.h"
#include "DrawTexture.h"	//�Q�c�`���DrawTexture�Ɉˑ�����

using namespace GameL;

#define SAFE_RELEASE(p)      { if (p) { (p)->Release();    (p)=nullptr;  }	}
#define SAFE_RESET(p)		 { if (p) { (p).reset(nullptr);				 }  }
//�����̉𑜓x
#define FONT_SIZE	(64)
#define FONT_SHIFT	(8)

HFONT							CDrawFont::m_hFont;
HDC								CDrawFont::m_hdc;
HFONT							CDrawFont::m_oldFont;
TEXTMETRIC						CDrawFont::m_TM;
ID3D11Device*					CDrawFont::m_pDevice;
ID3D11DeviceContext*			CDrawFont::m_pDeviceContext;
D3D11_TEXTURE2D_DESC			CDrawFont::m_desc;
list< unique_ptr<CFontCharTex>>*CDrawFont::m_ListData;		//�������X�g


// CFontCharTex���\�b�h	---------------------------
 CFontCharTex::CFontCharTex()
{
	m_wc=L'\0';
	m_pTexture=nullptr;
	m_pTexResView=nullptr;
}

 CFontCharTex::~CFontCharTex()
{
	SAFE_RELEASE(m_pTexture) ;
	SAFE_RELEASE(m_pTexResView ); 
}
//------------------------------------------------

//�R���X�g���N�^
void CDrawFont::Init(ID3D11Device* p_device,ID3D11DeviceContext* p_device_context)
{
	setlocale( LC_CTYPE, "jpn" );

	m_ListData= new list< unique_ptr<CFontCharTex>>;

	//�g�p�f�o�C�X�o�^
	m_pDevice		 = p_device;
	m_pDeviceContext = p_device_context;
	// �t�H���g���
	HFONT hFont = CreateFont(
		FONT_SIZE,
		0,0,0,0,
		FALSE,FALSE,FALSE,
		SHIFTJIS_CHARSET,
		OUT_TT_ONLY_PRECIS,
		CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		L"�l�r �S�V�b�N"	//�g�p�t�H���g
		);
	m_hdc = GetDC(NULL);
	m_oldFont = (HFONT)SelectObject(m_hdc, hFont);
	GetTextMetrics( m_hdc, &m_TM );

	m_hFont=hFont;
}

//�N���X�f���[�g
void CDrawFont::Delete()
{
	//���X�g�j��
	ListDelete();
	// �I�u�W�F�N�g�̊J��
	DeleteObject(m_oldFont);
	DeleteObject(m_hFont);
	ReleaseDC(NULL,m_hdc);
	delete m_ListData;
}

//�g�p�����̎��O�o�^���\�b�h
void CDrawFont:: SetStrTex(wchar_t* init_str)
{
	//�����̏����o�^
	for(unsigned int i=0 ; i< wcslen(init_str) ; i++) 
	{
		bool hit=false;
		//���X�g���猟��
		for(auto itr = m_ListData->begin() ; itr != m_ListData->end() ; itr++ )
		{
			if((*itr)->m_wc == init_str[i] )
			{
				hit=true;
				break;
			}
		}

		//���X�g�ɕ�����o�^
		if(hit==false)
		{
			SetChar(init_str[i]);
		}
	}
}

//���X�g�����폜���\�b�h
void CDrawFont::ListDelete()
{
	m_ListData->clear(); 
}

//�t�H���g���X�g�ǉ����\�b�h
list< unique_ptr<CFontCharTex>>::iterator CDrawFont::SetChar(wchar_t c)
{
	//�����t�H���g���
	BYTE* ptr;
	DWORD size;
	GLYPHMETRICS GM;
	CONST MAT2 Mat = {{0,1},{0,0},{0,0},{0,1}};

	//�����쐬�p
	UINT code = 0;
	int  s=FONT_SHIFT;

	//�e�N�X�`������
	D3D11_MAPPED_SUBRESOURCE mapped;
	BYTE* pBits;

	//�t�H���g�o�^�p���I�������쐬
	unique_ptr<CFontCharTex> font_tex(new CFontCharTex());
	
	//���ʕ����R�[�h�o�^
	memcpy(&font_tex->m_wc,&c,sizeof(wchar_t));
	code=font_tex->m_wc;

	//��e�N�X�`���쐬
	memset( &m_desc, 0, sizeof( m_desc ) );
	m_desc.MipLevels = 1;
	m_desc.ArraySize = 1;
	m_desc.Format    = DXGI_FORMAT_R8G8B8A8_UNORM;
	m_desc.SampleDesc.Count= 1;						// �T���v�����O��1�s�N�Z���̂�
	m_desc.Usage     = D3D11_USAGE_DYNAMIC;			// CPU�������݉\
	m_desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;	// �V�F�[�_���\�[�X
	m_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;	// CPU���珑�����݃A�N�Z�X��
	m_desc.Height    = FONT_SIZE;					// �c�̃T�C�Y
	m_desc.Width	 = FONT_SIZE;					// ���̃T�C�Y
	
	// �r�b�g�}�b�v�擾
	size = GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, 0, NULL, &Mat);
	ptr  = new BYTE[size];
	GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, size, ptr, &Mat);

	//�e�N�X�`���N���G�C�g
	m_pDevice->CreateTexture2D( &m_desc, 0, &font_tex->m_pTexture  );

	// �e�N�X�`�������擾����
	D3D11_TEXTURE2D_DESC texDesc;
	font_tex->m_pTexture->GetDesc( &texDesc );

	// ShaderResourceView�̏����쐬����
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory( &srvDesc, sizeof(srvDesc) );
	srvDesc.Format = texDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = texDesc.MipLevels;
	m_pDevice->CreateShaderResourceView( font_tex->m_pTexture,&srvDesc, &font_tex->m_pTexResView);

	//�e�N�X�`�����b�N
	m_pDeviceContext->Map(font_tex->m_pTexture,0,D3D11_MAP_WRITE_DISCARD,0,&mapped);
	pBits = (BYTE*)mapped.pData;

	// �t�H���g���̏�������
	int iOfs_x = GM.gmptGlyphOrigin.x;	
	int iOfs_y = m_TM.tmAscent - GM.gmptGlyphOrigin.y;	// iOfs_x, iOfs_y : �����o���ʒu(����)
	int iBmp_w = GM.gmBlackBoxX + (4-(GM.gmBlackBoxX%4))%4;	
	int iBmp_h = GM.gmBlackBoxY;						// iBmp_w, iBmp_h : �t�H���g�r�b�g�}�b�v�̕���
	int Level = 17;										// Level : ���l�̒i�K (GGO_GRAY4_BITMAP�Ȃ̂�17�i�K)
	DWORD Alpha, Color;

	memset(pBits,0x00,sizeof(DWORD)*FONT_SIZE*FONT_SIZE);
	//FillMemory(pBits , sizeof(pBits), 0);
	for(int y=iOfs_y; y<iOfs_y+iBmp_h; y++)
	{
		for(unsigned int x=iOfs_x; x<iOfs_x+GM.gmBlackBoxX; x++)
		{
			Alpha =( 255 * ptr[ x - iOfs_x + iBmp_w * ( y - iOfs_y ) ] ) / ( Level - 1);
			Color = 0x00ffffff | (Alpha<<24);
			memcpy((BYTE*)pBits + (y<<s) + (x<<2), &Color, sizeof(DWORD));
		}
	}

	//�A�����b�N
	m_pDeviceContext->Unmap(font_tex->m_pTexture,D3D11CalcSubresource( 0, 0, 1 ));

	//�����r�b�g�}�b�v�f�[�^�폜
	delete[] ptr;

	//���X�g�o�^
	m_ListData->push_front(move(font_tex));
	
	return m_ListData->begin(); 
}


//������`�惁�\�b�h
void CDrawFont::StrDraw(wchar_t* str,float x,float y,float size,float color[4])
{
	list<unique_ptr<CFontCharTex>>::iterator itr;	//�o�^���������p
	bool hit;										//�o�^�q�b�g���Ă��邩�`�F�b�N

	//������\��
	float j=0.0f;
	for(unsigned int i=0 ; i<  wcslen(str) ; i++) 
	{
		hit=false;
		//���X�g���猟��
		for(auto itr_i = m_ListData->begin() ; itr_i != m_ListData->end() ; itr_i++ )
		{
			if((*itr_i)->m_wc == str[i] )
			{
				hit=true;
				itr=itr_i;
				break;
			}
		}
				
		//���X�g�ɕ�����o�^
		if(hit==false)
		{
			itr=SetChar(str[i]);
		}
		
		//�`��
		Draw::DrawStr((*itr)->m_pTexResView,x+j,y,size,color);

		//�啶�����������Ŏ��̕`��ʒu��ς���
		char mc[3];
		int len;
		wctomb_s(&len,mc,sizeof(wchar_t),(*itr)->m_wc); 
		if( len==1)
		{
			j+=size/2.0f;
		}
		else
		{
			j+=size;
		}

	}

}