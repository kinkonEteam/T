#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;



//オブジェクト：キャラクターブロック
class CObjMonke : public CObj
{
public:
	CObjMonke(float x, float y);
	~CObjMonke() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;	//お供ヒットボックス用
	float m_y;	//お供ヒットボックス用
	float m_px;		 //位置
	float m_py;
};

