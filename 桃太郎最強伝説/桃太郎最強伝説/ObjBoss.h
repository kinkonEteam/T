#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵
class CObjBoss :public CObj
{
public:
	CObjBoss(float x, float y);
	~CObjBoss() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

private:
	float m_x;		//位置
	float m_y;
	float m_vx;		//移動ベクトル
	float m_vy;
	float m_posture;//姿勢
	float alpha;

	int m_ani_time;	//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム
	int m_hp;       //ボスのヒットポイント
	int m_firetime;     //ファイア間隔

	int m_time;//無敵時間測定
	int m_f;//無敵時間
	int m_key_f;//無敵時間行動制御
	int m_t;
	int count;

	float m_speed_power;	//通常速度
	float m_ani_max_time;	//アニメーション動作間隔最大値

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//移動用の向き制御用
	bool m_movex;//左右
	bool m_movey;//上下

	bool knock;
};