//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "ObjTalk.h"
#include "GameHead.h"

void CObjTalk::Init()
{
	m_page = 0;		//�n���ꂽ�y�[�W��
	m_sec = 0;		//�b���J�E���g
	m_line = 0;		//�s���J�E���g
	m_picture = 9;	//�摜�ԍ��ύX�p
}

void CObjTalk::Action()
{
	if (m_page == m_p) {//�n���ꂽ�y�[�W���ƌ��݂̃y�[�W���������ɂȂ�����
		this->SetStatus(false);		//�I�u�W�F�N�g�폜
	}

	//���͔���A�������ςȂ�����
	if (Input::GetVKey(VK_RETURN) == true)//�G���^�[�L�[���͎�
	{
		if (m_f == true){//m_f��true�̏ꍇ
			m_page += 1;	//�y�[�W���P���Z
			m_line = 0;		//�s�����Z�b�g
			m_sec = 0;		//�b�����Z�b�g
			m_f = false;	//m_f��true����
		}
	}
	else//�G���^�[�L�[������Ă���ꍇ
		m_f = true;		//true���
}

void CObjTalk::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	if (m_tipe == 0) {//tipe0�́A�����o�������O�p�摜��\��
		 //�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 128.0f;
		src.m_bottom = 64.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 400.0f;
		dst.m_left = 20.0f;
		dst.m_right = 780.0f;
		dst.m_bottom = 580.0f;
		//�`��
		Draw::Draw(m_picture, &src, &dst, c, 0.0f);

		if (m_p != 1) {//�y�[�W����1�ł͂Ȃ��ꍇ
					   //�����摜�𖼑O�p�ɏォ��\��
			CObjText* text = (CObjText*)Objs::GetObj(OBJ_TEXT);
			CObjSummary* summary = (CObjSummary*)Objs::GetObj(OBJ_SUMMARY);
			if (text != nullptr || summary != nullptr)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = 380.0f;
				dst.m_left = 30.0f;
				dst.m_right = 200.0f;
				dst.m_bottom = 420.0f;
			}
			else
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = 380.0f;
				dst.m_left = 30.0f;
				dst.m_right = 100.0f;
				dst.m_bottom = 420.0f;
			}
			//�`��
			Draw::Draw(m_picture, &src, &dst, c, 0.0f);
		}
		else { ; }
	}


	else if (m_tipe == 1) {//tipe1�́A�R�����g���B���摜�\��
		if (m_sec <= 715) {//715(�R�����g�̕�)�܂Ŏ��Ԍo��
			m_sec += 5;	   //�����̕\���X�s�[�h---------------------
		}				   //���𒴂���ƁA�s����+1
		else {
			m_line += 1;
			m_sec = 0;
		}

		//�؂���ʒu�̐ݒ�(�摜�̍��������ɐݒ�)
		src.m_top = 10.0f;
		src.m_left = 10.0f;
		src.m_right = 120.0f;
		src.m_bottom = 60.0f;

		if (m_p != 1) {
			if (m_line == 0) {//�P�s�ځ[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[
							  //�\���ʒu�̐ݒ�
				dst.m_top = 440.0f;
				if (m_line == 0)//�P�s�ڂ̎��̂ݓ���
					dst.m_left = 50.0f + (m_sec*1.0f);
				else
					dst.m_left = 50.0f;
				dst.m_right = 765.0f;
				dst.m_bottom = 470.0f;
				//�`��
				Draw::Draw(m_picture, &src, &dst, c, 0.0f);
			}//�s���ς��ƁA�\�����Ȃ�
			else { ; }
			if (m_line <= 1) {//�Q�s�ځ[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[
							  //�\���ʒu�̐ݒ�
				dst.m_top = 480.0f;
				if (m_line == 1)//�Q�s�ڂ̎��̂ݓ���
					dst.m_left = 50.0f + (m_sec*1.0f);
				else
					dst.m_left = 50.0f;
				dst.m_right = 765.0f;
				dst.m_bottom = 510.0f;
				//�`��
				Draw::Draw(m_picture, &src, &dst, c, 0.0f);
			}//�s���ς��ƁA�\�����Ȃ�
			else { ; }
			if (m_line <= 2 && m_p != 1) {//�R�s�ځ[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[
										  //�\���ʒu�̐ݒ�
				dst.m_top = 520.0f;
				if (m_line == 2)//�R�s�ڂ̎��̂ݓ���
					dst.m_left = 50.0f + (m_sec*1.0f);
				else
					dst.m_left = 50.0f;
				dst.m_right = 765.0f;
				dst.m_bottom = 550.0f;
				//�`��
				Draw::Draw(m_picture, &src, &dst, c, 0.0f);
			}//�s���ς��ƁA�\�����Ȃ�
			else { ; }
		}

		if (m_line <= 3 || m_p == 1) {//�E�E�E�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[
			dst.m_top = 550.0f;
			if (m_line > 2 || m_p == 1)//�R�s�ڈȍ~�A����
				if (m_sec <= 160)//�\���ʒu��i�K�I�ɕύX
					dst.m_left = 745.0f;
				else if (m_sec <= 280)
					dst.m_left = 760.0f;
				else if (m_sec <= 440)
					dst.m_left = 770.0f;
				else if (m_sec <= 600)
					dst.m_left = 730.0f;
				else { dst.m_left = 730.0f; m_sec = 0; }//�J�E���g���O�ɂ��āA���ɖ߂�
			else
				dst.m_left = 730.0f;
			dst.m_right = 770.0f;
			dst.m_bottom = 575.0f;
			//�`��
			Draw::Draw(m_picture, &src, &dst, c, 0.0f);
		}
		else { ; }
	}

	else if (m_tipe == 2) {
		//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
		float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
		RECT_F src; //�`�挳�؂���ʒu
		RECT_F dst; //�`���\���ʒu
					//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 600.0f;
		src.m_bottom = 600.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 250.0f;
		dst.m_left = 50.0f;
		dst.m_right = 250.0f;
		dst.m_bottom = 450.0f;
		Draw::Draw(18, &src, &dst, c, 0.0f);
	}
	else if (m_tipe == 3) {
		//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
		float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
		RECT_F src; //�`�挳�؂���ʒu
		RECT_F dst; //�`���\���ʒu
					//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 600.0f;
		src.m_bottom = 600.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 250.0f;
		dst.m_left = 50.0f;
		dst.m_right = 250.0f;
		dst.m_bottom = 450.0f;
		Draw::Draw(19, &src, &dst, c, 0.0f);
	}
	else if (m_tipe == 4) {
		//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
		float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
		RECT_F src; //�`�挳�؂���ʒu
		RECT_F dst; //�`���\���ʒu
					//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 800.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 250.0f;
		dst.m_left = 50.0f;
		dst.m_right = 250.0f;
		dst.m_bottom = 450.0f;
		Draw::Draw(20, &src, &dst, c, 0.0f);
	}
}