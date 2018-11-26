#pragma once
//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)  

#include <memory>
using namespace std;

namespace GameL
{
	//���[�U�[�E�Z�[�u�E�V�[���Ԏ󂯓n���f�[�^�N���X
	typedef class CUserData
	{
		public :
			static void Init(void* data,int size);
			static void Delete();
			static void Open();
			static void Seve();
			static void* GetData();

			//���[�U�[�f�[�^�ȊO�̊O���f�[�^�ǂݍ���
			//�S�f�[�^(��������)���擾�������������Ԃ����
			//�e�L�X�g�G�f�B�^��Unicode�w��@BOM�`�F�b�N�L��ɂ��Ă��������B
			static unique_ptr<wchar_t> ExternalDataOpen(wchar_t* file_name,int* size);
		private:
			static void* m_data;		//���[�U�[���
			static int   m_data_size;	//���[�U�[���T�C�Y
	}Save;
};