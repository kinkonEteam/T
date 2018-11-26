#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define ITEM_KIND (2)
#define ITEM_NUM (6)

#define RANKING_POS_X		(600)
#define RANKING_POS_Y		(0)
#define RANKING_FONT_SIZE	(24)
#define RANKING_SCORE_MAX	(15)
#define STR_MAX				(256)
#define SCORE_INIT			(1)
#define SCORE_POS_X			(670)
#define SCORE_POS_Y			(24)
#define SCORE_POINT_MAX		(100)
#define SCORE_INTERVAL		(24)
#define SCORE_FONT_SIZE		(12)

//�I�u�W�F�N�g�F�L�����N�^�[�u���b�N
class CObjInventory : public CObj
{
public:
	CObjInventory() {};
	~CObjInventory() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	int item_list[20];
	bool item_id[ITEM_KIND][ITEM_NUM];//�A�C�e���ۑ��p:[���][��]

	
};





