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
	
}

//�f�X�g���N�^
CSceneSell::~CSceneSell()
{

}

//�Q�[�����C�����������\�b�h
void CSceneSell::InitScene()
{
	ObjSell*obj = new ObjSell();//�����I�u�W�F
	Objs::InsertObj(obj, OBJ_SELL, 10);
}

//�Q�[�����C�����s�����\�b�h
void CSceneSell::Scene()
{
	ObjSell*sell = (ObjSell*)Objs::GetObj(OBJ_SELL);
	if (sell == nullptr)
		Scene::SetScene(new CSceneClear());
}