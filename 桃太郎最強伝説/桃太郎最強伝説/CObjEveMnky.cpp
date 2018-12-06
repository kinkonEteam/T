// GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "CObjEveMnky.h"
#include "GameHead.h"

void CObjEveMnky::Init()
{
	m_f = true;		//初期値
	m_page = 0;

	//外部グラフィックを読み込み9番に登録(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);
	//外部グラフィックを読み込み18番に登録(512×512ピクセル)
	Draw::LoadImage(L"mnky.png", 18, TEX_SIZE_1024);

	//トークオブジェクト作成
	CObjTalk* talk = new CObjTalk(0, 4);	//オブジェクト作成
	Objs::InsertObj(talk, OBJ_TALK, 4);		//優先度4(高)に設定し登録
	//コメントの上に黒い画像表示
	CObjTalk* black = new CObjTalk(1, 4);	//オブジェクト作成
	Objs::InsertObj(black, OBJ_TALK, 10);	//優先度5(高)に設定し登録
	//立ち絵表示
	CObjTalk* mnky = new CObjTalk(2, 4);	//オブジェクト作成
	Objs::InsertObj(mnky, OBJ_TALK, 4);	//優先度4(高)に設定し登録
}


void CObjEveMnky::Action()
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

void CObjEveMnky::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//名前とENTERキー	 (X), (y),(size),color
	Font::StrDraw(L"猿", 55, 390, 25, c);
	Font::StrDraw(L"アクションキー・・・", 625, 560, 15, c);

	if (m_page == 0) {						//1ページ
		Font::StrDraw(L"「桃太郎さん桃太郎さん！お腰につけたキビ団子、", 50, 440, 30, c);
		Font::StrDraw(L"ひとつオレにくださいな！そうすれば鬼退治に協力", 50, 480, 30, c);
		Font::StrDraw(L"してやるぞ！」", 50, 520, 30, c);
	}
	else if (m_page == 1) {					//2ページ
		Font::StrDraw(L"キビ団子をあげた。", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 2) {					//3ページ
		Font::StrDraw(L"「サンキュー！オレは早いぜ！おいて行かれるなよ！」", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 3) {					//3ページ
		Font::StrDraw(L"サルが仲間になった！移動速度が上昇した！", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else {
		CObjMonke*monke = (CObjMonke*)Objs::GetObj(OBJ_MONKE);
		monke->Setdf(true);
		this->SetStatus(false);		//オブジェクト削除
	}
}