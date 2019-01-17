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

	swprintf_s(atk, L"タイムランキング");
	Font::StrDraw(atk, 100, 0, 30, c);

	//ここでスコアを描画してる
	for (int i = 0; i < 10;i++)
	{
		swprintf_s(atk, L" %d位:Score・%d",rank=rank+1, ((UserData*)Save::GetData())->m_ranking[i]);//スコアをとって？
		Font::StrDraw(atk, 350, y_point=y_point+60 , 40, c);

		//swprintf_s(atk, L" %d位:Score・%d", rank,m_ranking[i]);
		//Font::StrDraw(atk, 350, y_point, 40, c);
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
	int c;
	int rank[10];
	//		  41 +	  32 00	 +	02 00 00  (例)
	rank[9] = c + (s * 100) + (m * 1000);//最下位に代入

	//ソート
	for (int i = 0; i < 10; i++){//0~9(10個ソートする)
		for (int j = i + 1; j < 11; j++){//0~10(11回上下で比べる)
			if (rank[i] < rank[j]){
				//cを仲介に値の交換
				c = rank[i];
				rank[i] = rank[j];
				rank[j] = c;
			}
		}
	}

	for (int a = 0; a < 10; a++) {
		time[a][0] = rank[a] - (s * 100 + m * 10000);//sとmを引いてcを代入
		time[a][1] = rank[a] - (c       + m * 10000);//cとmを引いてcを代入
		time[a][2] = rank[a] - (c		+ s * 100  );//cとsを引いてcを代入
	}
}
