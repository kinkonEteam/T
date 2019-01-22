#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjMap5 :public CObj
{
public:
	CObjMap5(int map[56][56]);
	~CObjMap5() {};
	void Init();	//イニシャル
	void Action();	//アクション
	void Draw();	//ドロー

					//左右スクロール用
	void SetScrollx(float s) { m_scrollx = s; }
	float GetScrollx() { return m_scrollx; }
	//上下スクロール用
	void SetScrolly(float s) { m_scrolly = s; }
	float GetScrolly() { return m_scrolly; }

	void Setenemy(int f) { m_f = f; }
	void Setwall(bool type = true);//隠し通路セット関数

	int blocksize = 50.0f;

	//ブロックとの当たり判定
	void Map5Hit(
		float *x, float *y, bool scroll_on,
		bool*up, bool* down, bool*left, bool*right,

		float*vx, float*vy, int*bt
	);
private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	void ItemDraw(float x, float y, RECT_F* dst, float c[]);
	int m_id;
	int m_map[56][56];//マップ情報

	int m_f;//主人公消滅時のエラー回避用

	float m_scrollx;		//左右スクロール用
	float m_scrolly;	//上下スクロール用

	void setenemy();//敵出現用関数
};
