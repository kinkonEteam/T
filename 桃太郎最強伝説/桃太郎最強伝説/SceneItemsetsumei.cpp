//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneItemsetsumei.h"
#include"GameHead.h"



//�Q�[�����C�����������\�b�h
void CSceneItemsetsumei::InitScene()
{
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjItemsetsumei* obj = new CObjItemsetsumei(); //�A�C�e�������I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_ITEMSETSUMEI, 10);    //�A�C�e�������o�^
	
}

//�Q�[�����C�����s�����\�b�h
void CSceneItemsetsumei::Scene()
{

}