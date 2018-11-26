#pragma once
//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)  

#include <memory>
#include <list>
using namespace std;

namespace GameL
{
	//---	�Փˏ�ԍ\����		---//
	struct HIT_BOX
	{
		float x;	//�ʒux
		float y;	//�ʒuy
		float h;	//����
		float w;	//��
	};
	struct HIT_STATUS
	{
		 int  e;	//�����蔻�葮��
		 int  n;	//�I�u�W�F�N�g�l�[��
		 bool i;	//���G�X�C�b�`
		 int  p;	//�ʃ|�C���g���
	};
	struct HIT_DATA
	{
		int	  e;	//������������̑������
		int   n;	//������������̃I�u�W�F�N�g�l�[��
		int	  p;	//������������̃|�C���g���
		float s;	//����
		float r;	//�������Ă���p�x
		void* o;	//�������Ă���I�u�W�F�N�g�A�h���X
	};
	//-----------------------------//
	//---	�Փ˔���p�N���X	---//
	typedef class CHitBox
	{
		friend class CHitBoxManager;
		public:
			CHitBox();
			~CHitBox();
			void SetObj(void* t);									//����HitBox�����I�u�W�F�N�g�A�h���X�̐ݒ�
			void SetPos(float x,float y,float h,float w);			//���W�E�傫���ݒ�
			void SetPos(float x,float y);							//���W�ݒ�
			void SetStatus(int e,int n,int p);						//�����E�I�u�W�F�N�g�l�[���E�|�C���g�ݒ�
			void SetInvincibility(bool i);							//���G�̗L��

			void* CheckObjNameHit(int obj_name);					//HIT_BOX���̃I�u�W�F�N�g�l�[����T��
			void* CheckObjNameHit(int obj_name,int point);			//HIT_BOX���̃I�u�W�F�N�g�l�[���ƃ|�C���g�ŒT��
			bool  CheckElementHit(int element);						//HIT_BOX���ɂ��鑮����������
			bool  CheckElementHit(int element,int point);			//HIT_BOX���ɂ��鑮�����ƃ|�C���g������

			HIT_DATA** SearchObjNameHit(int name);					//HIT_BOX���̃l�[���ŒT�������ʂ�z��ɂ��ďo��
			HIT_DATA** SearchObjNameHit(int name,int point);		//HIT_BOX���̃l�[���E�|�C���g�ŒT�������ʂ�z��ɂ��ďo��
			HIT_DATA** SearchElementHit(int element);				//HIT_BOX���̑����ŒT�������ʂ�z��ɂ��ďo��
			HIT_DATA** SearchElementHit(int element,int point);		//HIT_BOX���̑����E�|�C���g�ŒT�������ʂ�z��ɂ��ďo��
			
			int		    GetCount();									//�������Ă���q�b�g����̐���Ԃ�
			bool	    GetInvincibility();							//���G��Ԋm�F
			void*	    GetMyObj();									//����HITBOX�����I�u�W�F�N�g�A�h���X��Ԃ�
			HIT_STATUS* GetStatus();								//�X�e�[�^�X�̏��
			HIT_BOX*	GetHitBox();								//�ʒu�E�����E��
		private:
			void SortHitBox();					//�������Ă�����̋����\�[�g
			HIT_STATUS	  m_hit_status;			//�����蔻��̏��
			HIT_BOX		  m_hit_box;			//�����蔻��̍��W��
			HIT_DATA*	  m_hit_data;			//�������Ă��鑊��̏��[10]
			HIT_DATA**	  m_hit_search_data;	//�������Ă��鑊��̒��ő����E�l�[��������̏��[10]
			void*		  m_my_obj;				//����HitBox�����I�u�W�F�N�g�A�h���X
			int			  m_hit_count;			//�q�b�g���Ă���J�E���g��
	}HitBox;
	//-----------------------------//

	//�Փ˔���}�l�[�W���[
	typedef class CHitBoxManager
	{
		public:
			static void		Init();
			static void		Delete();
			static void		SetHitBox(void* t,float x,float y,float w,float h,int e,int n,int p);	//�q�b�g�{�b�N�X�̍쐬�Ɠo�^
			static CHitBox*	GetHitBox(void* t);												//�����̃A�h���X�����q�b�g�{�b�N�X��Ԃ�
			static void		DeleteHitBox(void* t);											//�����̃A�h���X�����q�b�g�{�b�N�X�̍폜
			static void		AllHitCheck();													//�Փ˔���
			static void		DeleteAllListData();											//���X�g���j��
			static void		DrawHitBox();													//�f�o�b�N�p�̓����蔻��`��
		private:
			static bool Hit(HIT_BOX* a, HIT_BOX* b, HIT_DATA* hit);							//a�����̂ǂ��ɓ������Ă��邩
			static list<shared_ptr<CHitBox>>*	m_ListHitBox;								//�Փ˔��胊�X�g

	}Hits;
};