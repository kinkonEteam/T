#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：あらすじ
class CObjSummary : public CObj
{
public:
	CObjSummary(){};
	~CObjSummary(){};
	void Init();
	void Action();
	void Draw();
	
private:
	int m_time;     //時間
	bool m_key_f;//エンターキー
	float m_y;//スクロール用
	int m_ky;//一行の間隔
	
	
};
