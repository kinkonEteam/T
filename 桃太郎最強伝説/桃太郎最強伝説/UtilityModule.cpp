//�g�p����w�b�_�[
#include <math.h>   //���w�v�Z�w�b�_�[
#include "GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
bool UnitVec(float* vx, float* vy)
{
	//�x�N�g���̒��������߂�(�O�����̒藝)
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	//������0���ǂ������ׂ�
	if (r == 0.0f)
	{
		//0�Ȃ�v�Z���s
		return false;
	}
	else
	{
		//���K����vx��vy�Ɋi�[
		(*vx) = 1.0f / r*(*vx);
		(*vy) = 1.0f / r*(*vy);
	}
	//�v�Z����
	return true;
}

//---CheckWindow�֐�
//���� float pos_x    :�̈�O�����ׂ�x�ʒu
//���� float pos_y    :�̈�O�����ׂ�y�ʒu
//���� float window_x :�̈��top�ʒu
//���� float window_y :�̈��left�ʒu
//���� float window_w  :�̈��right�ʒu
//���� float window_h  :�̈��bottom�ʒu
//�߂�l bool
//�̈�����ǂ������ׂ�ʒupos_(x,y)��window_(xywh)�̒����O�����ׂ�
bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h)
{
	//�̈�`�F�b�N
	if (pos_x < window_x)
	{
		return false;   //�̈�O
	}
	if (pos_x > window_w)
	{
		return false;   //�̈�O
	}
	if (pos_y < window_y)
	{
		return false;   //�̈�O
	}
	if (pos_y > window_h)
	{
		return false;   //�̈�O
	}

	return true;        //�̈��
}
//---GetAtan2Anble�֐�
//����1 float w     :��
//����2 float h     :����
//�߂�l�@float     :�p�x(0���`�@360��)
//���e
//�����ƕ����璼�p�O�p�`������Ɖ��肵���̊p�x�����߂�B
float GetAtan2Angle(float w, float h)
{
	//rratan2�Ŋp�x�����߂�
	float r = atan2(h, w)*180.0f / 3.14f;

	//-180���`-0����180���`260���ɕϊ�
	if (r < 0)
	{
		r = 360 - fabs(r);
	}

	return r;
}

//---GetBulletEffec�֐�
//����1
//����2
//����3
//����4
//�߂�l
//del�Œe�ۂ�RECT�⒅�eeffect
RECT_F GetBulletEffec(int* ani, int* ani_time, bool del, int timing)
{
	//�Ԃ�RECT���
	RECT_F rect;

	//�u���O�Œʏ�e�ۂ����e�A�j���[�V������������
	if (del == true)
	{
		//���e�A�j���[�V����
		//���\�[�X���e�A�j���[�V�����ʒu
		RECT_F ani_src[4] =
		{
			{ 32, 0, 32, 64 },
			{ 32,32,64,64 },
			{ 32,64,96,64 },
			{ 32,96,128,64 },
		};
		//�A�j���[�V�����̃R�}�ԁ@
		if (*ani_time > timing)
		{
			*ani += 1;
			*ani_time = 0;
		}
		else
		{
			*ani_time += 1;
		}

		rect = ani_src[*ani];

	}
	else
	{
		//�e�ۂ̓A�j���[�V��������
		//���\�[�X�e�ۈʒu
		RECT_F bullet = { 0.0f,96.0f,126.0f,32.0f };
		rect = bullet;
	}

	return rect;
}




