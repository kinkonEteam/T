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
#include"SceneScore.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneScore::CSceneScore()
{

}

//�f�X�g���N�^
CSceneScore::~CSceneScore()
{

}


//���������\�b�h
void CSceneScore::InitScene()
{
	
	//�X�R�A�I�u�W�F�N�g�쐬
	CObjScore* obj = new CObjScore();
	Objs::InsertObj(obj, OBJ_SCORE, 10);

}

//���s�����\�b�h
void CSceneScore::Scene()
{

}