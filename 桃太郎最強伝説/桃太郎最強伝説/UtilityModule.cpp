//使用するヘッダー
#include <math.h>   //数学計算ヘッダー
#include "GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;
bool UnitVec(float* vx, float* vy)
{
	//ベクトルの長さを求める(三平方の定理)
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	//長さが0かどうか調べる
	if (r == 0.0f)
	{
		//0なら計算失敗
		return false;
	}
	else
	{
		//正規化しvxとvyに格納
		(*vx) = 1.0f / r*(*vx);
		(*vy) = 1.0f / r*(*vy);
	}
	//計算成功
	return true;
}

//---CheckWindow関数
//引数 float pos_x    :領域外か調べるx位置
//引数 float pos_y    :領域外か調べるy位置
//引数 float window_x :領域のtop位置
//引数 float window_y :領域のleft位置
//引数 float window_w  :領域のright位置
//引数 float window_h  :領域のbottom位置
//戻り値 bool
//領域内かどうか調べる位置pos_(x,y)がwindow_(xywh)の中か外か調べる
bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h)
{
	//領域チェック
	if (pos_x < window_x)
	{
		return false;   //領域外
	}
	if (pos_x > window_w)
	{
		return false;   //領域外
	}
	if (pos_y < window_y)
	{
		return false;   //領域外
	}
	if (pos_y > window_h)
	{
		return false;   //領域外
	}

	return true;        //領域内
}