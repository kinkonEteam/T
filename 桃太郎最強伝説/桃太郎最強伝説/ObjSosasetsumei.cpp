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

	//D�������ă|�[�Y�Ɉڍs���� 
	if (Input::GetVKey('D') == true)
	{
		Scene::SetScene(new CScenePose());
	}
	else {}
}

//�h���[
void CObjSosasetsumei::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�������", 300, 80, 50, c);
	Font::StrDraw(L"��������:�ړ�", 250, 150, 30, c);
	Font::StrDraw(L"A:���U��", 250, 200, 30, c);
	Font::StrDraw(L"F:", 250, 250, 30, c);
	Font::StrDraw(L"D:�߂�", 250, 300, 30, c);

}
