#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjMap5 :public CObj
{
public:
	CObjMap5(int map[56][56]);
	~CObjMap5() {};
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
	void Setwall(bool type = true);//�B���ʘH�Z�b�g�֐�

	int blocksize = 50.0f;

	//�u���b�N�Ƃ̓����蔻��
	void Map5Hit(
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

	void setenemy();//�G�o���p�֐�
};
