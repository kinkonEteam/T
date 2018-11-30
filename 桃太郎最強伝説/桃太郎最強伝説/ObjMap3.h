#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjMap3 :public CObj
{
public:
	CObjMap3(int map[56][56]);
	~CObjMap3() {};
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

	int blocksize = 50.0f;

	//ブロックとの当たり判定
	void Map3Hit(
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

	float Dot(float ax, float ay, float bx, float by);	//内積
	float Cross(float ax, float ay, float bx, float by);//外積

	void setstair();//階段出現用関数
	void sethero();//主人公出現用関数
	void setenemy();//敵出現用関数
};
