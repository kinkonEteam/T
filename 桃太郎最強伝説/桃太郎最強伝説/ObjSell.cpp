//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\UserData.h" 

#include"GameHead.h"
#include"ObjSell.h"

//使用するネームスペース
using namespace GameL;
extern int item_list[5];//アイテムリストを持ってくる

//イニシャライズ
void ObjSell::Init()
{
	m_keyf = true;		//初期値
	m_page = 0;
	m_count = 0;
	m_f = true;

	//外部グラフィックを読み込み29番に登録(512×512ピクセル)
	Draw::LoadImage(L"換金所.png", 29, TEX_SIZE_512);

	//外部グラフィックを読み込み9番に登録(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);

	//トークオブジェクト作成
	CObjTalk* talk = new CObjTalk(0, 2);	//オブジェクト作成
	Objs::InsertObj(talk, OBJ_TALK, 4);		//優先度4(中)に設定し登録

	//コメントの上に黒い画像表示
	CObjTalk* black = new CObjTalk(1, 2);	//オブジェクト作成
	Objs::InsertObj(black, OBJ_TALK, 20);	//優先度20(高)に設定し登録
}
//アクション
void ObjSell::Action()
{
	int p = 0;
	//ここではアイテムごとにスコアを計算し'ｐ'にスコアの数値を渡している
	for (int i = 0; i<7; i++)
	{
		if (i == 0)
		{
			p += item_list[i] * 100;//白桃　40％
		}
		else if (i == 1)
		{
			p += item_list[i] * 1000;//黄桃　20％
		}
		else if (i == 2)
		{
			p += item_list[i] * 1;//すもも　25％
		}
		else if (i == 3)
		{
			p += item_list[i] * 3000;//角
		}
		else if (i == 4)
		{
			p += item_list[i] * 10000;//金塊　5％
		}
		else if (i == 5)
		{
			p += item_list[i] * 5000;//銀塊　10％
		}
		else if (i == 6)
		{
			p += item_list[i] * 500;//棍棒
		}

	}

	//ここでスコアを決定する
	((UserData*)Save::GetData())->m_point = p;

	//入力判定、押しっぱなし制御
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_keyf == true)
		{
			m_page += 1;
			m_keyf = false;
		}
	}
	else//放している場合
		m_keyf = true;
}
//ドロー
void ObjSell::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	if (m_count == 0)
	{
		//名前とENTERキー	 (X), (y),(size),color
		Font::StrDraw(L"桃太郎", 55, 390, 25, c);
		Font::StrDraw(L"アクションキー・・・", 625, 560, 15, c);
	}
	else if (m_count == 110) {
		//トークオブジェクト作成
		CObjTalk* talk2 = new CObjTalk(0, 5);	//オブジェクト作成
		Objs::InsertObj(talk2, OBJ_TALK, 4);		//優先度4(中)に設定し登録
		//コメントの上に黒い画像表示
		CObjTalk* black2 = new CObjTalk(1, 5);	//オブジェクト作成
		Objs::InsertObj(black2, OBJ_TALK, 20);	//優先度10(高)に設定し登録
	}
	else if (m_count == 111) {
		m_f = false;
		m_page = 0;
		m_count++;
		ObjCapture* cap = new ObjCapture(29);		//29番の画像表示
		Objs::InsertObj(cap, OBJ_CAPTURE, 1);		//登録
	}

	if (m_f == true) {
		if (m_page == 0) {						//1ページ
			Font::StrDraw(L"鬼を倒した後、疲れのあまり記憶が少し曖昧で", 50, 440, 30, c);
			Font::StrDraw(L"少し変な夢を見た気がする。。。", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else if (m_page == 1) {					//2ページ
			Font::StrDraw(L"・　・　・", 50, 440, 30, c);
			Font::StrDraw(L"", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else {
			m_count++;//トークオブジェ消滅後カウント
		}
	}
		 /*各番号
		0,		//白桃
		1,		//黄桃
		2,		//すもも
		3,		//つの
		4,		//金塊
		5,		//銀塊
		6,		//棍棒
			*/
	if (m_f == false)//換金所シーン
	{
	float c[4] = { 1.0f,1.0f,1.0f,0.65f };//夢っぽく字を透過
	wchar_t a[128];
	
	if (0 <= m_page && m_page <= 2) {
			Font::StrDraw(L"商人", 55, 390, 25, c);
			Font::StrDraw(L"アクションキー・・・", 625, 560, 15, c);
		}
		else {
			Font::StrDraw(L"桃太郎", 55, 390, 25, c);
			Font::StrDraw(L"アクションキー・・・", 625, 560, 15, c);
		}

		if (m_page == 0) {						//1ページ
			swprintf_s(a, L"白桃が%d個で%d銭！", item_list[0],item_list[0]*100);
			Font::StrDraw(a, 50, 440, 30, c);
			swprintf_s(a, L"黄桃が%d個で%d銭！", item_list[1], item_list[1] * 1000);
			Font::StrDraw(a, 50, 480, 30, c);
			swprintf_s(a, L"すももが%d個で%d銭！", item_list[2], item_list[2] * 1);
			Font::StrDraw(a, 50, 520, 30, c);
		}
		else if (m_page == 1) {					//2ページ
			swprintf_s(a, L"つの%d個で%d銭！", item_list[3], item_list[3] * 3000);
			Font::StrDraw(a, 50, 440, 30, c);
			swprintf_s(a, L"金塊が%d個で%d銭！", item_list[4], item_list[4] * 10000);
			Font::StrDraw(a, 50, 480, 30, c);
			swprintf_s(a, L"銀塊が%d個で%d銭！", item_list[5], item_list[5] * 5000);
			Font::StrDraw(a, 50, 520, 30, c);
		}
		else if (m_page == 2) {					//3ページ
			swprintf_s(a, L"棍棒が%d個で%d銭！", item_list[6], item_list[6] * 500);
			Font::StrDraw(a, 50, 440, 30, c);
			Font::StrDraw(L"", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else if (m_page == 3)//4ページ
		{
			swprintf_s(a, L"合計%d銭！", ((UserData*)Save::GetData())->m_point);
			Font::StrDraw(a, 50, 440, 30, c);
			Font::StrDraw(L"", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else if (m_page == 4) {					//5ページ
			Font::StrDraw(L"この村人が、皆に渡してくれるだろうか。。。", 50, 440, 30, c);
			Font::StrDraw(L"", 50, 480, 30, c);
			Font::StrDraw(L"", 50, 520, 30, c);
		}
		else 
		{
			this->SetStatus(false);		//自己削除
		}
	}
}