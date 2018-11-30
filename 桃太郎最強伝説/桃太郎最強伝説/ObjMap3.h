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

	//���E�X�N���[���p
	void SetScrollx(float s) { m_scrollx = s; }
	float GetScrollx() { return m_scrollx; }
	//�㉺�X�N���[���p
	void SetScrolly(float s) { m_scrolly = s; }
	float GetScrolly() { return m_scrolly; }

	void Setenemy(int f) { m_f = f; }

	int blocksize = 50.0f;

	//�u���b�N�Ƃ̓����蔻��
	void Map3Hit(
		float *x, float *y, bool scroll_on,
		bool*up, bool* down, bool*left, bool*right,

		float*vx, float*vy, int*bt
	);
private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	void ItemDraw(float x, float y, RECT_F* dst, float c[]);
	int m_id;
	int m_map[56][56];//�}�b�v���

	int m_f;//��l�����Ŏ��̃G���[���p

	float m_scrollx;		//���E�X�N���[���p
	float m_scrolly;	//�㉺�X�N���[���p

	float Dot(float ax, float ay, float bx, float by);	//����
	float Cross(float ax, float ay, float bx, float by);//�O��

	void setstair();//�K�i�o���p�֐�
	void sethero();//��l���o���p�֐�
	void setenemy();//�G�o���p�֐�
};
