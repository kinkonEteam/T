//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "CObjText5.h"
#include "GameHead.h"

void CObjText5::Init()
{
	m_f = true;		//初期値
	m_page = 0;

	//外部グラフィックを読み込み9番に登録(512*512)
	Draw::LoadImage(L"talk.png", 9, TEX_SIZE_512);

	//トークオブジェクト作成
	CObjTalk* talk = new CObjTalk(0, 2);	//オブジェクト作成
	Objs::InsertObj(talk, OBJ_TALK, 4);		//優先度4(高)に設定し登録
											//コメントの上に黒い画像表示
	CObjTalk* black = new CObjTalk(1, 2);	//オブジェクト作成
	Objs::InsertObj(black, OBJ_TALK, 20);	//優先度5(高)に設定し登録
}

void CObjText5::Action()
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

void CObjText5::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//名前とENTERキー	 (X), (y),(size),color
	Font::StrDraw(L"桃太郎", 77, 390, 25, c);
	Font::StrDraw(L"アクションキー・・・", 625, 560, 15, c);

	if (m_page == 0)
	{
		Font::StrDraw(L"桃太郎のトドメの一撃を受け", 50, 440, 30, c);
		Font::StrDraw(L"大鬼は絶命した", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	if (m_page == 1) {						//1ページ
		Font::StrDraw(L"・・・どこかが開いた音がした", 50, 440, 30, c);
		Font::StrDraw(L"", 50, 480, 30, c);
		Font::StrDraw(L"", 50, 520, 30, c);
	}
	else
		this->SetStatus(false);			//オブジェクト削除
}