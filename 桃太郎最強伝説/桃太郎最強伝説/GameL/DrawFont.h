#pragma once

//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)  

#include <memory>
#include <list>
#include <algorithm>
#include <D3D11.h> 
#include <d3dCompiler.h>

using namespace std;

namespace GameL
{

	//�t�H���g�ꕶ���̃e�N�X�`�����
	class CFontCharTex
	{
		friend class CDrawFont;
		public:
			CFontCharTex();
			~CFontCharTex();
		private:
			wchar_t					  m_wc;				//�g�p����Ă��镶��(�����p)
			ID3D11Texture2D*		  m_pTexture;		//�����̃e�N�X�`�����
			ID3D11ShaderResourceView* m_pTexResView;	//�e�N�X�`�����V�F�[�_�ɑ�������
	};


	//�t�H���g�\���N���X
	typedef class CDrawFont
	{
		public:
			static void Init(ID3D11Device* p_device,ID3D11DeviceContext* p_device_context);	//������
			static void Delete();														//�N���X�폜
			static void SetStrTex(wchar_t* init_str);									//���O�\�񕶎����X�g�쐬
			static void ListDelete();													//�������X�g�폜
			static void StrDraw(wchar_t* str,float x,float y,float size,float color[4]);	//������`��

		private:
			static list< unique_ptr<CFontCharTex>>::iterator SetChar(wchar_t c);		//�t�H���g���X�g�ǉ����\�b�h
		
			static HFONT		m_hFont;
			static HDC			m_hdc;
			static HFONT		m_oldFont;
			static TEXTMETRIC	m_TM;
 		
			static ID3D11Device*		m_pDevice;
			static ID3D11DeviceContext* m_pDeviceContext;
			static D3D11_TEXTURE2D_DESC m_desc;

			//�t�H���g�����i�[���X�g
			static list< unique_ptr<CFontCharTex>>*	m_ListData;		//�������X�g
	}Font;

};