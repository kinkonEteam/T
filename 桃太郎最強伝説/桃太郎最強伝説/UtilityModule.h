//プロトタイプ宣言
bool UnitVec(float* vx, float* vy);//ベクトルの正規化

bool CheckWindow(float pos_x, float pos_y,//領域内か調べる関数
	float window_x, float window_y, float window_w, float window_h);
float GetAtan2Angle(float w, float h);//高さと幅で角度を求める

RECT_F GetBulletEffec(int* ani, int* ani_time, bool del, int timing);//delで弾丸のRECTや着弾effectのRECT(アニメーションRECT)を返す