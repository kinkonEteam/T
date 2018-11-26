#pragma once

//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)  

#include <memory>
#include <vector>
#include <algorithm>
#include <D3D11.h> 
#include <d3dCompiler.h>
#include "DirectXTex.h"
#include "WICTextureLoader.h"


using namespace std;

namespace GameL
{
	//�e�N�X�`���C���[�W�T�C�Y�@�W����-�ݒ�
	enum TEX_SIZE
	{
		TEX_SIZE_141_47 = 141 * 47,
		TEX_SIZE_151_200 = 151 * 200,
		TEX_SIZE_64   =	  64,
		TEX_SIZE_128  =	 128,
		TEX_SIZE_145_201 =145 * 201,
		TEX_SIZE_256  =	 256,
		TEX_SIZE_512  =	 512,
		TEX_SIZE_1024 =	1024,
	};

	//�Q�c�`���pRECT��FLOAT�^
	struct RECT_F
	{
		float m_top;
		float m_left;
		float m_right;
		float m_bottom;
	};

	//�e�N�X�`���ۑ��p�N���X
	class C_TEX_DATA
	{
		public :
			C_TEX_DATA();
			~C_TEX_DATA();

			ID3D11ShaderResourceView** GetTexData();
			float	GetTexSizeH();
			float	GetTexSizeW();
			void SetTexData(ID3D11ShaderResourceView* tex);
			void SetTexSize(float  size_w,float size_h);
		private:
			ID3D11ShaderResourceView* m_pSRV;
			float 	m_tex_size_w;
			float	m_tex_size_h;
	};

	//�e�N�X�`���ǂݍ��݁E�\���E�폜�N���X
	typedef class CDrawTexture
	{
		public :
			//�`��p�I�u�W�F�N�g�j��
			static void DeleteDrawTexture();
			static void InitDraw(ID3D11Device* p_device,ID3D11DeviceContext* p_device_context,int w,int h,int img_max);	//������
			static void LoadImage(wchar_t* name,int id,TEX_SIZE hw);			//�O���t�B�b�N�ǂݍ��݁@�T�C�Y�͒萔�Ŏw��
			static void DeleteImage();											//�O���t�B�b�N�j��
			static void Draw(int id,RECT_F* src,RECT_F* dst,float col[4],float r); //�o�^�e�N�X�`���`��
			static void DrawStr(ID3D11ShaderResourceView* ptex_res_view,float x,float y,float size,float col[4]);//�����`��
			static void DrawHitBox(float x,float y,float h,float w,float col[4]);//�����蔻��`��

		private:
			static void Set2DDraw();	//�QD�g�p�ݒ�

			//�f�o�C�X
			static ID3D11DeviceContext* m_pDeviceContext;
			static ID3D11Device*		m_pDevice; 

			//�e�N�X�`�����
			static vector<shared_ptr<C_TEX_DATA>> vec_tex_data;

			//�E�B���h�E���
			static int m_width ;
			static int m_height; 

			//�擾�C���[�W�ő吔
			static int m_img_max;

			//�V�F�[�_�֌W
			static ID3D11VertexShader* m_pVertexShader;		//�o�[�e�b�N�X�V�F�[�_�[
			static ID3D11PixelShader*  m_pPixelShader;		//�s�N�Z���V�F�[�_�[
			static ID3D11SamplerState* m_pSampleLinear;		//�e�N�X�`���[�T���v���[
			static ID3D11InputLayout*  m_pVertexLayout;		//���_���̓��C�A�E�g
			//�o�b�t�@
			static ID3D11Buffer* m_pVertexBuffer;			//�Q�c�|���S���p�o�[�e�B�N�X�o�b�t�@
			static ID3D11Buffer* m_pConstantBuffer;			//�A�v�������V�F�[�_�[�˂��� �R���X�^���g�o�b�t�@
			static ID3D11Buffer* m_pIndexBuffer;			//�C���f�b�N�X�o�b�t�@
	}Draw;

};