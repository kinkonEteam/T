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
	count = 0;
	sec = 0;
	min = 0;
}
//�A�N�V����
void ObjCharView::Action()
{
	count++;//���1���Z

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

	swprintf_s(str, L"%d�F%d", min, sec);//���̂܂ܓo�^

	if ((sec < 10) || (min < 10)) {//�b�����������A�񌅂łȂ��ꍇ�̂ݏ㏑��
		swprintf_s(str, L"%d�F0%d", min, sec);
		if (min < 10) {					//��
			swprintf_s(str, L"0%d�F%d", min, sec);
		}
		if ((sec < 10) && (min < 10)) {	//�����������ꍇ
			swprintf_s(str, L"0%d�F0%d", min, sec);
		}
	}
	
	Font::StrDraw(str, 100, 100, SCORE_FONT_SIZE, c);
	
	Font::StrDraw(L"'H'�w���v 'M'���j���[", 10, 560, 25, c);
}
