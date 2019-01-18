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
extern int c, s, m;//カウント、セコンド、ミニッツ

//イニシャライズ
void CObjScore::Init()
{
	/*
	for (int i = 0; i < 10; i++)
	{
		((UserData*)Save::GetData())->m_ranking[i] = 0;
		for (int j = 0; j < 3; j++)
			((UserData*)Save::GetData())->m_timerank[i][j] = 0;
	}
	*/
	
	//得点情報をランキング最下位に登録
	((UserData*)Save::GetData())->m_ranking[9] = ((UserData*)Save::GetData())->m_point;
	((UserData*)Save::GetData())->m_timerank[9][0] = c;
	((UserData*)Save::GetData())->m_timerank[9][1] = s;
	((UserData*)Save::GetData())->m_timerank[9][2] = m;

	//得点が高い順に並び変えする
	RankingSort(((UserData*)Save::GetData())->m_ranking);
	//TimeSort(((UserData*)Save::GetData())->m_timerank);
	
	//セーブデータ？
	Save::Seve();

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
	int y_point = -10;//y軸
	int rank= 0;//順位変数
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//描画
	Draw::Draw(18, &src, &dst, c, 0.0f);
	wchar_t atk[128];

	//描画
	swprintf_s(atk, L"ゲームランキング");
	Font::StrDraw(atk, 100, 0 , 30, c);

	swprintf_s(atk, L"タイムランキング");
	Font::StrDraw(atk, 500, 0, 30, c);

	//ここでスコアを描画してる
	for (int i = 0; i < 10; i++)
	{
		swprintf_s(atk, L" %2d位:Score・%d", rank = rank + 1, ((UserData*)Save::GetData())->m_ranking[i]);//スコアをとって？
		Font::StrDraw(atk, 0, y_point = y_point + 55, 40, c);

		swprintf_s(atk, L"%2d位:Time   ： ：", rank);
		Font::StrDraw(atk, 400, y_point, 40, c);

		for (int n = 0; n < 3; n++) {
			swprintf_s(atk, L" %2d", ((UserData*)Save::GetData())->m_timerank[i][n]);
			Font::StrDraw(atk, 710 - (n * 60), y_point, 40, c);
		}
	}

}

//ランキングソートメソッド
//引数1　int[16]:ランキング用配列
//降順でバブルソートを行う
void CObjScore::RankingSort(int rank[10])
{
	//値交換用変数
	int c;

	//バブルソート
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 11; j++)
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

void CObjScore::TimeSort(int time[10][3])
{
	//値交換用変数
	int n;
	int rank[10];
	for (int a = 0; a < 3; a++) {
		//ソート
		for (int i = 0; i < 10; i++) {//0~9(10個ソートする)
			for (int j = i + 1; j < 11; j++) {//0~10(11回上下で比べる)
				if (time[i][a] < time[j][a]) {
					//cを仲介に値の交換
					n = time[i][a];
					time[i][a] = time[j][a];
					time[j][a] = n;
				}
			}
		}

	}
}
/*
void CObjScore::TimeSort(int time[10][3])
{
	//値交換用変数
	int n;
	int rank[10];
	for (int j = 0; j < 10; j++) {
		//				 ??  +			 ?? 00	  +	?? 00 00  
		rank[j] = time[j][0] + (time[j][1] * 100) + (time[j][2] * 1000);//時間をまとめる
	}

	//ソート
	for (int i = 0; i < 10; i++){//0~9(10個ソートする)
		for (int j = i + 1; j < 11; j++){//0~10(11回上下で比べる)
			if (rank[i] < rank[j]){
				//cを仲介に値の交換
				n = rank[i];
				rank[i] = rank[j];
				rank[j] = n;
			}
		}
	}

	for (int a = 0; a < 10; a++) {//時間を分ける
		time[a][0] = rank[a] - (s * 100 + m * 10000);//sとmを引いてc
		time[a][1] = rank[a] - (c       + m * 10000);//cとmを引いてs
		time[a][2] = rank[a] - (c		+ s * 100  );//cとsを引いてm
	}
}
*/