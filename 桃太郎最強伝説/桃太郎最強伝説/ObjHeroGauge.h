#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：キャラクターブロック
class CObjHeroGauge : public CObj
{
	public:
		CObjHeroGauge() {};
		~CObjHeroGauge() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー

		float Gethp() { return gethp; }
	private:
		float gethp;//体力戻り値
		int change;
		int ad;//HP増加調整用
		int ac;//HP減少調整用
		int ab;

};
