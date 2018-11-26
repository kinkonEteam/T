//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjTalk.h"
#include "GameHead.h"

void CObjTalk::Init()
{
	
}

void CObjTalk::Action()
{

}

void CObjTalk::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top  =   0.0f;
	src.m_left =   0.0f;
	src.m_right =128.0f;
	src.m_bottom= 64.0f;

	//表示位置の設定
	dst.m_top   =400.0f;
	dst.m_left  = 20.0f;
	dst.m_right =780.0f;
	dst.m_bottom=580.0f;

	//描画
	Draw::Draw(8, &src, &dst, c, 0.0f);

	Font::StrDraw(L"コメント", 30, 410, 25, c);
}