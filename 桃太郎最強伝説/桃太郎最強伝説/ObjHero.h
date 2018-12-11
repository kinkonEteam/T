#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero :public CObj
{
	public:
		CObjHero(float x, float y) ;
		~CObjHero() {};
		void Init();	 //イニシャライズ
		void Action();	 //アクション
		void Draw();	 //ドロー

		float GetX() { return m_px; }
		float GetY() { return m_py; }
		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }
		float Gethp() { return m_hp; }
		int GetBT() { return m_block_type; }

		void SetX(float x) { m_px = x; }
		void SetY(float y) { m_py = y; }
		void SetVY(float vy) { m_vy = vy; }
		void SetVX(float vx) { m_vx = vx; }
		void SetBT(int t) { m_block_type = t; }
		void SaveDATA();//セーブ関数
		void SetDATA();//リセット関数(ゲームオーバー後、HPを初期値に戻す)
		void SetYAMI(bool tipe = true);//暗闇セット関数
		void PHP(int hp) { m_hp += hp; }//プラスHP関数(値をメンバhpに加算)
	private:

	//主人公の位置と移動用
		float m_px;			//プレイヤーの座標X
		float m_py;			//プレイヤーの座標X
		float m_vx;			//移動ベクトル(座標xの増分)
		float m_vy;			//移動ベクトル(座標yの増分)
		float m_speed;		//移動ベクトルに代入するスピード
		float alpha;		//(透過情報)


		int m_posture;		//姿勢
		int getmap[56][56]; //

		int m_hp;			//HP
		int m_hp_max;		//最大HP
		int m_map[56][56];//マップ情報
		int m_time;//無敵時間測定
		int m_f;//無敵時間
		int m_key_f;//無敵時間行動制御
		int m_t;
		int count;

		int m_ani_time;  //アニメーションフレーム動作間隔
		int m_ani_frame;	//描画フレーム
		bool m_Sf;			//ソード攻撃制御
		bool m_Kf;			//キジ攻撃制御
		bool m_Df;			//犬生存確認用
		bool m_If;		//持ち物リスト制御用
		bool m_Mf;		//持ち物リスト表示フラグ用

		//blockとの衝突状態確認用
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

		bool df;//犬イベントフラグ管理用
		bool mf;//猿イベントフラグ管理用
		bool pf;//雉イベントフラグ管理用

		//踏んでいるblockの種類を確認用
		int m_block_type;
		int m_image;		//暗闇の画像登録ナンバー(15,16,17)


};