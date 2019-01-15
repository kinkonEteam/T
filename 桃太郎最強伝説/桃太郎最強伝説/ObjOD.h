#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトルに戻る
class CObjOD : public CObj
{
public:
	CObjOD() {};
	~CObjOD() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー

private:
	bool m_key_f;//エンターキー
	bool m_Af; //フラグ

};


