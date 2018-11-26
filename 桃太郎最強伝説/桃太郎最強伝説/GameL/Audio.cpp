#include "Audio.h"

#define SCENE_AUDIO_EFFCT_MAX	(16)					//���ʉ��̓����o�͍ő吔
#define HRESULT_CHECK(hr) if(FAILED(hr)){ _asm{int 3} }	//�ȒP�ȃG���[�`�F�b�N�}�N��
#define SAFE_RESET(p){ if (p) { (p).reset(nullptr);}  }


using namespace GameL;

IXAudio2*						CAudio::m_pXAudio2;			//XAudio2�I�u�W�F�N�g
IXAudio2MasteringVoice*			CAudio::m_pMasteringVoice;	//�}�X�^�[�{�����[��
vector<shared_ptr<AudioData>>	CAudio::m_AudioData;		//�T�E���h�f�[�^	
int								CAudio::m_aud_max;			//�I�[�f�B�I�ő吔
float							CAudio::m_volume;			//�}�X�^�[�{�����[���l

//�G���[�T�E���h�ϐ�
bool g_is_error_sound;

//������
void CAudio::Init(int max_audio)
{
	m_aud_max=max_audio;
	m_volume=1.0f;
	unsigned XAudio2CreateFlags = 0;
	

	XAudio2Create(&m_pXAudio2, XAudio2CreateFlags);

	//�}�X�^�[�{�C�X�쐬
	m_pXAudio2->CreateMasteringVoice(&m_pMasteringVoice);

	//�}�X�^�[�{�C�X�G���[�`�F�b�N
	g_is_error_sound = false;
	if (m_pMasteringVoice == nullptr)
	{
		MessageBox(0, L"�����ʰ�ތn�̻�߰Ăɖ�肪���邽�߁A�����Ȃ�܂���", NULL, MB_OK);
		g_is_error_sound = true;
		return;
	}

	//�������쐬
	m_AudioData.reserve(m_aud_max); //�z��̋��e�ʐݒ�
	m_AudioData.resize( m_aud_max);	//�z��̗v�f���ݒ�
	
	//�I�[�f�B�I�f�[�^�쐬
	for(int i=0;i<m_aud_max;i++)
	{
		//�e�I�[�f�B�I�������쐬	
		m_AudioData[i].reset(new AudioData);
		
		m_AudioData[i]->pData=nullptr;
		m_AudioData[i]->pWave=nullptr;
		m_AudioData[i]->Size=0;
		m_AudioData[i]->m_volume=1.0f;

		//�T�E���h�C���^�[�t�F�[�X�������쐬
		m_AudioData[i]->m_pSourceVoice = new IXAudio2SourceVoice*[SCENE_AUDIO_EFFCT_MAX];
		for(int j=0 ; j < SCENE_AUDIO_EFFCT_MAX ; j++ )
		{
			m_AudioData[i]->m_pSourceVoice[j]=nullptr;
		}

		//�~�b�N�X�{�C�X�쐬
		m_pXAudio2->CreateSubmixVoice(&m_AudioData[i]->m_pSFXSubmixVoice,1,44100,0,0,0,0);
	}

	//�}�X�^�[�{�����[��
	m_pMasteringVoice->SetVolume(1.0f,0);
}

//�N���X�j��
void CAudio::Delete()
{
	//�}�X�^�[�{�C�X�G���[�`�F�b�N
	if (g_is_error_sound == true)
	{
		m_pXAudio2->Release();
		return;
	}

	//�T�E���h�j��
	DeleteAudio();

	//�T�E���h�������j��
	for(int i=0 ; i < m_aud_max ; i++ )
	{
		//�T�E���h�C���^�[�t�F�[�X�j��
		delete [] m_AudioData[i]->m_pSourceVoice;

		//�~�b�N�X�T�E���h�j��
		m_AudioData[i]->m_pSFXSubmixVoice->DestroyVoice();
	}
	
	//�I�[�f�B�I�x�N�^�[�j��
	m_AudioData.clear();
	m_AudioData.shrink_to_fit();


	//�}�X�^�[�{�C�X�@�EXAudio2�j��
	m_pMasteringVoice->DestroyVoice();
	
	m_pXAudio2->Release();
}

//�e�{�����[���ύX
float CAudio::Volume(float t,int id)
{
	//�}�X�^�[�{�C�X�G���[�`�F�b�N
	if (g_is_error_sound == true)
	{
		return 0.0f;
	}

	if(id<0)		 return -1.0f;
	if(id>m_aud_max) return -1.0f;
	m_AudioData[id]->m_volume+=t;
	if(m_AudioData[id]->m_volume<0.0f)  m_AudioData[id]->m_volume= 0.0f; 
	if(m_AudioData[id]->m_volume>10.0f) m_AudioData[id]->m_volume=10.0f; 

	m_AudioData[id]->m_pSFXSubmixVoice->SetVolume(m_AudioData[id]->m_volume,0);
	return m_AudioData[id]->m_volume;
}

//�}�X�^�[�{�����[���ύX
float CAudio::VolumeMaster(float t)
{	
	//�}�X�^�[�{�C�X�G���[�`�F�b�N
	if (g_is_error_sound == true)
	{
		return 0.0f;
	}

	m_volume+=t;
	if(m_volume< 0.0f) m_volume= 0.0f; 
	if(m_volume>10.0f) m_volume=10.0f; 
	m_pMasteringVoice->SetVolume(m_volume,0);
	return m_volume;
}

//�T�E���h���j��
void CAudio::DeleteAudio()
{
	//�}�X�^�[�{�C�X�G���[�`�F�b�N
	if (g_is_error_sound == true)
	{
		return;
	}

	for(int i=0 ; i < m_aud_max ; i++ )
	{
		//�C���^�[�t�F�[�X�j��
		for(int j=0 ; j < SCENE_AUDIO_EFFCT_MAX ; j++ )
		{
			if(m_AudioData[i]->m_pSourceVoice[j]!=nullptr)
			{
				m_AudioData[i]->m_pSourceVoice[j]->Stop();
				m_AudioData[i]->m_pSourceVoice[j]->FlushSourceBuffers();
				m_AudioData[i]->m_pSourceVoice[j]->DestroyVoice();
				m_AudioData[i]->m_pSourceVoice[j]=nullptr;
			}
		}

		//�T�E���h�f�[�^�j��
		if(m_AudioData[i]->pWave != nullptr)
		{
			delete []m_AudioData[i]->pWave;
			m_AudioData[i]->pWave=nullptr;
		}
	}
}

//�X�^�[�g
void CAudio::Start(int id)
{
	//�}�X�^�[�{�C�X�G���[�`�F�b�N
	if (g_is_error_sound == true)
	{
		return;
	}

	if(id<0)		 return ;
	if(id>m_aud_max) return ;

	if(m_AudioData[id]->m_type==BACK_MUSIC)
	{
		//���[�v�T�E���h
		//���[�v�X�^�[�g�̍ہA�j������
		Stop(id);
		m_AudioData[id]->m_pSourceVoice[0]->SubmitSourceBuffer(&m_AudioData[id]->m_sound_buffer);
		m_AudioData[id]->m_pSourceVoice[0]->Start();
		return ;
	}
	else
	{
		//�G�t�F�N�g�T�E���h
		for(int i=0 ; i<(SCENE_AUDIO_EFFCT_MAX<<1) ; i++ )
		{
			//�T�E���h�z�����̊ԂŎg�p����Ă��Ȃ��ꏊ�m�F����
			int count = i%SCENE_AUDIO_EFFCT_MAX;

			//�T�E���h�̏�Ԃ��擾
			XAUDIO2_VOICE_STATE stats;
			m_AudioData[id]->m_pSourceVoice[count]->GetState(&stats);

			//�T�E���h�o�b�t�@���󂩂ǂ����`�F�b�N
			if( stats.BuffersQueued == 0 )
			{
				//�T�E���h�C���^�[�t�F�[�X�ɃT�E���h��o�^���ăT�E���h��炷
				m_AudioData[id]->m_pSourceVoice[count]->SubmitSourceBuffer(&m_AudioData[id]->m_sound_buffer);
				m_AudioData[id]->m_pSourceVoice[count]->Start();
				return ;
			}
		}
		//�C���^�[�t�F�[�X���S�Ďg���Ă����ꍇ�@�ŏI�C���^�[�t�F�[�X�ŗ���Ă�T�E���h�������j�����āA�T�E���h�o�^���Ė炷
		m_AudioData[id]->m_pSourceVoice[SCENE_AUDIO_EFFCT_MAX-1]->Stop();
		m_AudioData[id]->m_pSourceVoice[SCENE_AUDIO_EFFCT_MAX-1]->FlushSourceBuffers();
		m_AudioData[id]->m_pSourceVoice[SCENE_AUDIO_EFFCT_MAX-1]->SubmitSourceBuffer(&m_AudioData[id]->m_sound_buffer);
		m_AudioData[id]->m_pSourceVoice[SCENE_AUDIO_EFFCT_MAX-1]->Start();
		return ;
	}
}
//�X�g�b�v
void CAudio::Stop(int id)
{
	//�}�X�^�[�{�C�X�G���[�`�F�b�N
	if (g_is_error_sound == true)
	{
		return;
	}

	if(id<0)		 return ;
	if(id>m_aud_max) return ;

	for(int i=0 ; i < SCENE_AUDIO_EFFCT_MAX ; i++ )
	{
		m_AudioData[id]->m_pSourceVoice[i]->Stop();
		m_AudioData[id]->m_pSourceVoice[i]->FlushSourceBuffers();
	}
}

//�T�E���h�{�C�X�f�[�^�o�^
void CAudio::LoadAudio(int id ,wchar_t* name,SOUND_TYPE type)
{
	//�}�X�^�[�{�C�X�G���[�`�F�b�N
	if (g_is_error_sound == true)
	{
		return;
	}

	if(id<0)		 return ;
	if(id>m_aud_max) return ;

	//�C���^�[�t�F�[�X�j��
	if(m_AudioData[id]->m_pSourceVoice[0]!=nullptr)
	{
		for(int j=0 ; j < SCENE_AUDIO_EFFCT_MAX ; j++ )
		{
			if(m_AudioData[id]->m_pSourceVoice[j]!=nullptr)
			{
				m_AudioData[id]->m_pSourceVoice[j]->Stop();
				m_AudioData[id]->m_pSourceVoice[j]->FlushSourceBuffers();
				m_AudioData[id]->m_pSourceVoice[j]->DestroyVoice();
				m_AudioData[id]->m_pSourceVoice[j]=nullptr;
			}
		}

		//�T�E���h�f�[�^�j��
		if(m_AudioData[id]->pWave != nullptr)
			delete []m_AudioData[id]->pWave;
	}

	//�T�E���h�^�C�v�Z�b�g
	m_AudioData[id]->m_type=type;
	


	//wave�t�@�C���̃��������ɓW�J
	ifstream ifs(name,ios::in | ios::binary);
	if(!ifs)	return;

	unsigned int Size = 0;
	//�W�J
	ifs.seekg(0,ios::end);
	Size = static_cast<unsigned>( ifs.tellg() );
	ifs.seekg(0,ios::beg);
	m_AudioData[id]->pWave = new unsigned char[Size];

	ifs.read(reinterpret_cast<char*>(m_AudioData[id]->pWave),Size);
	ifs.close();

	//RIFF�t�@�C�����
	//wave���
	WAVEFORMATEX WaveformatEx = {0};
	FindChunk(m_AudioData[id]->pWave,"fmt",&m_AudioData[id]->Size,&m_AudioData[id]->pData);
	
	//wave��񕪃A�h���X�����炵�Ĕg��f�[�^�Ɉړ�
	unsigned char* p = m_AudioData[id]->pData;
	WaveformatEx.wFormatTag =      GetWord(p);  p += sizeof(WORD);
	WaveformatEx.nChannels =       GetWord(p);  p += sizeof(WORD);
	WaveformatEx.nSamplesPerSec  = GetDword(p); p += sizeof(DWORD);
	WaveformatEx.nAvgBytesPerSec = GetDword(p); p += sizeof(DWORD);
	WaveformatEx.nBlockAlign =     GetWord(p);  p += sizeof(WORD);
	WaveformatEx.wBitsPerSample =  GetWord(p);  p += sizeof(WORD);
	WaveformatEx.cbSize =          GetWord(p);  p += sizeof(WORD);
	
	//�g�{�̂̃f�[�^
	FindChunk(m_AudioData[id]->pData,"data",&m_AudioData[id]->Size,&m_AudioData[id]->pData);

	//�Đ��̂��߂̃C���^�[�t�F�[�X����
	XAUDIO2_SEND_DESCRIPTOR SFXSend = {1, m_AudioData[id]->m_pSFXSubmixVoice};
	XAUDIO2_VOICE_SENDS SFXSendList = {1, &SFXSend};
	for (int i = 0; i < SCENE_AUDIO_EFFCT_MAX; i++)
	{
		m_pXAudio2->CreateSourceVoice(&m_AudioData[id]->m_pSourceVoice[i], &WaveformatEx);
	}
	//�T�E���h�o�b�t�@���\�[�X�{�C�X�L���[�ɍ쐬
	memset(&m_AudioData[id]->m_sound_buffer,0x00,sizeof(m_AudioData[id]->m_sound_buffer));
	m_AudioData[id]->m_sound_buffer.AudioBytes		=  m_AudioData[id]->Size;
	m_AudioData[id]->m_sound_buffer.pAudioData		=  reinterpret_cast<BYTE*>(m_AudioData[id]->pData);
	m_AudioData[id]->m_sound_buffer.Flags			=  XAUDIO2_END_OF_STREAM;

	if(type==EFFECT)
		m_AudioData[id]->m_sound_buffer.LoopCount	=  0;
	else
		m_AudioData[id]->m_sound_buffer.LoopCount	=  XAUDIO2_LOOP_INFINITE;

	//�{�����[���ݒ�
	m_AudioData[id]->m_volume=1.0f;
	m_AudioData[id]->m_pSFXSubmixVoice->SetVolume(m_volume,0);
}

//wave�t�@�C���ǂݍ���
WORD  CAudio::GetWord(const unsigned char* pData)
{
	WORD Value = pData[0] | pData[1] << 8;
	return Value;
}
DWORD CAudio::GetDword(const unsigned char* pData)
{
	DWORD Value = pData[0] | pData[1] << 8 | pData[2] << 16 | pData[3] << 24;
	return Value;
}

//���Ȃ炸�`�����N�͌�����Ƃ��Ċȗ���
void CAudio:: FindChunk(const unsigned char* pData,const char* pChunckName,unsigned* Size,unsigned char** ppData)
{
	const unsigned CHUNKNAME_LENGTH = std::strlen(pChunckName);
	while(true)
	{
		bool IsFind = true;
		for(unsigned i = 0 ; i < CHUNKNAME_LENGTH ; ++i)
		{
			if(pData[i] != pChunckName[i])
			{
				IsFind = false;
				break;
			}
		}
		if(IsFind)
		{
			*Size = pData[4+0] | pData[4+1] << 8 | pData[4+2] << 16 | pData[4+3] << 24;
			*ppData = const_cast<unsigned char*>(pData+8 );
			return ;
		}

		pData++;
	}
	return;
}
