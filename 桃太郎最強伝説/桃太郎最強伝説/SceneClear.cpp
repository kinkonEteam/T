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

		//�N���A�I�u�W�F�N�g
		CObjClear*obj = new CObjClear();
		Objs::InsertObj(obj, OBJ_CLEAR, 10);

		//�O���O���t�B�b�N��ǂݍ���19�Ԃɓo�^(512�~512�s�N�Z��)
		Draw::LoadImage(L"�Q�[���N���A.png", 19, TEX_SIZE_512);

		Audio::LoadAudio(1, L"�G���f�B���O.wav", BACK_MUSIC);

		Audio::Start(1);
}

//���s�����\�b�h
void CSceneClear::Scene()
{

}