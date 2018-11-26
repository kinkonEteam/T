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

					/*		//ブロックとの当たり判定
					void BlockHit(
					float *x, float *y, bool scroll_on,
					bool*up, bool* down, bool*left, bool*right,

					float*vx, float*vy, int*bt
					);

					//主人公と壁の交差判定
					bool HeroBlockCrossPoint(
					float x, float y, float vx, float vy,
					float *out_px, float *out_py, float *out_len
					);*/

private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	int m_map[56][56];//マップ情報
	int x, y;	//初期位置設定用変数

	float m_scroll;		//左右スクロール用

	float Dot(float ax, float ay, float bx, float by);	//内積
	float Cross(float ax, float ay, float bx, float by);//外積
};
