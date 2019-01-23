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
	void SetOf(bool of) { m_Of = of; }

private:
	bool m_Af; //フラグ
	bool m_Cf;
	bool m_Of; //フラグ

};


