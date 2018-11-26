//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "CObjEveDog.h"
#include "GameHead.h"

void CObjEveDog::Init()
{
	m_f = true;

	//外部グラフィックを読み込み7番に登録(512*512)
	Draw::LoadImage(L"talk.png", 8, TEX_SIZE_512);

	//オブジェクト作成
	CObjTalk* t = new CObjTalk();
	Objs::InsertObj(t, OBJ_TALK, 1);
}

void CObjEveDog::Action()
{
	//攻撃の入力判定、押しっぱなし制御
	if (Input::GetVKey('\n') == true)
	{
		if (m_f == true)
		{
			
			

			m_f = false;
		}
	}
	else//放している場合
		m_f = true;
}

void CObjEveDog::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	Font::StrDraw(L"コメント", 30, 410, 25, c);

	Font::StrDraw(L"a", 30, 410, 25, c);
}