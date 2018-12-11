// GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "CObjEveKiji.h"


void CObjEveKiji::Init()
{
	m_f = true;		//初期値
	m_page = 0;

	//外部グラフィックを読み込み9番に登録(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);
	//外部グラフィックを読み込み4番に登録(512×512ピクセル)
	Draw::LoadImage(L"kiji.png", 20, TEX_SIZE_1024);

	//トークオブジェクト作成
	CObjTalk* talk = new CObjTalk(0, 4);	//オブジェクト作成
	Objs::InsertObj(talk, OBJ_TALK, 4);		//優先度4(高)に設定し登録
	//コメントの上に黒い画像表示
	CObjTalk* black = new CObjTalk(1, 4);	//オブジェクト作成
	Objs::InsertObj(black, OBJ_TALK, 10);	//優先度5(高)に設定し登録
	//立ち絵表示
	CObjTalk* dog = new CObjTalk(4, 4);		//オブジェクト作成
	Objs::InsertObj(dog, OBJ_TALK, 4);		//優先度5(高)に設定し登録
}

void CObjEveKiji::Action()
{
	//入力判定、押しっぱなし制御
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_f == true)
		{
			m_page += 1;
			m_f = false;
		}
	}
	else//放している場合
		m_f = true;
}

void CObjEveKiji::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//名前とENTERキー	 (X), (y),(size),color
	Font::StrDraw(L"キジ", 35, 390, 25, c);
	Font::StrDraw(L"アクションキー・・・", 625, 560, 15, c);

	if (m_page == 0) {						//1ページ
		Font::StrDraw(L"「桃太郎さん桃太郎さん！お腰につけたキビ団子、", 50, 440, 30, c);
		Font::StrDraw(L"ひとつ私にくださいな。さすれば鬼退治に協力して", 50, 480, 30, c);
		Font::StrDraw(L"さしあげましょう」", 50, 520, 30, c);
	}
	else if (m_page == 1) {					//2ページ
		Font::StrDraw(L"キビ団子をあげた。", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 2) {					//3ページ
		Font::StrDraw(L"「ありがとうございます。上からの援護はおまかせく", 50, 440, 30, c);
		Font::StrDraw(L"　ださい」", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 3) {					//3ページ
		Font::StrDraw(L"キジが仲間になった！遠距離攻撃が可能になった！", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else {
		CObjPheasant*kiji = (CObjPheasant*)Objs::GetObj(OBJ_PHEASANT);
		kiji->Setdf(true);				//オブジェクト削除フラグ
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		hero->SetYAMI(false);			//falseで暗闇更新
		this->SetStatus(false);			//オブジェクト削除
	}
}