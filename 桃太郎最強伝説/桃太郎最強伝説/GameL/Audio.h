#pragma once
//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)  

#include <XAudio2.h>
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;


namespace GameL
{
	enum SOUND_TYPE
	{
		EFFECT,			//���ʉ�			�i�P�����j
		BACK_MUSIC,		//�o�b�N�~���[�W�b�N (���[�v)
	};


	//�T�E���h�f�[�^
	struct AudioData
	{
		//�T�E���h���(RIFF�t�@�C���t�H�[�}�b�g��ǂݎ��p)
		unsigned int   Size;					//�T�E���h�T�C�Y
		unsigned char* pWave;					//wave�擪�A�h���X�|�C���^
		unsigned char* pData;					//�g����A�h���X�|�C���^
		//Audio�f�[�^
		IXAudio2SourceVoice**	m_pSourceVoice;     //�T�E���h�{�C�X�C���^�[�t�F�[�X
		IXAudio2SubmixVoice*	m_pSFXSubmixVoice;  //�T�u�~�N�X�C���^�[�t�F�[�X
		SOUND_TYPE				m_type;				//�T�E���h�^�C�v
		XAUDIO2_BUFFER			m_sound_buffer;		//�T�E���h�o�b�t�@
		float					m_volume;			//�{�����[�����
	};

	//�I�[�f�B�I�N���X
	//Wave�`���̓ǂݍ��݂ƃT�E���h�Đ��E�Ǘ����s��
	typedef class CAudio
	{
		public:
			static void Init(int max_audio);			//������
			static void Delete();						//�N���X�j��
			static void LoadAudio(int id,wchar_t* name,SOUND_TYPE type);	//�T�E���h�{�C�X�f�[�^�o�^
			static void DeleteAudio();					//�T�E���h���j��
			static void Start(int id);					//�X�^�[�g	
			static void Stop(int id);					//�X�g�b�v
			static float Volume(float t,int id);		//�X�̃T�E���h�{�����[���ύX
			static float VolumeMaster(float t);			//�S�̂̃T�E���h�{�����[���ύX

		private:
			static IXAudio2*						m_pXAudio2;				//XAudio2�I�u�W�F�N�g
			static IXAudio2MasteringVoice*			m_pMasteringVoice;		//�}�X�^�[�{�����[��
			static vector<shared_ptr<AudioData>>	m_AudioData;			//�T�E���h�f�[�^
			static int		m_aud_max;					//�I�[�f�B�I�ő吔
			static float	m_volume;					//�}�X�^�[�{�����[���l
			//wave�t�@�C���ǂݍ���
			static WORD GetWord(const unsigned char* pData);
			static DWORD GetDword(const unsigned char* pData);
			static void FindChunk(const unsigned char* pData,const char* pChunckName,unsigned* Size,unsigned char** ppData);
	}Audio;
};
