//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjPose.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjPose::Init()
{

	
}

//�A�N�V����
void  CObjPose::Action()
{
	//Z�������ăQ�[����ʂɈڍs����
	if (Input::GetVKey('Z') == true)
	{
		Scene::SetScene(new CScenefloor1());
	}
	else{}

	//X�������đ��������ʂɈڍs����
	if (Input::GetVKey('X') == true)
	{
		Scene::SetScene(new CSceneSosasetsumei());
	}
	else{}

	//C�������ăA�C�e��������ʂɈڍs����
	if (Input::GetVKey('C') == true)
	{
		Scene::SetScene(new CSceneItemsetsumei());
	}
	else{}

	//V��������Title�Ɉڍs����
	if (Input::GetVKey('V') == true)
	{
		Scene::SetScene(new CSceneTitle());
	}
	else{}
	
}

//�h���[
void  CObjPose::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�|�[�Y���j���[", 350, 120, 45, c);
	Font::StrDraw(L"�Q�[���ɖ߂�(Z)", 300, 200, 30, c);
	Font::StrDraw(L"�������(X)", 300, 250, 30, c);
	Font::StrDraw(L"�A�C�e������(C)", 300, 300, 30, c);
	Font::StrDraw(L"�^�C�g���ɖ߂�(V)", 300, 350, 30, c);
}
