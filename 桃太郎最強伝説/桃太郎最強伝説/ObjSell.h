#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class ObjSell : public CObj
{
public:
	ObjSell() {};
	~ObjSell() {};
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー
private:
	int m_page;
	int m_count;
	bool m_f;		//二回目のトーク作成用
	bool m_keyf;	//押しっぱなし制御
};