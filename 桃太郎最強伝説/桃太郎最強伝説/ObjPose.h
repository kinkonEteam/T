#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトルに戻る
class CObjPose : public CObj
{
public:
	CObjPose() {};
	~CObjPose() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー
	void SetAf(bool af) { m_Af = af; }
private:
	bool m_CSceneposeFlag;
	bool m_Af; //フラグ
	bool m_Pf;


};

