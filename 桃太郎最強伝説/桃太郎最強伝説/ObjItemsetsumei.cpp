//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjItemsetsumei.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjItemsetsumei::Init()
{


}

//�A�N�V����
void CObjItemsetsumei::Action()
{

	//D�������ă|�[�Y�Ɉڍs���� 
	if (Input::GetVKey('D') == true)
	{
		Scene::SetScene(new CScenePose());
	}
	else {}
}

//�h���[
void CObjItemsetsumei::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	

}
