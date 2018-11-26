#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：犬イベント
class CObjEveDog : public CObj
{
public:
	CObjEveDog() {};	//コンストラクタ
	~CObjEveDog() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	char* m_pward;
	bool m_f;
};