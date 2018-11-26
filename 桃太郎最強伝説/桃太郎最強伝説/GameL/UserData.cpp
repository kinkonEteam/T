#include <stdio.h>
#include <locale.h>
#include "UserData.h"
using namespace GameL;

#define SEVE_NAME (L"user_data")
void* CUserData::m_data;		//���[�U�[���
int   CUserData::m_data_size;	//���[�U�[���T�C�Y


void* CUserData::GetData()
{
	return m_data;
}

void CUserData::Init(void *data,int size)
{
	setlocale( LC_CTYPE, "jpn" );
	m_data=data;
	m_data_size=size;
}

void CUserData::Delete()
{
	m_data=nullptr;
	m_data_size=0;
}

void CUserData::Open()
{
	FILE* fp;
	_wfopen_s(&fp,SEVE_NAME,L"r");
	if(fp==nullptr)
	{
		memset(m_data,0x00,m_data_size);
		return ;
	}
	fread(m_data,m_data_size,1,fp);
	fclose(fp);
}

void CUserData::Seve()
{
	FILE* fp;
	_wfopen_s(&fp,SEVE_NAME,L"w");
	if(fp==nullptr) return ;
	fwrite(m_data,m_data_size,1,fp);
	fclose(fp);

}

unique_ptr<wchar_t> CUserData::ExternalDataOpen(wchar_t* file_name,int* size)
{
	
	int  s=0;
	wint_t c;
	unique_ptr<wchar_t> str;
	FILE* fp;
	_wfopen_s(&fp,file_name,L"rt,ccs=Unicode");//�����R�[�h��Unicode�w��
	if(fp==nullptr) return nullptr;

	//�t�@�C���̃T�C�Y�擾
	do
	{
		c=fgetwc(fp);
		if( c == WEOF )
		{
			break;
		}
		else
		{
			s++;
		}
		
	}while(1);

	if(s==0)
	{
		fclose(fp);
		return nullptr;
	}

	fseek(fp,0, SEEK_SET);
	//�t�@�C�����̑傫��
	str.reset(new wchar_t[s+1]);
	fread(str.get(),sizeof(wchar_t)*s,1,fp);
	str.get()[s]=L'\0';
	fclose(fp);

	*size=s+1;
	return move(str);
}