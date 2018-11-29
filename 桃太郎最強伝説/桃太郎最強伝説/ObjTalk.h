#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：吹き出し
class CObjTalk : public CObj
{
public:
	CObjTalk(int t, int p) { m_tipe = t; m_p = p; }//コンストラクタ
	~CObjTalk() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	bool m_f;		//入力制御
	int m_tipe;		//動作の種類
	int m_p;		//渡されたページ数
	int m_page;		//ページ数
	int m_sec;		//セコンド(秒)
	int m_line;		//行数
	int m_picture;	//画像番号
};