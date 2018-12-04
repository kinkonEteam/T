#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトルに戻る
class CObjSosasetsumei : public CObj
{
public:
	CObjSosasetsumei() {};
	~CObjSosasetsumei() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー
private:


};


