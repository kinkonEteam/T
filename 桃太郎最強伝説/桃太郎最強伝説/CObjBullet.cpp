//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjBullet.h"

//�C�j�V�����C�Y
void CObjBullet::Init()
{
	m_vx = 0.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);

	

}

//�A�N�V����
void CObjBullet::Action()
{
	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�e�ۂƐڐG���Ă��邩�𒲂ׂ�
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);  //�폜����
		Hits::DeleteHitBox(this);//HitBox�폜
	}

	//�̈�O�ɏo����e�ۂ�j������
	if (m_x > 800.0f)
	{
		this->SetStatus(false);
	}
    

}

//�h���[
void CObjBullet::Draw()
{
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;


	Draw::Draw(8, &m_eff, &dst, c, 0.0f);
}