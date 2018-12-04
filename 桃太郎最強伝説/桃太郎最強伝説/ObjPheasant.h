#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;



//オブジェクト：キャラクターブロック
class CObjPheasant : public CObj
{
public:
	CObjPheasant(float x, float y);
	~CObjPheasant() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	void Setdf(bool pf) { m_pf = pf; }
private:
	float m_x;	//お供ヒットボックス用
	float m_y;	//お供ヒットボックス用
	float m_px;		 //位置
	float m_py;
	bool m_pf;
};

