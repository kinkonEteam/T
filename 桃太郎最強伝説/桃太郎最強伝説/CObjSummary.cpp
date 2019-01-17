//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "CObjSummary.h"
#include "GameHead.h"

void CObjSummary::Init()
{
	m_f = true;		//�����l
	m_page = 0;
	m_key_f = false;

	//�O���O���t�B�b�N��ǂݍ���9�Ԃɓo�^(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);

	//�g�[�N�I�u�W�F�N�g�쐬
	CObjTalk* talk = new CObjTalk(0, 18);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(talk, OBJ_TALK, 4);		//�D��x4(��)�ɐݒ肵�o�^
											//�R�����g�̏�ɍ����摜�\��
	CObjTalk* black = new CObjTalk(1, 18);	//�I�u�W�F�N�g�쐬
	Objs::InsertObj(black, OBJ_TALK, 20);	//�D��x5(��)�ɐݒ肵�o�^
}

void CObjSummary::Action()
{

	//���͔���A�������ςȂ�����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_f == true)
		{
			m_page += 1;
			m_f = false;
		}
	}
	else//�����Ă���ꍇ
		m_f = true;
}

void CObjSummary::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//���O��ENTER�L�[	 (X), (y),(size),color
	Font::StrDraw(L"", 77, 390, 25, c);
	Font::StrDraw(L"�A�N�V�����L�[�E�E�E", 625, 560, 15, c);

	if (m_page == 1) {						//1�y�[�W
		Font::StrDraw(L"�ނ����ނ����A����Ƃ���ɁA�����������", 50, 440, 30, c);
		Font::StrDraw(L"���΂����񂪏Z��ł��܂����B", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 2) {					//2�y�[�W
		Font::StrDraw(L"������A�����̂悤�ɂ���������͎R�֎Ŋ���ɁA", 50, 440, 30, c);
		Font::StrDraw(L"���΂�����͐�֐���ɍs���܂����B", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 3) {					//3�y�[�W
		Font::StrDraw(L"���΂����񂪐�֐�������Ă���ƁA", 50, 440, 30, c);
		Font::StrDraw(L"��ォ��h���u���R,�h���u���R��", 50, 480, 30, c);
		Font::StrDraw(L"�傫�ȓ�������Ă��܂����B", 50, 520, 30, c);
	}
	else if (m_page == 4) {					//4�y�[�W
		Font::StrDraw(L"�u����A����͗ǂ����݂₰�ɂȂ��v", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 5) {					//5�y�[�W
		Font::StrDraw(L"��񂾂��΂�����͑傫�ȓ����Ђ낢�����āA", 50, 440, 30, c);
		Font::StrDraw(L"�ƂɎ����A�邱�Ƃɂ��܂����B", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 6) {					//6�y�[�W
		Font::StrDraw(L"�u�����A����͂܂������Ɨ��h�ȓ����v", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 7) {					//7�y�[�W
		Font::StrDraw(L"��񂾂��������񂪑�����l�ŐH�ׂ悤��", 50, 440, 30, c);
		Font::StrDraw(L"����؂��Ă݂�ƁA", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 8) {					//8�y�[�W
		Font::StrDraw(L"�u�����Ⴀ�A�����Ⴀ�v", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 9) {					//9�y�[�W
		Font::StrDraw(L"�Ȃ�ƁA�����猳�C�Ȓj�̎q��", 50, 440, 30, c);
		Font::StrDraw(L"��яo���Ă��܂����B", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 10) {					//10�y�[�W
		Font::StrDraw(L"�u����͂����Ɛ_���܂������������q�ɂ������Ȃ��v", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 11) {					//11�y�[�W
		Font::StrDraw(L"�q�ǂ��̂��Ȃ����������������", 50, 440, 30, c);
		Font::StrDraw(L"���΂�����͑��тł��B", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 12) {					//12�y�[�W
		Font::StrDraw(L"��l�͒j�̎q�𓍂��琶�܂ꂽ���Ƃ���", 50, 440, 30, c);
		Font::StrDraw(L"�����Y�Ɩ��t���A�厖�Ɉ�Ă܂����B", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 13) {					//13�y�[�W
		Font::StrDraw(L"�����Y�͂��������������A", 50, 440, 30, c);
		Font::StrDraw(L"�ƂĂ������j�̎q�ɂȂ�܂����B", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 14) {					//14�y�[�W
		Font::StrDraw(L"������A�����Y�͌����܂����B", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 15) {					//15�y�[�W
		Font::StrDraw(L"�u�S�����֍s���āA���������������S������", 50, 440, 30, c);
		Font::StrDraw(L"�@�ގ����Ă��܂��v", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 16) {					//16�y�[�W
		Font::StrDraw(L"������̎��A���΂�����͂������󂢂Ă�", 50, 440, 30, c);
		Font::StrDraw(L"�����Ȃ�����Ƃ��т��񂲂��������Ă���܂����B", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 17) {					//17�y�[�W
		Font::StrDraw(L"�u���肪�Ƃ��A���΂����񂨂�������B", 50, 440, 30, c);
		Font::StrDraw(L"�@�ł͍s���Ă��܂��v", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 18) {					//18�y�[�W
		Font::StrDraw(L"�������āA�����Y�ɂ��S�ގ��̗���", 50, 440, 30, c);
		Font::StrDraw(L"�����J�����̂ł����B", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else
		this->SetStatus(false);			//�I�u�W�F�N�g�폜
}