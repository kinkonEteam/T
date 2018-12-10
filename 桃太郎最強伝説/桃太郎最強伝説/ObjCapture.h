#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：キャラクターブロック
class ObjCapture : public CObj
{
public:
	ObjCapture(int n) { m_num = n; }//コンストラクタ
	~ObjCapture() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

	void SetImage(int n) { m_num = n; }
private:
	int m_num;
};