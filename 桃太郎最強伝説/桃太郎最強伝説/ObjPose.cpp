//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjPose.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjPose::Init()
{
	m_Af = false;
	
}

//�A�N�V����
void  CObjPose::Action()
{
	if (Input::GetVKey('Z') == true)
	{
		this->SetStatus(false);	//���g�ɍ폜���߂��o��			

	}
	if (Input::GetVKey('X') == true)
	{
		Scene::SetScene(new CSceneTitle());
	}
			
	
}

//�h���[
void  CObjPose::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�^�C�g���ɖ߂�܂���?", 200, 120, 45, c);
	Font::StrDraw(L"������(Z)", 450, 300, 30, c);
	Font::StrDraw(L"�͂�(X)", 250, 300, 30, c);
	


}
