#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：犬イベント
class ObjItemEffe : public CObj
{
public:
	ObjItemEffe(int i) { m_item = i; }	//コンストラクタ
	~ObjItemEffe() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	int m_item;//1桃, 2黄桃, 3すもも, 4つの, 5金の延べ棒, 6銀の延べ棒, 7棍棒
};