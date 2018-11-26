#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjMap3 :public CObj
{
public:
	CObjMap3(int map[56][56]);
	~CObjMap3() {};
	void Init();	//�C�j�V����
	void Action();	//�A�N�V����
	void Draw();	//�h���[

					/*		//�u���b�N�Ƃ̓����蔻��
					void BlockHit(
					float *x, float *y, bool scroll_on,
					bool*up, bool* down, bool*left, bool*right,

					float*vx, float*vy, int*bt
					);

					//��l���ƕǂ̌�������
					bool HeroBlockCrossPoint(
					float x, float y, float vx, float vy,
					float *out_px, float *out_py, float *out_len
					);*/

private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	int m_map[56][56];//�}�b�v���
	int x, y;	//�����ʒu�ݒ�p�ϐ�

	float m_scroll;		//���E�X�N���[���p

	float Dot(float ax, float ay, float bx, float by);	//����
	float Cross(float ax, float ay, float bx, float by);//�O��
};
