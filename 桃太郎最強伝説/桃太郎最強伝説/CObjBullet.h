#pragma once
//使用するヘッダー
#include"GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjBullet : public CObj
{
public:
	CObjBullet(float x, float);//コントラクタ
	~CObjBullet() {};
	void Init();     //イニシャライズイニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー
private:
	float  m_x;       //弾丸のx方向の位置用変数
	float  m_y;       //弾丸のＹ方向の位置用変数
	float  m_vx;      //弾丸のｘ方向の速度用変数
	float  m_vy;

	int    m_ani;     //着弾アニメーション用
	int    m_ani_time;//着弾アニメーション間タイム
	bool   m_del;     //削除チェック
	RECT_F m_eff;     //着弾エフェクト描画用
};