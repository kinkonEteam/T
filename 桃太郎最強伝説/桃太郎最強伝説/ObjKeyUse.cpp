//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjKeyUse.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void ObjKeyUse::Init()
{

}
//アクション
void ObjKeyUse::Action()
{

}
//ドロー
void ObjKeyUse::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	
	Font::StrDraw(L"'H'ヘルプ 'M'メニュー", 10, 560, 25, c);
}
