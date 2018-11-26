//�g�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"CObjhomingfire.h"
#include"GameHead.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjHomingfire::CObjHomingfire(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjHomingfire::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	m_vx = -1.0f;
	m_vy = 0.0f;
	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);
	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_BULLET, 1);
}

//�A�N�V����
void CObjHomingfire::Action()
{
	//Resources�̕`�敨��RECT
	m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 2);

	//�e�ۏ��ŏ��� -----
	if (m_del == true)
	{
		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j��
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������
	}


	//��l���@�ƗU���e�ۂŊp�x�����
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (obj != nullptr)
	{

		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		float ar = GetAtan2Angle(x, -y);

		//�e�ۂ̌��݂̌����Ă���p�x�����
		float br = GetAtan2Angle(m_vx, -m_vy);

		//��l���@�ƓG�@�p�x������܂�ɂ��������ꂽ��
		if (ar - br > 20)
		{
			//�ړ���������l���@�̕����ɂ���
			m_vx = cos(3.14 / 180 * ar);
			m_vy = -sin(3.14 / 180 * ar);
		}

		float r = 3.14 / 180.0f;      //�p�x1��
		if (ar < br)
		{
			//�ړ�������+�P��������
			m_vx = m_vx*cos(r) - m_vy*sin(r);
			m_vy = m_vy*cos(r) + m_vx*sin(r);
		}
		else
		{
			//�ړ�������-�P��������
			m_vx = m_vx*cos(-r) - m_vy*sin(-r);
			m_vy = m_vy*cos(-r) + m_vx*sin(-r);

		}
		UnitVec(&m_vx, &m_vy);
	}
	//�ړ�
	m_x += m_vx * 5.0f;
	m_y += m_vy * 5.0f;

	//�U���e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�U���e�ۂ����S�ɗ̈�O�ɏo����U���e�ۂ�j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);   //�G�@�e�ۂ����L����HitBox�ɍ폜
	}

	//��l���@�I�u�W�F�N�g�ƐڐG������G�@�e�ۍ폜
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		m_del = true;
		hit->SetInvincibility(true);
	}
}
//�h���[
void CObjHomingfire::Draw()
{
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	float r = 0.0f;
	//��l���@�ƗU���e�ۂŊp�x�����
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		r = GetAtan2Angle(x, -y);

	}
	//8�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̌��ɕ`��
	Draw::Draw(8, &m_eff, &dst, c, r);

}