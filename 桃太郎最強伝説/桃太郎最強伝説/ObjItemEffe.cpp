//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "ObjItemEffe.h"
#include "GameHead.h"

void ObjItemEffe::Init()
{
	//外部グラフィックを読み込み8番に登録(512*512)
	Draw::LoadImage(L"talk.png", 8, TEX_SIZE_512);

	//トークオブジェクト作成
	CObjTalk* talk = new CObjTalk(0, 1);	//オブジェクト作成
	Objs::InsertObj(talk, OBJ_TALK, 3);//優先度1(低)に設定し登録
	//コメントの上に黒い画像表示
	CObjTalk* black = new CObjTalk(1, 1);	//オブジェクト作成
	Objs::InsertObj(black, OBJ_TALK, 5);//優先度3(高)に設定し登録
}

void ObjItemEffe::Action()
{
	//入力判定、押しっぱなし制御
	if (Input::GetVKey(VK_RETURN) == true)
	{
		this->SetStatus(false);		//オブジェクト削除
	}
	else { ; }//押してない場合
}

void ObjItemEffe::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	//名前とENTERキー	 (X), (y),(size),color
	Font::StrDraw(L"", 35, 390, 25, c);
	Font::StrDraw(L"アクションキー・・・", 625, 560, 15, c);

	//1桃, 2黄桃, 3すもも, 4つの, 5金の延べ棒, 6銀の延べ棒, 7棍棒
	if (m_item == 1) {							//桃
		Font::StrDraw(L"体力が１回復した！", 50, 440, 30, c);
	}
	else if (m_item == 2) {						//黄桃
		Font::StrDraw(L"体力が３回復した！", 50, 440, 30, c);
	}
	else if (m_item == 3) {						//すもも
		Font::StrDraw(L"すももを手に入れた！", 50, 440, 30, c);
	}
	else if (m_item == 4) {						//つの
		Font::StrDraw(L"つのを手に入れた！", 50, 440, 30, c);
	}
	else if (m_item == 5) {						//金の延べ棒
		Font::StrDraw(L"金の延べ棒を手に入れた！", 50, 440, 30, c);
	}
	else if (m_item == 6) {						//銀の延べ棒
		Font::StrDraw(L"銀の延べ棒を手に入れた！", 50, 440, 30, c);
	}
	else {										//棍棒
		Font::StrDraw(L"棍棒を手に入れた！", 50, 440, 30, c);
		Font::StrDraw(L"移動速度が低下した。", 50, 480, 30, c);
	}
}