//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "Inventory.h"
#include "GameL\Audio.h"
#include "Itemlist.cpp"
//�g�p����l�[���X�y�[�X
using namespace GameL;

extern int HP;		//Date.cpp���Ő錾�����O���[�o���ϐ���extern�錾

CObjHero::CObjHero(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;

	m_hp = HP;			//����HP�T
	m_time = 70;
	alpha = 1.0f;
	count = 10;

	m_posture = 0.0f;	//����(0.0f) ��(1.0f) �E(2.0f) �w��(3.0f)
	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[��
	m_Sf = true;			//�U������
	m_Kf = true;			//�L�W�U������
	m_key_f = false;		//���G���ԍs������
	m_t = false;

	//HitBox�쐬���W�ƃT�C�Yx,y�A�G�������g�ƃI�u�W�F�N�g��ݒ�
	Hits::SetHitBox(this, m_px+5, m_py+3, 40, 47, ELEMENT_PLAYER, OBJ_HERO, 1);

	Audio::LoadAudio(4, L"�ߐڍU��.wav", EFFECT);			//�ߐڍU��SE
	Audio::LoadAudio(5, L"kijiSE.wav", EFFECT);				//�������U��SE
	Audio::LoadAudio(6, L"damage.wav", EFFECT);				//�_���[�WSE
	Audio::LoadAudio(8, L"heal.wav", EFFECT);				//�̗͉񕜎�SE
	Audio::LoadAudio(9, L"speeddown.wav", EFFECT);			//���_�擾���pSE

	//���ʂ�0.9������
	float Volume = Audio::VolumeMaster(-0.9f);
}

//�A�N�V����
void CObjHero::Action()
{
	//�x�N�g��������
	m_vx = 0.0f;
	m_vy = 0.0f;

	
	if (m_key_f==false)
	{
		//�U���̓��͔���A�������ςȂ�����
		if (Input::GetVKey('A') == true)
		{
			if (m_Sf == true)
			{
				//�ߋ����U������炷
				Audio::Start(4);
				//���I�u�W�F�N�g�쐬		�����Ō��ɍ��W�ƌ�����n��
				CObjSword* swd = new CObjSword(m_px, m_py, m_posture);//�쐬
				Objs::InsertObj(swd, OBJ_SWORD, 3);	//�}�l�[�W���[�ɓo�^

				m_Sf = false;
			}
		}
		else//�����Ă���ꍇ
			m_Sf = true;


		//�L�W�̏����擾
		CObjFlyKiji* obj = (CObjFlyKiji*)Objs::GetObj(OBJ_FLYKIJI);
		if (Input::GetVKey('S') == true)
		{
			if (obj == nullptr)//�L�W��񂪑��݂��Ȃ��ꍇ
			{
				//�������U������炷
				Audio::Start(5);

				//�L�W�I�u�W�F�N�g�쐬				�L�W�ɍ��W�ƌ�����n��
				CObjFlyKiji* kiji = new CObjFlyKiji(m_px, m_py, m_posture);//�쐬
				Objs::InsertObj(kiji, OBJ_FLYKIJI, 3);	//�}�l�[�W���[�ɓo�^
			}
		}
		else //�����ĂȂ��ꍇ
		{
			;//�������Ȃ�
		}

		//��l���̈ړ��Ƀx�N�g��������
		if (Input::GetVKey(VK_RIGHT) == true)//��
		{
			m_vx += 1.0f;
			m_posture = 2.0f;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_UP) == true)	//��
		{
			m_vy -= 1.0f;
			m_posture = 3.0f;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_DOWN) == true)//��
		{
			m_vy += 1.0f;
			m_posture = 0.0f;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_LEFT) == true)//��
		{
			m_vx -= 1.0f;
			m_posture = 1.0f;
			m_ani_time += 1;
		}
		else
		{
			m_ani_frame = 1;	//�L�[���͂��Ȃ��ꍇ�͐Î~�t���[���ɂ���
			m_ani_time = 0;
		}
	}


	if (m_ani_time > 6)		//�A�j���[�V��������Ԋu(�������ŃA�j���[�V�������x�ύX�o����)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
		m_ani_frame = 0;	//�t���[��4��0�ɖ߂�

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�X�N���[��
	CObjMap1*b = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
		m_px = 375;
		m_py = 275;

	//�u���b�N�Ƃ̓����蔻��
	CObjMap1*pb = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	pb->Map1Hit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px+5, m_py+3);

	//ELEMENT_ENEMY�����I�u�W�F�N�g�ƐڐG������
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
		{
			//��l�����G�Ƃǂ̊p�x�œ������Ă��邩���m�F
			HIT_DATA**hit_data;							//�����������ׂ̍��ȏ������邽�߂̍\����
			hit_data = hit->SearchElementHit(ELEMENT_ENEMY);//hit_data�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

			for (int i = 0; i < hit->GetCount(); i++)
			{
				//�_���[�W����炷
				Audio::Start(6);

				//�G�̍��E�ɓ���������
				float r = hit_data[i]->r;
				if ((r < 45 && r >= 0) || r > 315)
				{
					m_t = true;
					if (m_t == true)
					{
						m_vx += -1.0f;//���Ɉړ�������
					}
				}
				if (r > 45 && r < 135)
				{
					m_vy = 10.0f;//��Ɉړ�������
				}
				if (r > 135 && r < 225)
				{
					m_vx = 10.0f;//�E�Ɉړ�������
				}
				if (r > 225 && r < 315)
				{
					m_vy = -10.0f;//�����Ɉړ�������
				}
			}
			m_hp -= 1;
			m_f = true;
			m_key_f = true;
			hit->SetInvincibility(true);//���G�I��
		}

		if (m_f == true)
		{
			m_time--;//���G���ԊJ�n

			if (m_time == 30)
				m_key_f = false;

			alpha = 0.5f;
		}
		if (m_time <= 0)
		{
			m_f = false;
			hit->SetInvincibility(false);//���G�I�t
			alpha = 1.0f;
			m_time = 70;
		}

		//�A�C�e���ɓ��������ꍇ�ȉ��̏���������
		if (hit->CheckElementHit(ELEMENT_ITEM) == true)
		{
			if (hit->CheckObjNameHit(OBJ_PEACH) != nullptr)
			{				
				m_hp += 1;
				Audio::Start(8);//�񕜉���炷
			}
			if (hit->CheckObjNameHit(OBJ_YELLOW_PEACH) != nullptr)
			{
				Audio::Start(8);//�񕜉���炷
				m_hp += 3;
			}
			if (hit->CheckObjNameHit(OBJ_PLUM) != nullptr)
				Audio::Start(2);//�A�C�e���擾����炷

			if (hit->CheckObjNameHit(OBJ_HORN) != nullptr)
				Audio::Start(2);//�A�C�e���擾����炷

			if (hit->CheckObjNameHit(OBJ_GOLD_BULLION) != nullptr)
				Audio::Start(2);//�A�C�e���擾����炷

			if (hit->CheckObjNameHit(OBJ_SILVER_BULLION) != nullptr)
				Audio::Start(2);//�A�C�e���擾����炷

			if (hit->CheckObjNameHit(OBJ_CLUB) != nullptr)
				Audio::Start(9);//�f�o�t����炷
				//�ړ����x��0.8�{����
				//m_px *= 0.8;
				//m_py *= 0.8;

		}
	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		CObjMap1* map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);//�O���ƃG���[���o��
		map1->Setenemy(1);
		this->SetStatus(false);	//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����B

		Scene::SetScene(new CSceneGameOver());
	}
}

//�h���[
void CObjHero::Draw()
{
	int AniData[4] = { 0,1,2,1, };
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,alpha, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top   =50.0f *  m_posture - 1;	 //������-1
	src.m_left  = 0.0f + (AniData[m_ani_frame] * 48);
	src.m_right =48.0f + (AniData[m_ani_frame] * 48);
	src.m_bottom=50.0f * (m_posture + 1) - 3;//������-3

	//�\���ʒu�̐ݒ�
	dst.m_top   = 0.0f + m_py;
	dst.m_left  = 0.0f + m_px;
	dst.m_right =50.0f + m_px;
	dst.m_bottom=50.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}