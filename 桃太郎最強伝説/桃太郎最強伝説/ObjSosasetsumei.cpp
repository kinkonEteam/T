//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

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

	//Z�������ă|�[�Y�Ɉڍs����
	if (Input::GetVKey('Z') == true)
	{
		Scene::SetScene(new CScenePose());
	}
	else {}
}

//�h���[
void CObjSosasetsumei::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"���������ňړ���", 300, 150, 30, c);
	Font::StrDraw(L"A�Ō��U����", 300, 200, 30, c);
	Font::StrDraw(L"S��賍U����", 300, 250, 30, c);
	Font::StrDraw(L"�i賓����\�j", 300, 300, 30, c);
	Font::StrDraw(L"M�Ŗ߂�񂶂�", 300, 350, 30, c);

}
