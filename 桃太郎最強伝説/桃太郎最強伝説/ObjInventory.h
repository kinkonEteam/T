#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


#define RANKING_POS_X		(600)
#define RANKING_POS_Y		(24)
#define RANKING_FONT_SIZE	(32)
#define RANKING_SCORE_MAX	(15)
#define STR_MAX				(256)
#define SCORE_INIT			(1)
#define SCORE_POS_X			(600)
#define SCORE_POS_Y			(84)
#define SCORE_POINT_MAX		(100)
#define SCORE_INTERVAL		(48)
#define SCORE_FONT_SIZE		(24)

//�I�u�W�F�N�g�F�L�����N�^�[�u���b�N
class CObjInventory : public CObj
{
public:
	CObjInventory() {};
	~CObjInventory() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	void SetEf(bool ef) { m_Ef = ef; }
private:

	int peach;//�A�C�e���ۑ��p
	bool m_Ef; //�t���O

};





