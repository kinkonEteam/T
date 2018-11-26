#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define ITEM_TOP	(111.0f)
#define ITEM_LEFT	(256.0f)

//オブジェクト：キャラクターブロック
class CObjPlum : public CObj
{
public:
	CObjPlum() {};
	~CObjPlum() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;	//アイテムヒットボックス用
	float m_y;	//アイテムヒットボックス用
	bool m_del;	//削除チェック


};





