//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "CObjSummary.h"
#include "GameHead.h"

void CObjSummary::Init()
{
	m_f = true;		//初期値
	m_page = 0;
	m_key_f = false;

	//外部グラフィックを読み込み9番に登録(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);

	//トークオブジェクト作成
	CObjTalk* talk = new CObjTalk(0, 18);	//オブジェクト作成
	Objs::InsertObj(talk, OBJ_TALK, 4);		//優先度4(高)に設定し登録
											//コメントの上に黒い画像表示
	CObjTalk* black = new CObjTalk(1, 18);	//オブジェクト作成
	Objs::InsertObj(black, OBJ_TALK, 20);	//優先度5(高)に設定し登録
}

void CObjSummary::Action()
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

void CObjSummary::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//名前とENTERキー	 (X), (y),(size),color
	Font::StrDraw(L"", 77, 390, 25, c);
	Font::StrDraw(L"アクションキー・・・", 625, 560, 15, c);

	if (m_page == 1) {						//1ページ
		Font::StrDraw(L"むかしむかし、あるところに、おじいさんと", 50, 440, 30, c);
		Font::StrDraw(L"おばあさんが住んでいました。", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 2) {					//2ページ
		Font::StrDraw(L"ある日、いつものようにおじいさんは山へ芝刈りに、", 50, 440, 30, c);
		Font::StrDraw(L"おばあさんは川へ洗濯に行きました。", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 3) {					//3ページ
		Font::StrDraw(L"おばあさんが川へ洗濯をしていると、", 50, 440, 30, c);
		Font::StrDraw(L"川上からドンブラコ,ドンブラコと", 50, 480, 30, c);
		Font::StrDraw(L"大きな桃が流れてきました。", 50, 520, 30, c);
	}
	else if (m_page == 4) {					//4ページ
		Font::StrDraw(L"「おや、これは良いおみやげになるわ」", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 5) {					//5ページ
		Font::StrDraw(L"喜んだおばあさんは大きな桃をひろいあげて、", 50, 440, 30, c);
		Font::StrDraw(L"家に持ち帰ることにしました。", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 6) {					//6ページ
		Font::StrDraw(L"「おお、これはまた随分と立派な桃だ」", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 7) {					//7ページ
		Font::StrDraw(L"喜んだおじいさんが早速二人で食べようと", 50, 440, 30, c);
		Font::StrDraw(L"桃を切ってみると、", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 8) {					//8ページ
		Font::StrDraw(L"「おぎゃあ、おぎゃあ」", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 9) {					//9ページ
		Font::StrDraw(L"なんと、中から元気な男の子が", 50, 440, 30, c);
		Font::StrDraw(L"飛び出してきました。", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 10) {					//10ページ
		Font::StrDraw(L"「これはきっと神さまがくださった子にちがいない」", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 11) {					//11ページ
		Font::StrDraw(L"子どものいなかったおじいさんと", 50, 440, 30, c);
		Font::StrDraw(L"おばあさんは大喜びです。", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 12) {					//12ページ
		Font::StrDraw(L"二人は男の子を桃から生まれたことから", 50, 440, 30, c);
		Font::StrDraw(L"桃太郎と名付け、大事に育てました。", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 13) {					//13ページ
		Font::StrDraw(L"桃太郎はすくすく成長し、", 50, 440, 30, c);
		Font::StrDraw(L"とても強い男の子になりました。", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 14) {					//14ページ
		Font::StrDraw(L"ある日、桃太郎は言いました。", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 15) {					//15ページ
		Font::StrDraw(L"「鬼ヶ島へ行って、村を脅かす悪い鬼たちを", 50, 440, 30, c);
		Font::StrDraw(L"　退治してきます」", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 16) {					//16ページ
		Font::StrDraw(L"見送りの時、おばあさんはお腹が空いては", 50, 440, 30, c);
		Font::StrDraw(L"いけないからときびだんごを持たせてくれました。", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 17) {					//17ページ
		Font::StrDraw(L"「ありがとう、おばあさんおじいさん。", 50, 440, 30, c);
		Font::StrDraw(L"　では行ってきます」", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else if (m_page == 18) {					//18ページ
		Font::StrDraw(L"こうして、桃太郎による鬼退治の旅が", 50, 440, 30, c);
		Font::StrDraw(L"幕を開けたのでした。", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else
		this->SetStatus(false);			//オブジェクト削除
}