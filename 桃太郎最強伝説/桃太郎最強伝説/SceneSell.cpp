//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"
#include "GameL\SceneObjManager.h"
#include"GameL\UserData.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneSell.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneSell::CSceneSell()
{
	//�O���O���t�B�b�N��ǂݍ���29�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L".png", 29, TEX_SIZE_512);
}

//�f�X�g���N�^
CSceneSell::~CSceneSell()
{

}

//�Q�[�����C�����������\�b�h
void CSceneSell::InitScene()
{
	
}

//�Q�[�����C�����s�����\�b�h
void CSceneSell::Scene()
{

}