//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjKeyUse.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void ObjKeyUse::Init()
{

}
//�A�N�V����
void ObjKeyUse::Action()
{

}
//�h���[
void ObjKeyUse::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	
	Font::StrDraw(L"'H'�w���v 'M'���j���[", 10, 560, 25, c);
}
