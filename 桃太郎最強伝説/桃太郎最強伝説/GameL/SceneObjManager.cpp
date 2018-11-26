#include "SceneObjManager.h"
using namespace GameL;

//�\�[�g�p�N���X
class Pr
{
	public:
	bool operator()(const shared_ptr<CObj> x, const shared_ptr<CObj> y) const 
	{
		return x.get()->GetPrio()  <  y.get()->GetPrio();
	}
};

list<shared_ptr<CObj>>*		CSceneObjManager::m_ListData;	//�Q�[�����s���X�g
		
//---CObj-----------------------------------------------------
//�R���X�g���N�^
CObj::CObj()
{
	m_prio=     0;
	m_name=    -1;
	m_status=true;
}

//�D�揇�ʕύX
void CObj::SetPrio(unsigned int prio)
{
	m_prio=prio;
	CSceneObjManager::ResetPrio();
}

unsigned int CObj::GetPrio()
{
	return m_prio;
}

//�I�u�W�F�N�g���OID�ύX
void CObj::SetName(int name)
{
	m_name=name;
}

int CObj::GetName()
{
	return m_name;
}

//�I�u�W�F�N�g�̏�ԕύX
void CObj::SetStatus(bool exe)
{
	m_status=exe;
}
bool CObj::GetStatus()
{
	return m_status; 
}
//------------------------------------------------------------


//������
void CSceneObjManager::Init()
{
	m_ListData= new list<shared_ptr<CObj>>;
}

//�폜
void CSceneObjManager::Delete()
{
	m_ListData->clear(); 
	delete m_ListData;
}

//�^�X�N�f�[�^�}���i���[�j���\�b�h
void CSceneObjManager:: InsertObj(CObj* obj,int name,unsigned int prio)
{
	if(obj == nullptr ) 
		return ;
	
	//�I�u�W�F�N�g�̏��������\�b�h�N��
	obj->Init();

	//�I�u�W�F�N�g�X�e�[�^�X�o�^
	obj->SetName(name);
	

	//�f�[�^�o�^
	unique_ptr<CObj> ptr_obj(obj);
	m_ListData->push_front(move(ptr_obj));

	obj->SetPrio(prio);

	return;
}

//�I�u�W�F�N�g���X�g�폜���߃��\�b�h
void CSceneObjManager::ListDeleteSceneObj()
{
	for(auto itr = m_ListData->begin() ; itr != m_ListData->end() ; itr++ )
	{
		(*itr)->SetStatus(false);
	}
}

//�A�N�V�������s
void CSceneObjManager::ObjAction()
{
	//�폜���s
	auto i = m_ListData->begin();
	while (i !=  m_ListData->end())
	{
		if (i->get()->GetStatus() == false)
		{
			i=m_ListData->erase(i);
		} 
		else
		{
			i++;
		}
	}

	//�A�N�V�������s
    for(auto itr =m_ListData->begin() ; itr !=m_ListData->end() ; itr++ )
	{
		if( (*itr)->GetStatus() == true )
		{
			(*itr)->Action();
		}
	}
}

//�`��D�揇�ʂ̍ăZ�b�g
void CSceneObjManager::ResetPrio()
{
	//�`��D�揇�ʃ��X�g�\�[�g//
	Pr pr;
	if(m_ListData->size()>=2)
	{
		m_ListData->sort(pr);
	}
}

//�h���[���s
void CSceneObjManager::ObjDraw()
{
	//�`����s
    for(auto itr = m_ListData->begin() ; itr != m_ListData->end() ; itr++ )
	{
		if( (*itr)->GetStatus() == true )
		{
			(*itr)->Draw(); 
		}
	}
}

//OBJ_NEME����I�u�W�F�N�g���擾
CObj* CSceneObjManager::GetObj(int name)
{
    for(auto itr =m_ListData->begin() ; itr != m_ListData->end() ; itr++ )
	{
		if( (*itr)->GetName()== name )
			return (*itr).get(); 
	}

	return NULL;
}
