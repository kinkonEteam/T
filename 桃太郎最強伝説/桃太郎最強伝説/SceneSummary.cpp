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

	//BGM�{�����[����0.4�����A����1/10�̉��ʂɂ���B
	float Volume = Audio::VolumeMaster(-0.4f);

	//���y�X�^�[�g
	Audio::Start(0);

	Font::SetStrTex(L"�ނ����ނ����A����Ƃ���ɁA����������Ƃ��΂����񂪏Z��ł��܂����B");
	Font::SetStrTex(L"����������͎R�֎Ŋ���ɁA���΂�����͐�֐���ɍs���܂���");

	//���炷���I�u�W�F�N�g
	CObjSummary*obj = new CObjSummary();
	Objs::InsertObj(obj, OBJ_SUMMARY, 10);
}

//���s�����\�b�h
void CSceneSummary::Scene()
{

}