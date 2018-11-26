#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
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

//オブジェクト：キャラクターブロック
class CObjInventory : public CObj
{
public:
	CObjInventory() {};
	~CObjInventory() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	int item_list[20];
	bool item_id[ITEM_KIND][ITEM_NUM];//アイテム保存用:[種類][個数]

	
};





