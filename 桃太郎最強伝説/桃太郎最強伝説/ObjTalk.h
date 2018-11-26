#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：吹き出し
class CObjTalk : public CObj
{
public:
	CObjTalk(/*char* t*/) {/* m_pward = t; */ };//コンストラクタ
	~CObjTalk() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	char* m_pward;
};