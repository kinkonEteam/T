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
};