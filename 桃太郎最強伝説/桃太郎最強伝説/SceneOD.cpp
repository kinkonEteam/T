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
#include"SceneOD.h"
#include"GameHead.h"



//���������\�b�h
void CSceneOD::InitScene()
{
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjOD* obj = new CObjOD();//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_OD, 10);    //��l���I�u�W�F�N�g�o�^

	//�O���O���t�B�b�N��ǂݍ���30�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"��������y�C���g.png", 30, TEX_SIZE_512);

	
}

//���s�����\�b�h
void CSceneOD::Scene()
{

}