//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)


//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"ScecneClear.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//�������\���b�h
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"�Q�[���N���A�B");
		Font::SetStrTex(L"��`�������܂ꂽ�c");

		//�N���A�I�u�W�F�N�g
		CObjClear*obj = new CObjClear();
		Objs::InsertObj(obj, OBJ_CLEAR, 10);

		Audio::LoadAudio(0, L"BossBGM.wav", BACK_MUSIC);

		//�{�����[����1.0�ɖ߂�
		float v = Audio::VolumeMaster(0);
		v = Audio::VolumeMaster((1.0 - v));

		Audio::Start(0);
}

//���s�����\�b�h
void CSceneClear::Scene()
{

}