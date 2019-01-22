//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjOD.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjOD::Init()
{
	m_Af = false;
}

//�A�N�V����
void CObjOD::Action()
{


	Audio::LoadAudio(0, L"ButtonSE.wav", EFFECT);	//�R�}���hSE

	//D�������ă|�[�Y�Ɉڍs���� 
	if (Input::GetVKey('H') == true)
	{
		//�R�}���h�pSE��炷
		Audio::Start(0);
		Sleep(100);
		
	}
	else {}
	//�G���^�[�L�[�������ăV�[���F���C���ڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_f == true)
		{
			Scene::SetScene(new CScenefloor1());
			m_key_f = false;
		}
	}
	else
	{
		m_key_f = true;
	}

}


//�h���[
void CObjOD::Draw()
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
	Draw::Draw(40, &src, &dst, c, 0.0f);

	
}
