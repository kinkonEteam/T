#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：犬イベント
class CObjSummary : public CObj
{
public:
	CObjSummary() {};	//コンストラクタ
	~CObjSummary() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	bool m_f;		//押しっぱ制御
	bool m_key_f;//エンターキー
	int m_page;		//コメントのページ
};