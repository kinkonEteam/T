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
	m_vx = -1.0f;
	m_vy = 0.0f;
	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);
	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x, m_y, 50, 50, ELEMENT_ENEMY, OBJ_BULLET, 1);
}

//�A�N�V����
void CObjHomingfire::Action()
{
	//��l���@�ƗU���e�ۂŊp�x�����
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (obj != nullptr)
	{
		CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);
		
		float x = 400 - (m_x + map5->GetScrollx());
		float y = 300 - (m_y + map5->GetScrolly());
		float ar = GetAtan2Angle(x, y);

		//�e�ۂ̌��݂̌����Ă���p�x�����
		float br = GetAtan2Angle(m_vx, m_vy);

		//��l���@�ƓG�@�p�x������܂�ɂ��������ꂽ��
		m_vx = cos(3.14 / 180 * ar);
		m_vy = sin(3.14 / 180 * ar);
		
		UnitVec(&m_vx, &m_vy);
	}
	//�ړ�
	m_x += m_vx * 3.0f;
	m_y += m_vy * 3.0f;

	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + map5->GetScrollx(), m_y + map5->GetScrolly());

	//��l���I�u�W�F�N�g�ƐڐG������G�@�e�ۍ폜
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr || hit->CheckElementHit(ELEMENT_MAGIC) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}
//�h���[
void CObjHomingfire::Draw()
{
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;

	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 300.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y + map5->GetScrolly();
	dst.m_left = 0.0f + m_x + map5->GetScrollx();
	dst.m_right = 50.0f + m_x + map5->GetScrollx();
	dst.m_bottom = 50.0f + m_y + map5->GetScrolly();

	float r = 0.0f;
	//��l���@�ƗU���e�ۂŊp�x�����
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (obj != nullptr)
	{
		float x = 375 - dst.m_top;
		float y = 275 - dst.m_left;
		r = GetAtan2Angle(x, y)+30;

	}
	//8�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̌��ɕ`��
	Draw::Draw(10, &src, &dst, c, r);

}