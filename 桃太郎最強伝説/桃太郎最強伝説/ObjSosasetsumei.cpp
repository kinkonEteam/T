//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjSosasetsumei.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSosasetsumei::Init()
{

}

//�A�N�V����
void CObjSosasetsumei::Action()
{
	Audio::LoadAudio(0, L"ButtonSE.wav", EFFECT);	//�R�}���hSE

	//D�������ă|�[�Y�Ɉڍs���� 
	if (Input::GetVKey('D') == true)
	{
		//�R�}���h�pSE��炷
		Audio::Start(0);
		Sleep(100);
		Scene::SetScene(new CScenePose());
	}
	else {}
}

//�h���[
void CObjSosasetsumei::Draw()
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
	Draw::Draw(30, &src, &dst, c, 0.0f);

	
}
