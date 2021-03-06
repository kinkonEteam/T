#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：犬イベント
class CObjEveKiji : public CObj
{
public:
	CObjEveKiji() {};	//コンストラクタ
	~CObjEveKiji() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	bool m_f;		//押しっぱ制御
	int m_page;		//コメントのページ
	bool m_df;	//雉削除用
};