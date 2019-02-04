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
	//得点情報をランキング最下位に登録
	((UserData*)Save::GetData())->m_ranking[9] = ((UserData*)Save::GetData())->m_point;
	((UserData*)Save::GetData())->m_timerank[9][0] = c;
	((UserData*)Save::GetData())->m_timerank[9][1] = s;
	((UserData*)Save::GetData())->m_timerank[9][2] = m;

	//得点が高い順に並び変えする
	RankingSort(((UserData*)Save::GetData())->m_ranking);
	TimeSort(((UserData*)Save::GetData())->m_timerank);
	
	//セーブ
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
	Font::StrDraw(atk, 450, 0, 30, c);

	//ここでスコアを描画してる
	for (int i = 0; i < 10; i++)
	{
		swprintf_s(atk, L" %2d位:%d銭", rank = rank + 1, ((UserData*)Save::GetData())->m_ranking[i]);//スコアをとって？
		Font::StrDraw(atk, 0, y_point = y_point + 55, 40, c);

		swprintf_s(atk, L"%2d位:Time   ： ：", rank);
		Font::StrDraw(atk, 350, y_point, 40, c);

		for (int n = 0; n < 3; n++) {
			swprintf_s(atk, L" %02d", ((UserData*)Save::GetData())->m_timerank[i][n]);
			Font::StrDraw(atk, 660 - (n * 60), y_point, 40, c);
			if (((UserData*)Save::GetData())->m_timerank[i][n] == s) {
				s = 0;
			}
			if (((UserData*)Save::GetData())->m_timerank[i][n] == m) {
				if (s == 0) {
					//swprintf_s(atk, L"New!");
					//Font::StrDraw(atk, 700, y_point, 40, c);
				}
			}
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
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
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
	for (int m = 0; m < 10; m++)
		if (time[m][0] == 0 && time[m][1] == 0) {
			time[m][0] = 99, time[m][1] = 99, time[m][2] = 99;
		}

	//値交換用変数
	int n;
	for (int a = 0; a < 3; a++) {
		//ソート
		for (int i = 0; i < 9; i++) {//0~8(10個ソートする)
			for (int j = i + 1; j < 10; j++) {//i+1~9(i以上で比べる)
				if (time[i][a] > time[j][a]) {
					for (int b = 0; b < 3; b++) {
						n = time[i][b];
						time[i][b] = time[j][b];
						time[j][b] = n;
					}//b値交換×3
				}//if大小比較
			}//j
		}//i
	}//a

	for (int m = 0; m < 10; m++)
		if (time[m][0] == 99 && time[m][1] == 99) {
			time[m][0] = 0, time[m][1] = 0, time[m][2] = 0;
		}
}
