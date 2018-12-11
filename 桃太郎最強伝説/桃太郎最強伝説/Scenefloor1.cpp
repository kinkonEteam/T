//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
#include"GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"Scenefloor1.h"
#include"GameHead.h"

//�R���X�g���N�^
CScenefloor1::CScenefloor1()
{
	Audio::LoadAudio(0, L"DungeonBGM.wav",SOUND_TYPE::BACK_MUSIC);		//�_���W�����pBGM

	
}

//�f�X�g���N�^
CScenefloor1::~CScenefloor1()
{
	
}

//���������\�b�h
void CScenefloor1::InitScene()
{
	//BGM�̓ǂݍ���
	Audio::LoadAudio(0, L"DungeonBGM.wav", BACK_MUSIC);		//�_���W�����pBGM

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));
	//���y�X�^�[�g
	Audio::Start(0);
	//�O���f�[�^�̓ǂݍ��݁i�K�w1���j
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;			//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"Book1.csv", &size);//�O���f�[�^�ǂݍ���

	unique_ptr<wchar_t>pID;//�A�C�e�����|�C���^�[
	int itemsize;			//�A�C�e�����̑傫��
	pID = Save::ExternalDataOpen(L"ItemData.csv", &itemsize);//�O���f�[�^�ǂݍ���

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

	//�O���t�B�b�N�ǂݍ���
	//�O���O���t�B�b�N��ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�����Y.png", 0, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���1�Ԃɓo�^(141�~47�s�N�Z��)
	Draw::LoadImageW(L"�}�b�v�`�b�v.png", 1, TEX_SIZE_141_47);

	//�O���O���t�B�b�N��ǂݍ���2�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"OTOMO.GIF", 2, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"Sword.png", 3, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���4�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�A�C�e��.png", 4, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���5�Ԃɓo�^(151�~200�s�N�Z��)
	Draw::LoadImage(L"�S���� �S �V��.png", 5, TEX_SIZE_151_200);

	//�O���O���t�B�b�N��ǂݍ���6�Ԃɓo�^(151�~200�s�N�Z��)
	Draw::LoadImage(L"�S���� ���S �V��.png", 6, TEX_SIZE_151_200);

	//�O���O���t�B�b�N��ǂݍ���7�Ԃɓo�^(151�~200�s�N�Z��)
	Draw::LoadImage(L"�S���� �΋S �V��.png", 7, TEX_SIZE_151_200);

	//�O���O���t�B�b�N��ǂݍ���8�Ԃɓo�^(512�s�N�Z��)
	Draw::LoadImage(L"�̗̓Q�[�W�t��.png", 8, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���4�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�Èōŏ�.png", 15, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���4�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�È�+1.png", 16, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���4�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�È�+2.png", 17, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���11�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"���G�t�F�N�g.png", 11, TEX_SIZE_512);



	//�K�w1�I�u�W�F�N�g�쐬
	CObjMap1* objb = new CObjMap1(map);
	Objs::InsertObj(objb, OBJ_MAP1, 1);

	//�Èō쐬				//�Èŉ摜�ԍ�
	//ObjCapture* Y = new ObjCapture(15);
	//Objs::InsertObj(Y, OBJ_CAPTURE, 3);

	//��l���̗̓Q�[�W�I�u�W�F�N�g�쐬
	CObjHeroGauge* objg = new CObjHeroGauge();
	Objs::InsertObj(objg, OBJ_HEROGAUGE, 20);

	//��������쐬
	ObjKeyUse* K = new ObjKeyUse();
	Objs::InsertObj(K, OBJ_KEYUSE, 20);

}

//���s�����\�b�h
void CScenefloor1::Scene()
{

}