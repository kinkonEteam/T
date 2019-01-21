//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"
#include "GameL\SceneObjManager.h"
#include"GameL\UserData.h"
#include "GameL\WinInputs.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"


//�R���X�g���N�^
CSceneMain::CSceneMain()
{
	
}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//�O���f�[�^�̓ǂݍ��݁i�K�w1���j
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;			//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"Book1.csv", &size);//�O���f�[�^�ǂݍ���

	int map[56][56];
	int count = 1;
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			if (w >= 10)
			{
				count += 1;
			}

			count += 2;
		}
	}

	//BGM�ESE�̓ǂݍ���
	
	//Audio::LoadAudio(3, L"���ԃQ�b�g.wav", EFFECT);			//�����𑝂₵�����pSE
	


	//�O���O���t�B�b�N��ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�����Y.png", 0,TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImageW(L"�}�b�v�`�b�v.png", 1, TEX_SIZE_141_47);	//�}�b�v
	
	//�O���O���t�B�b�N��ǂݍ���2�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"OTOMO.GIF", 2, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"Sword.png", 3, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���4�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�A�C�e��.png", 4, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���5�Ԃɓo�^(151*200�s�N�Z��)
	Draw::LoadImage(L"�S���� �S �V��.png", 5, TEX_SIZE_151_200);

	//�O���O���t�B�b�N��ǂݍ���6�Ԃɓo�^(151*200�s�N�Z��)
	Draw::LoadImage(L"�S���� ���S �V��.png", 6, TEX_SIZE_151_200);

	//�O���O���t�B�b�N��ǂݍ���7�Ԃɓo�^(151*200�s�N�Z��)
	Draw::LoadImage(L"�S���� �΋S �V��.png", 7, TEX_SIZE_151_200);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���8�Ԃɓo�^
	Draw::LoadImage(L"�t�@�C�A�{�[��.png", 8, TEX_SIZE_151_200);
	
	//�O���O���t�B�b�N�t�@�C����ǂݍ���9�Ԃɓo�^
	Draw::LoadImage(L"�S���� �ԋS �V��.png", 9, TEX_SIZE_151_200);

	//�O���O���t�B�b�N��ǂݍ���15�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�Èōŏ�.png", 15, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���16�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�È�+1.png", 16, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���17�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�È�+2.png", 17, TEX_SIZE_512);

	


}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}