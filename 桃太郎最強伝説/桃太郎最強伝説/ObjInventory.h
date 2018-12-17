#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
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

//オブジェクト：キャラクターブロック
class CObjInventory : public CObj
{
public:
	CObjInventory() {};
	~CObjInventory() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	void SetEf(bool ef) { m_Ef = ef; }
private:

	int peach;//アイテム保存用
	bool m_Ef; //フラグ

};





