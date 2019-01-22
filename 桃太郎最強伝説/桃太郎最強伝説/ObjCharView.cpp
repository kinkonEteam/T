//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\UserData.h"

#include"GameHead.h"
#include"ObjCharView.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void ObjCharView::Init()
{
	count = c;
	sec = s;
	min = m;
}
//�A�N�V����
void ObjCharView::Action()
{
	CObjTalk* talk = (CObjTalk*)Objs::GetObj(OBJ_TALK);
	if (talk != nullptr){}
	else
		count++;//�J�E���g
	

	if (count == 60)
	{
		sec++;		//1���Z
		count = 0;	//�J�E���g���Z�b�g
	}
	if (sec == 60)
	{
		min++;		//1���Z
		sec = 0;	//�b���Z�b�g
	}
}
//�h���[
void ObjCharView::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	

	wchar_t str[STR_MAX];

	swprintf_s(str, L"%d�F", min);
	if(min < 10)
		swprintf_s(str, L"0%d�F", min);
	Font::StrDraw(str, 650, 20, SCORE_FONT_SIZE, c);
	swprintf_s(str, L"%d�F", sec);
	if (sec < 10)
		swprintf_s(str, L"0%d�F", sec);
	Font::StrDraw(str, 700, 20, SCORE_FONT_SIZE, c);
	swprintf_s(str, L"%d"  , count);
	if (count < 10)
		swprintf_s(str, L"0%d", count);
	Font::StrDraw(str, 750, 20, SCORE_FONT_SIZE, c);
	
	
	
	

	CObjTalk* obj = (CObjTalk*)Objs::GetObj(OBJ_TALK);//�C�x���g�擾
	if (obj == nullptr)//���݂��Ȃ��ꍇ�̂ݕ\��
	{
		Font::StrDraw(L"�uH�v�������", 10, 560, 25, c);
		Font::StrDraw(L"�ui�v������", 200, 560, 25, c);
	}
}
