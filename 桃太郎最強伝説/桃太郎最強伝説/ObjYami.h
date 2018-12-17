#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：キャラクターブロック
class ObjYami : public CObj
{
public:
	ObjYami(int n) { m_num = n; }//コンストラクタ
	~ObjYami() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	int m_num;
};