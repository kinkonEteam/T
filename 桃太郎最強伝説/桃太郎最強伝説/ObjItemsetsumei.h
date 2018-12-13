#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトルに戻る
class CObjItemsetsumei : public CObj
{
public:
	CObjItemsetsumei() {};
	~CObjItemsetsumei() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー
private:


};


