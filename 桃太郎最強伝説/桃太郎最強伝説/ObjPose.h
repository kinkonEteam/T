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
private:
	bool m_CSceneposeFlag;


};

