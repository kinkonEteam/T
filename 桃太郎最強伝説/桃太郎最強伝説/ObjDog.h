#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�I�u�W�F�N�g�F�L�����N�^�[�u���b�N
class CObjDog : public CObj
{
	public:
		CObjDog(float x, float y);
		~CObjDog() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
		void Setdf(bool df) { m_df = df; }
	private:
		float m_px;		 //�ʒu
		float m_py;

		bool m_df;

};

