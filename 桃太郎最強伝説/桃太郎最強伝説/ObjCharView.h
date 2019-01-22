#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

extern int c;
extern int s;
extern int m;

//オブジェクト:タイトル
class ObjCharView : public CObj
{
public:
	ObjCharView() {};
	~ObjCharView() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	void SaveSM() { c = count; s = sec, m = min; }//セーブ、セコンドミニッツ
private:
	int count;			//カウント用
	int sec;			//セコンド(秒)
	int min;			//ミニッツ(分)
};