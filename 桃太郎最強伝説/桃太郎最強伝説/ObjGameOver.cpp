//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
/*#include"GameL\UserData.h" 
#include "GameL\DrawFont.h"*/

#include"GameHead.h"
#include"ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[���^�C�g���Ɉڍs����
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
void CObjGameOver::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//�`��
	Draw::Draw(18, &src, &dst, c, 0.0f);
	Font::StrDraw(L"GAME OVER", 300, 250, 64, c);

	//�X�R�A�̕`��
	/*float se[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"Score:%d", ((UserData*)Save::GetData())->m_point);//�X�R�A���Ƃ��āH
	Font::StrDraw(str, 630, 10, 20, se); //������ŉ�ʂɕ`�悷��ʒu�╶���̃T�C�Y��ς���*/

}
