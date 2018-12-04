#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;



//オブジェクト：キャラクターブロック
class CObjDog : public CObj
{
	public:
		CObjDog(float x, float y);
		~CObjDog() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
		void Setdf(bool df) { m_df = df; }
	private:
		float m_px;		 //位置
		float m_py;

		bool m_df;

};

