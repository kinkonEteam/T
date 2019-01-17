//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneTitle.h"
#include"GameHead.h"

//�A�C�e���������p
extern int item_list[7];

//�Q�[�����C�����������\�b�h
void CSceneTitle::InitScene()
{
	//�A�C�e��������������
	for (int i = 0; i < 7; i++)
	{
		item_list[i] = 0;
		
	}
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	hero->SetDATA();//��l��HP�Ƃ����f�[�^���Z�b�g�֐�

	//�O���O���t�B�b�N��ǂݍ���19�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�Q�[���^�C�g��.png", 20, TEX_SIZE_512);

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* obj = new CObjTitle();       //�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_TITLE, 10);    //��l���I�u�W�F�N�g�o�^

	//BGM�̓ǂݍ���
	Audio::LoadAudio(0, L"�^�C�g��.wav", BACK_MUSIC);		//�^�C�g���pBGM

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//BGM�{�����[����������
	float Volume = Audio::VolumeMaster(-0.95f);
	//���y�X�^�[�g
	Audio::Start(0);
}

//�Q�[�����C�����s�����\�b�h
void CSceneTitle::Scene()
{

}