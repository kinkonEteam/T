
//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)


//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneSummary.h"
#include"GameHead.h"



//�������\���b�h
void CSceneSummary::InitScene()
{
	//���炷���pBGM
	Audio::LoadAudio(0, L"���炷��.wav", BACK_MUSIC);		

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//BGM�{�����[����������
	float Volume = Audio::VolumeMaster(-0.99f);

	//���y�X�^�[�g
	Audio::Start(0);

	Font::SetStrTex(L"�ނ����ނ����A����Ƃ���ɁA����������Ƃ��΂����񂪏Z��ł��܂����B");
	Font::SetStrTex(L"����������͎R�֎Ŋ���ɁA���΂�����͐�֐���ɍs���܂���");

	//���炷���I�u�W�F�N�g
//	CObjSummary*obj = new CObjSummary();
//	Objs::InsertObj(obj, OBJ_SUMMARY, 10);

	//�e�L�X�g�쐬
	CObjSummary* summary = new CObjSummary();
	Objs::InsertObj(summary, OBJ_SUMMARY, 20);
}

//���s�����\�b�h
void CSceneSummary::Scene()
{

	CObjSummary* summary = (CObjSummary*)Objs::GetObj(OBJ_SUMMARY);
	if (summary == nullptr)
	{
		Scene::SetScene(new CScenefloor1());
	}
}