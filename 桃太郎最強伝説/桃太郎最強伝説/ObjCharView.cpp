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
	count = 0;
	sec = 0;
	min = 0;
}
//アクション
void ObjCharView::Action()
{
	count++;//常に1加算

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

	swprintf_s(str, L"%d：%d", min, sec);//そのまま登録

	if ((sec < 10) || (min < 10)) {//秒数か分数が、二桁でない場合のみ上書き
		swprintf_s(str, L"%d：0%d", min, sec);
		if (min < 10) {					//分
			swprintf_s(str, L"0%d：%d", min, sec);
		}
		if ((sec < 10) && (min < 10)) {	//両方小さい場合
			swprintf_s(str, L"0%d：0%d", min, sec);
		}
	}
	
	Font::StrDraw(str, 100, 100, SCORE_FONT_SIZE, c);
	
	Font::StrDraw(L"'H'ヘルプ 'M'メニュー", 10, 560, 25, c);
}
