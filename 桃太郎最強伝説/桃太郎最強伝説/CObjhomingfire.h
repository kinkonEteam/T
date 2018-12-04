#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ホーミング弾丸
class CObjHomingfire : public CObj
{
public:
	CObjHomingfire(float x, float y);
	~CObjHomingfire() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー
private:
	float m_x;  //オブジェクトの位置x
	float m_y;  //オブジェクトの位置y
	float m_vx; //オブジェクトの移動用ベクトルx
	float m_vy; //オブジェクトの移動用ベクトルy
};