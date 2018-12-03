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
	float c[4] = { 1.0f,1.0f,1.0f,2.5f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;


	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//描画
	Draw::Draw(20, &src, &dst, c, 0.0f);

	float b[4] = { 1.0f,0.0f,0.0f,1.0f };
	Font::StrDraw(L"", 10, 550, 45, b);
	Font::StrDraw(L"", 10, 550, 45, b);
}
