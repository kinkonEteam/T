//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameHead.h"
#include"ObjSummary.h"

#include <windows.h>


//�g�p����l�[���X�y�[�X
using namespace GameL;
//�C�j�V�����C�Y
void CObjSummary::Init()
{
	m_time = 0;
	m_key_f = false;
	m_y = 0;
	m_ky= 30;
}

//�A�N�V����
void CObjSummary::Action()
{
	m_y+= 1.5;
	m_time += 1;


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
	if(m_time==920)
	{
		Scene::SetScene(new CScenefloor1());
		m_key_f = false;
	}
}
//�h���[
void CObjSummary::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f }; 

	Font::StrDraw(L"�ނ����ނ����A����Ƃ���ɁA����������Ƃ��΂����񂪏Z��ł��܂���", 0, 500-m_y + m_ky, 24, c);
	Font::StrDraw(L"����������͎R�֎Ŋ���ɁA���΂�����͐�֐���ɍs���܂���", 60, 530-m_y + m_ky * 2, 23, c);
	Font::StrDraw(L"���΂����񂪐�֐�������Ă���ƁA�h���u���R,�h���u���R��", 60, 560 - m_y + m_ky * 3, 24, c);
	Font::StrDraw(L"�傫�ȓ�������Ă��܂���", 60, 590 - m_y + m_ky * 4, 23, c);
	Font::StrDraw(L"�u����D�D�D�ǂ����݂₰�ɂȂ��v", 70, 620 - m_y + m_ky * 5, 24, c);
	Font::StrDraw(L"���΂�����͑傫�ȓ����Ђ낢�����ĉƂɎ����A��܂����B", 60, 650 - m_y + m_ky * 6, 23, c);
	Font::StrDraw(L"�����āA����������Ƃ��΂����񂪓���H�ׂ悤�Ɠ���؂��Ă݂��", 0, 680 - m_y + m_ky * 7, 24, c);
	Font::StrDraw(L"�Ȃ�ƒ����猳�C�̗ǂ��j�̐Ԃ���񂪔�яo���Ă��܂���", 60, 710 - m_y + m_ky * 8, 23, c);
	Font::StrDraw(L"�u����͂����ƁA�_���܂������������ɂ������Ȃ��v", 60, 740 - m_y + m_ky * 9, 24, c);
	Font::StrDraw(L"�q�ǂ��̂��Ȃ���������������Ƃ��΂�����́A���тł�", 60, 770 - m_y + m_ky * 10, 23, c);
	Font::StrDraw(L"�����琶�܂ꂽ�j�̎q���A����������Ƃ��΂�����͓����Y�Ɩ��t����", 0, 800 - m_y + m_ky * 11, 24, c);
	Font::StrDraw(L"�����Y�͂��������������āA�����j�̎q�ɂȂ�܂���", 60, 830 - m_y + m_ky * 12, 23, c);
	Font::StrDraw(L"�����Ă�����A�����Y�͌����܂���", 60, 860 - m_y + m_ky * 13, 24, c);
	Font::StrDraw(L"�u�ڂ��́A�S�����֍s���āA��邢�S��ގ����܂��v", 60, 890 - m_y + m_ky * 14, 23, c);
	Font::StrDraw(L"���΂�����ɂ��ђc�q������Ă��炤�ƁA�S�����֍s�����̂ł�����", 0, 920 - m_y + m_ky * 15, 24 , c);
	
}



