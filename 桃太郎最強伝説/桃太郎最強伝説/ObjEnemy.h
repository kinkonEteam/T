#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵
class CObjEnemy :public CObj
{
public:
	CObjEnemy(float x, float y);
	~CObjEnemy() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

	float GetVx() { return m_vx; }

private:
	float m_px;		//位置
	float m_py;
	float m_vx;		//移動ベクトル
	float m_vy;
	float m_posture;//姿勢
	float alpha;

	int m_ani_time;	//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム
	int m_hp;//体力

	int m_time;//無敵時間測定
	int m_f;//無敵時間
	int m_key_f;//無敵時間行動制御
	int count;
	int e_time;//敵行動時間
	int enemy_move;//敵移動

	int m_ftime;//階層突入後の時間測定

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

	bool m_do_f;//敵攻撃フラグ
};