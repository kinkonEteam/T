#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：剣
class CObjSword :public CObj
{
	public:	    //ここで位置と向きを渡される
		CObjSword(float x, float y,int m_pos);//コンストラクタ
		~CObjSword() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		float m_px;		//プレイヤー座標
		float m_py;
		float m_posx;	//向き変更用座標
		float m_posy;
		float m_r;		//剣の角度
		float m_vr;		//角度の増分
		int m_pos;		//主人公の向き格納
};