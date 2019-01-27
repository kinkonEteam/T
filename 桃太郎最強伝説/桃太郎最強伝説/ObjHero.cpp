//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "ObjInventory.h"
#include "GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//Date.cpp���Ő錾�����O���[�o���ϐ���extern�錾----------------------�ێ��f�[�^
extern int HP;				//HP
extern bool OTOMO[3];		//�����������
extern int item_list[7];	//
extern int c, s, m;
void CObjHero::SaveDATA() {		//�Z�[�u�֐�----------------------�f�[�^���Z�[�u
	HP = m_hp;					//�V�[���؂�ւ�����hp�f�[�^���AHP�֊i�[
	ObjCharView* cv = (ObjCharView*)Objs::GetObj(OBJ_CV);//�I�u�W�F���擾
	cv->SaveSM();//�Z�[�u�A�Z�R���h�~�j�b�c
}
void CObjHero::SetDATA() {		//�Z�b�g�֐�----------------------�f�[�^���Z�b�g
	HP = 5;						//�Q�[���I�[�o�[��AHP�������l�ɖ߂�
	for (int n = 0; n <= 2; n++)
		OTOMO[n] = false;
	c = 0, s = 0, m = 0;
}
//�V�[���\�����̈Èō쐬()���́A�C�x���g����֐����g���ĈÈł��J�����Ă�����(false)
void CObjHero::SetYAMI(bool tipe) {//�ÈŃZ�b�g�֐�-----------------------�È�
	m_image = 15;				//������
	for (int nam = 0; nam < 3; nam++) {//�����̐����m�F���ĉ摜�ԍ����
		if (OTOMO[nam] == true)	//�e����������Ȃ�
			m_image += 1;		//�摜�ԍ�+1
	}
	if (tipe == true){			//SetYAMI(true or ��)
		ObjCapture* yami = new ObjCapture(m_image);	//�Èō쐬
		Objs::InsertObj(yami, OBJ_CAPTURE, 3);		//�o�^
	}
	else{						//SetYami(false)
		ObjCapture* yami = (ObjCapture*)Objs::GetObj(OBJ_CAPTURE);
		yami->SetImage(m_image);
	}
}

CObjHero::CObjHero(float x, float y)
{//�I�u�W�F�쐬���ɓn���ꂽx,y���W�������o�ϐ��ɑ��
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_hp_max = 5;		//�����ő�HP
	m_speed = 1.0f;			//���x

	
	m_Sf = true;		//�\�[�h����
	m_Kf = true;		//  �L�W����

	//OTOMO[0��,1�L�W,2��] == true(����) or false(�Ȃ�)
	if (OTOMO[0] == true)		//��������ꍇ
	{
		m_hp_max = 6;			//�ő�HP��6�ɃZ�b�g
	}
	if (OTOMO[1] == true)		//��������ꍇ
	{
		m_speed = 1.2f;			//���x
	}
	if (OTOMO[2] == true)		//�L�W������ꍇ
	{
		m_Kf = false;			//���������
	}
	SetYAMI();					//�Èō쐬
	

	m_hp = HP;				//�����ohp��HP����
	m_time = 70;
	alpha = 1.0f;
	count = 10;

	m_posture = 0;	//����(0) ��(1) �E(2) �w��(3)
	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[��
	m_key_f = false;		//���G���ԍs������
	m_If = true;			//���������X�g����
	m_Mf = false;			//���������X�g�\���t���O�Ǘ�
	m_Pf = false;
	m_Pf1 = true;
	m_stime = 13;
	m_Sf = true;
	m_of = true;
	m_of_d = false;

	df = true;
	mf = true;
	pf = true;
	

	//HitBox�쐬���W�ƃT�C�Yx,y�A�G�������g�ƃI�u�W�F�N�g��ݒ�
	Hits::SetHitBox(this, m_px + 5, m_py + 3, 40, 47, ELEMENT_PLAYER, OBJ_HERO, 1);

	Audio::LoadAudio(2, L"�A�C�e���Q�b�g.wav", EFFECT);		//�A�C�e���擾��SE
	Audio::LoadAudio(3, L"�ߐڍU��.wav", EFFECT);			//�ߐڍU��SE
	Audio::LoadAudio(4, L"kijiSE.wav", EFFECT);				//�������U��SE
	Audio::LoadAudio(5, L"damage.wav", EFFECT);				//�_���[�WSE
	Audio::LoadAudio(6, L"heal.wav", EFFECT);				//�̗͉񕜎�SE
	Audio::LoadAudio(7, L"speeddown.wav", EFFECT);			//���_�擾���pSE
	Audio::LoadAudio(8, L"ButtonSE.wav", EFFECT);				//�R�}���hSE

																//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//BGM�{�����[����������
	float Volume = Audio::VolumeMaster(-0.95f);

}

//�A�N�V����
void CObjHero::Action()
{
	//�x�N�g��������
	m_vx = 0.0f;
	m_vy = 0.0f;

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + 5, m_py + 3);//HitBox��l�����W + �ʒu����


	//�e�����擾
	CObjPose* pob = (CObjPose*)Objs::GetObj(OBJ_POSE);
	CObjInventory* iob = (CObjInventory*)Objs::GetObj(OBJ_INVENTORY);
	CObjOD* od = (CObjOD*)Objs::GetObj(OBJ_OD);

	//��������\�����͓�����~�߂�
	if (od != nullptr)
	{
		m_key_f = true;
	}

	//�|�[�Y
	if (pob == nullptr)
		m_Pf = false;
	while (1)
	{
		if (Input::GetVKey('M') == true)//M�L�[���͎�
		{

			if (m_Pf == true) {//m_f��true�̏ꍇ
							   //�R�}���h�pSE��炷
				if (od == nullptr || iob == nullptr)
				{
					Audio::Start(8);
					while (1)
					{
						//�|�[�Y���\������Ă�����|�[�Y���\���ɂ���

						if (m_Pf == true)
						{
							//X��������Title�Ɉڍs����
							if (Input::GetVKey('Z') == true)
							{
								//�^�C�g���Ɉړ�
								Scene::SetScene(new CSceneTitle());
								break;

							}
						}
						if (Input::GetVKey('X') == true)//Z�L�[���͎�
						{
							if (m_Pf == true) {

								Audio::Start(8);
								//�|�[�Y�I�u�W�F�N�g���폜
								if (pob != nullptr)
									pob->SetAf(true);
								break;
							}
						}

					}
				}

			}

			if (m_Pf == false) {
				//�|�[�Y�I�u�W�F�N�g�쐬
				CObjPose* po = new CObjPose();       //�|�[�Y�I�u�W�F�N�g�쐬
				Objs::InsertObj(po, OBJ_POSE, 11);    //�|�[�Y�I�u�W�F�N�g�o�^
				m_Pf = true;

			}
			else {}
		}
		break;
	}



	//���������X�g------------------------------------------------------------------------------
	//

	if (iob == nullptr)
		m_Mf = false;
	if (Input::GetVKey('I') == true)//I�L�[���͎�
	{

		if (m_If == true)
		{
			if (od == nullptr || pob == nullptr)
			{
				//�R�}���h�pSE��炷
				Audio::Start(8);
				//���������X�g���\������Ă����玝�������X�g���\���ɂ���
				if (m_Mf == true) {
					if (iob != nullptr)
						iob->SetEf(true);
				}

				if (m_Mf == false)
				{
					//���������X�g�\��
					CObjInventory* it = new CObjInventory();       //�������I�u�W�F�N�g�쐬
					Objs::InsertObj(it, OBJ_INVENTORY, 50);    //�������I�u�W�F�N�g�o�^
															   //��\���t���O�𗧂Ă�
					m_Mf = true;
				}
				m_If = false;
			}
		}
	}
	else //�����͎�
	{
		m_If = true;

	}

	//�������

	if (od == nullptr)
		m_of_d = false;
	if (Input::GetVKey('H') == true)//H�L�[���͎�
	{

		if (m_of == true)
		{
			if (od == nullptr || pob == nullptr)
			{
				//�R�}���h�pSE��炷
				Audio::Start(8);
				//����������\���ɂ���
				if (m_of_d == true) {
					od->SetOf(true);
				}

				if (m_of_d == false)
				{
					//��������\��
					CObjOD* od = new CObjOD();       //�������I�u�W�F�N�g�쐬
					Objs::InsertObj(od, OBJ_OD, 50);    //�������I�u�W�F�N�g�o�^
					//��\���t���O�𗧂Ă�
					m_of_d = true;
				}
				m_of = false;
			}
		}
	}
	else //�����͎�
	{
		m_of = true;

	}



	//�ʏ�U������---------------------------------------------------------------------
	if (m_key_f == false)
	{
		if (Input::GetVKey('A') == true && hit->CheckElementHit(ELEMENT_RED) == false)//A�L�[���͎������Ƃ��ɓ������Ă��Ȃ��Ƃ�
		{
			CObjSword* sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);//���̏����擾
			if (sword == nullptr)//���������ꍇ
			{
				if (m_Sf == true) {//m_f��true�̏ꍇ
					//�ߋ����U������炷
					Audio::Start(3);
					//���I�u�W�F�N�g�쐬			���ɍ��W�ƌ�����n��
					CObjSword* swd = new CObjSword(m_px, m_py, m_posture);
					Objs::InsertObj(swd, OBJ_SWORD, 3);//�}�l�[�W���[�ɓo�^

					m_Sf = false;
				}
			}
		}
		else		//�����Ă���ꍇ
			m_Sf = true;//true����

		//�L�W�U������------------------------------------------------------------------
		//�L�W�̏����擾
		CObjFlyKiji* obj = (CObjFlyKiji*)Objs::GetObj(OBJ_FLYKIJI);
		if (Input::GetVKey('S') == true && hit->CheckElementHit(ELEMENT_RED) == false)//S�L�[���͎������Ƃ��ɓ������Ă��Ȃ��Ƃ�
		{
			if (m_Kf == false) {
				if (obj == nullptr)//�L�W��񂪖����ꍇ
				{
					//�������U������炷
					Audio::Start(4);

					//�L�W�I�u�W�F�N�g�쐬				�L�W�ɍ��W�ƌ�����n��
					CObjFlyKiji* kiji = new CObjFlyKiji(m_px, m_py, m_posture);
					Objs::InsertObj(kiji, OBJ_FLYKIJI, 3);//�}�l�[�W���[�ɓo�^

				}
			}
		}




		//��l���ړ��L�[���͔���--------------------------------------------------------
		if (Input::GetVKey(VK_RIGHT) == true)//��
		{
			m_vx += m_speed;				//�ړ��x�N�g�����Z(�����l1,�����o�t1.5)
			m_posture = 2;					//���������
			m_ani_time += 1;				//�A�j���[�V�������ԉ��Z
		}
		else if (Input::GetVKey(VK_UP) == true)	//��
		{
			m_vy -= m_speed;
			m_posture = 3;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_DOWN) == true)//��
		{
			m_vy += m_speed;
			m_posture = 0;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_LEFT) == true)//��
		{
			m_vx -= m_speed;
			m_posture = 1;
			m_ani_time += 1;
		}
		else//�ړ��L�[�̓��͂������ꍇ
		{
			m_ani_frame = 1;	//�Î~�t���[���ɂ���
			m_ani_time = 0;		//�A�j���[�V�������ԃ��Z�b�g
		}
	}

	//�A�j���[�V��������Ԋu(�����ŃA�j���[�V�������x�ύX)---------------------------------
	if (m_ani_time > 6)		//���Ԃ�6���傫���ꍇ
	{
		m_ani_frame += 1;	//�t���[���ϐ������Z���A�؂�ւ���
		m_ani_time = 0;		//���Ԃ�0����
	}

	if (m_ani_frame == 4)	//�t���[����4�̏ꍇ
		m_ani_frame = 0;	//�t���[����0����

	//�ړ��x�N�g���̐��K��	�΂߈ړ����Ȃ��וs�v
	//UnitVec(&m_vy, &m_vx);

	//�X�N���[��
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);
	m_px = 375;
	m_py = 275;

	//�u���b�N�Ƃ̓����蔻��
	if (map1 != nullptr)
	{
		map1->Map1Hit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);
	}
	if (map2 != nullptr)
	{
		map2->Map2Hit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);
	}
	if (map3 != nullptr)
	{
		map3->Map3Hit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);
	}
	if (map4 != nullptr)
	{
		map4->Map4Hit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);
	}
	if (map5 != nullptr)
	{
		map5->Map5Hit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);
	}

	//ELEMENT_ENEMY�����I�u�W�F�N�g�ƐڐG������
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		HIT_DATA**hit_data;		//Hit���f�[�^�^�Ahit_data��錾
		hit_data = hit->SearchElementHit(ELEMENT_ENEMY);//hit_data�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

		for (int i = 0; i < hit->GetCount(); i++)//�����ɕ�����HitBox�ɓ��������ꍇ�A
		{										 //������������������������ׂ̃��[�v
			//�G�̍��E�ɓ���������
			if (hit_data[i] == nullptr)
				continue;

			//�_���[�W����炷
			Audio::Start(5);

			float r = hit_data[i]->r;
			if ((r < 45 && r >= 0) || r > 315)
			{
				m_vx = -10.0f;//���Ɉړ�������
			}
			if (r >= 45 && r < 135)
			{
				m_vy = 10.0f;//��Ɉړ�������
			}
			if (r >= 135 && r < 225)
			{
				m_vx = 10.0f;//�E�Ɉړ�������
			}
			if (r >= 225 && r < 315)
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
		if (m_hp != m_hp_max) {//HP���ő�l�łȂ��ꍇ�̂݉�
			if (hit->CheckObjNameHit(OBJ_PEACH) != nullptr)
			{
				m_hp += 1; //HP��1��
				Audio::Start(6);//�񕜉���炷
			}
			else if (hit->CheckObjNameHit(OBJ_YELLOW_PEACH) != nullptr)
			{
				if (m_hp < m_hp_max - 1) {
					m_hp += 2;		//HP��2��
				}
				else {
					m_hp += 1;	//HP��1��
				}
				Audio::Start(6);//�񕜉�			
			}
			else if (hit->CheckObjNameHit(OBJ_PLUM) != nullptr)
			{
				item_list[2]++;
				Audio::Start(2);//�A�C�e���擾��
			}
			else if (hit->CheckObjNameHit(OBJ_HORN) != nullptr)
			{
				item_list[3]++;
				Audio::Start(2);//�A�C�e���擾��
			}
			else if (hit->CheckObjNameHit(OBJ_GOLD_BULLION) != nullptr)
			{

				item_list[4]++;
				Audio::Start(2);//�A�C�e���擾��
			}
			else if (hit->CheckObjNameHit(OBJ_SILVER_BULLION) != nullptr)
			{
				item_list[5]++;
				Audio::Start(2);//�A�C�e���擾��
			}
			else if (hit->CheckObjNameHit(OBJ_CLUB) != nullptr)
			{
				item_list[6]++;
				Audio::Start(7);//�f�o�t��
			}
		}
		else //�ő�l�̏ꍇ�A�񕜏o���Ȃ�
		{
			if (hit->CheckObjNameHit(OBJ_PEACH) != nullptr)
			{
				item_list[0]++;
				Audio::Start(2);//�A�C�e���擾��
			}
			else if (hit->CheckObjNameHit(OBJ_YELLOW_PEACH) != nullptr)
			{
				item_list[1]++;
				Audio::Start(2);//�A�C�e���擾��			
			}
			else if (hit->CheckObjNameHit(OBJ_PLUM) != nullptr)
			{
				item_list[2]++;
				Audio::Start(2);//�A�C�e���擾��
			}
			else if (hit->CheckObjNameHit(OBJ_HORN) != nullptr)
			{
				item_list[3]++;
				Audio::Start(2);//�A�C�e���擾��
			}
			else if (hit->CheckObjNameHit(OBJ_GOLD_BULLION) != nullptr)
			{
				item_list[4]++;
				Audio::Start(2);//�A�C�e���擾��
			}
			else if (hit->CheckObjNameHit(OBJ_SILVER_BULLION) != nullptr)
			{
				item_list[5]++;
				Audio::Start(2);//�A�C�e���擾��
			}
			else if (hit->CheckObjNameHit(OBJ_CLUB) != nullptr)
			{
				item_list[6]++;
				Audio::Start(7);//�f�o�t��
			}
		}
	}


	//���Ƃ��̓����蔻��
	HIT_DATA**hit_data;		//Hit���f�[�^�^�Ahit_data��錾
	hit_data = hit->SearchElementHit(ELEMENT_RED);//hit_data�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

	for (int i = 0; i < hit->GetCount(); i++)//�����ɕ�����HitBox�ɓ��������ꍇ�A
	{										 //������������������������ׂ̃��[�v
		if (hit_data[i] == nullptr)
			continue;
		float r = hit_data[i]->r;
		if ((r < 45 && r >= 0) || r > 315)
		{
			if (Input::GetVKey(VK_RIGHT) == true) //��
				m_vx = 0.0f;
		}
		if (r >= 45 && r < 135)
		{
			if (Input::GetVKey(VK_UP) == true)//��
				m_vy = 0.0f;
		}
		if (r >= 135 && r < 225)
		{
			if (Input::GetVKey(VK_LEFT) == true)//��
				m_vx = 0.0f;
		}
		if (r >= 225 && r < 315)
		{
			if (Input::GetVKey(VK_DOWN) == true)//��
				m_vy = 0.0f;
		}
	}

	//���Ƃ��C�x���g
	if (hit->CheckElementHit(ELEMENT_RED) == true)
	{
		if (Input::GetVKey('F') == true)//F�L�[���͎�
		{
			//���������X�g���J���Ă��������
			CObjInventory* iob = (CObjInventory*)Objs::GetObj(OBJ_INVENTORY);
			if (iob != nullptr)
				iob->SetEf(true);


				if (hit->CheckObjNameHit(OBJ_DOG) && df ==true)//���ɓ��������ꍇ
				{
					//���C�x���g����
					CObjEveDog* evedog = new CObjEveDog();//�I�u�W�F�N�g�쐬
					Objs::InsertObj(evedog, OBJ_EVEDOG, 10);//�}�l�[�W���ɓo�^

				df = false;

				m_hp_max = 6;
				OTOMO[0] = true;
			}
			else if (hit->CheckObjNameHit(OBJ_MONKE) && mf == true)//���ɓ��������ꍇ
			{
				//���C�x���g����
				CObjEveMnky* evemonky = new CObjEveMnky();//�I�u�W�F�N�g�쐬
				Objs::InsertObj(evemonky, OBJ_EVEMNKY, 10);//�}�l�[�W���ɓo�^

				mf = false;

				m_speed = 1.2f;
				OTOMO[1] = true;
			}
			else if (hit->CheckObjNameHit(OBJ_PHEASANT) && pf == true)//�L�W�ɓ��������ꍇ
			{
				//賃C�x���g����
				CObjEveKiji* kiji = new CObjEveKiji();//�I�u�W�F�N�g�쐬
				Objs::InsertObj(kiji, OBJ_EVEKIJI, 10);//�}�l�[�W���ɓo�^

				pf = false;

				m_Kf = false;
				OTOMO[2] = true;
			}
		}
	}

		//��l���̏����擾
		CObjEveDog* evedog = (CObjEveDog*)Objs::GetObj(OBJ_EVEDOG);
		CObjEveKiji* evekiji = (CObjEveKiji*)Objs::GetObj(OBJ_EVEKIJI);
		CObjEveMnky* evemnky = (CObjEveMnky*)Objs::GetObj(OBJ_EVEMNKY);
		CObjText* text = (CObjText*)Objs::GetObj(OBJ_TEXT);
		if (text != nullptr || evedog != nullptr || evekiji != nullptr || evemnky != nullptr)
		{
			m_key_f = true;
		}
		else
			m_key_f = false;

	//HP��0�ɂȂ�����j��------���S����----------------------------------------------------------------
	if (m_hp <= 0)
	{
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//��l���f�[�^�擾
		hero->SetDATA();//��l���̃f�[�^��������

		this->SetStatus(false);	//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����B

		Scene::SetScene(new CSceneGameOver());
	}
	else {}

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