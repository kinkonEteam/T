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