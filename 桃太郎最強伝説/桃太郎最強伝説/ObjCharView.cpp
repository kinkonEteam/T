//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\UserData.h"

#include"GameHead.h"
#include"ObjCharView.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void ObjCharView::Init()
{
	count = c;
	sec = s;
	min = m;
}
//アクション
void ObjCharView::Action()
{
	CObjTalk* talk = (CObjTalk*)Objs::GetObj(OBJ_TALK);
	if (talk != nullptr){}
	else
		count++;//カウント
	

	if (count == 60)
	{
		sec++;		//1加算
		count = 0;	//カウントリセット
	}
	if (sec == 60)
	{
		min++;		//1加算
		sec = 0;	//秒リセット
	}
}
//ドロー
void ObjCharView::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	

	wchar_t str[STR_MAX];

	swprintf_s(str, L"%d：", min);
	if(min < 10)
		swprintf_s(str, L"0%d：", min);
	Font::StrDraw(str, 650, 20, SCORE_FONT_SIZE, c);
	swprintf_s(str, L"%d：", sec);
	if (sec < 10)
		swprintf_s(str, L"0%d：", sec);
	Font::StrDraw(str, 700, 20, SCORE_FONT_SIZE, c);
	swprintf_s(str, L"%d"  , count);
	if (count < 10)
		swprintf_s(str, L"0%d", count);
	Font::StrDraw(str, 750, 20, SCORE_FONT_SIZE, c);
	
	
	
	

	CObjTalk* obj = (CObjTalk*)Objs::GetObj(OBJ_TALK);//イベント取得
	if (obj == nullptr)//存在しない場合のみ表示
	{
		Font::StrDraw(L"「H」操作説明", 10, 560, 25, c);
		Font::StrDraw(L"「i」持ち物", 200, 560, 25, c);
	}
}
