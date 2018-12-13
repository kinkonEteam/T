//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\UserData.h"
/*#include "GameL\DrawFont.h"*/

#include"GameHead.h"
#include"ObjScore.h"

//使用するネームスペース
using namespace GameL;
extern int item_list[5];

//イニシャライズ
void CObjScore::Init()
{
	
	//得点情報をランキング最下位に登録
	((UserData*)Save::GetData())->m_ranking[15] = ((UserData*)Save::GetData())->m_point;

	//得点が高い順に並び変えする
	RankingSort(((UserData*)Save::GetData())->m_ranking);

	m_key_flag = false;//キーフラグ
}

//アクション
void CObjScore::Action()
{
	//エンターキーを押してシーン：ゲームタイトルに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}

	}
	else
	{
		m_key_flag = true;
	}


}

//ドロー
void CObjScore::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	int y_point = -40;//y軸
	int rank= 0;//順位変数
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//描画
	Draw::Draw(18, &src, &dst, c, 0.0f);
	wchar_t atk[128];

	//描画
	swprintf_s(atk, L"ゲームランキング");
	Font::StrDraw(atk, 0, 0 , 30, c);

	//ここでスコアを描画してる
	for (int i = 0; i < 15;i++)
	{
		swprintf_s(atk, L"%d位:Score・%d",rank=rank+1, ((UserData*)Save::GetData())->m_ranking[i]);//スコアをとって？
		Font::StrDraw(atk, 300, y_point=y_point+40 , 40, c);
	}

}

//ランキングソートメソッド
//引数1　int[16]:ランキング用配列
//降順でバブルソートを行う
void CObjScore::RankingSort(int rank[16])
{
	//値交換用変数
	int c;

	//バブルソート
	for (int i = 0; i < 15; i++)
	{
		for (int j = i + 1; j < 16; j++)
		{
			if (rank[i] < rank[j])
			{
				//値の交換
				c = rank[i];
				rank[i] = rank[j];
				rank[j] = c;
			}
		}
	}
}