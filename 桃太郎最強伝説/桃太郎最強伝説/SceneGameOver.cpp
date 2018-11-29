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
#include"SceneGameOver.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//���������\�b�h
void CSceneGameOver::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"GAME OVER");

	Audio::LoadAudio(0, L"GameOverBGM.wav", SOUND_TYPE::BACK_MUSIC);	//�Q�[���I�[�o�[�pBGM

	//�{�����[����1.0�ɖ߂�																	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//BGM�X�^�[�g
	Audio::Start(0);
	Font::SetStrTex(L"GAME OVER");
	//�O���O���t�B�b�N��ǂݍ���18�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�Q�[���I�[�o�[.png", 18, TEX_SIZE_512);
	
	//�Q�[���I�[�o�[�I�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);

}

//���s�����\�b�h
void CSceneGameOver::Scene()
{

}