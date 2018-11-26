//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjClear::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjClear::Action()
{
	//�G���^�[�L�[�������ăV�[���F�^�C�g���ڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//�h���[
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�Q�[���N���A", 224, 250, 16, c);
	Font::StrDraw(L"��`�������܂ꂽ�c", 230, 270, 16, c);

	Font::StrDraw(L"�߂ł����߂ł���", 340, 300, 64, c);
}