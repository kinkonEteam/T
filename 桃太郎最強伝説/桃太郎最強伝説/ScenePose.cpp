//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"ScenePose.h"
#include"GameHead.h"



//�Q�[�����C�����������\�b�h
void CScenePose::InitScene()
{
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjPose* obj = new CObjPose();       //�|�[�Y�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_POSE, 10);    //�|�[�Y�I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CScenePose::Scene()
{

}