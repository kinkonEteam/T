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
#include"Scenefloor5.h"
#include"GameHead.h"

//�R���X�g���N�^
CScenefloor5::CScenefloor5()
{
	
}

//�f�X�g���N�^
CScenefloor5::~CScenefloor5()
{

}

//���������\�b�h
void CScenefloor5::InitScene()
{
	//�{�X��pBGM�ǂݍ���
	Audio::LoadAudio(1, L"BossBGM.wav", BACK_MUSIC);

	Audio::Start(1);//�{�X�pBGM���X�^�[�g

	//�O���f�[�^�̓ǂݍ��݁i�K�w5���j
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;			//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"Book5.csv", &size);//�O���f�[�^�ǂݍ���

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

	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"�}�b�v�`�b�v.png", 0, TEX_SIZE_141_47);

	//�K�w5�I�u�W�F�N�g�쐬
	CObjMap5* objb = new CObjMap5(map);
	Objs::InsertObj(objb, OBJ_MAP5, 9);
}

//���s�����\�b�h
void CScenefloor5::Scene()
{

}