//使用するヘッダーファイル
//#include"GameL\DrawFont.h"
//#include"GameL\WinInputs.h"

#include"GameHead.h"
#include"ObjYami.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void ObjYami::Init()
{

}

//アクション
void ObjYami::Action()
{

}

void ObjYami::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

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

	if (m_num == 1) { m_num = 15; }
	else if (m_num == 2) { m_num = 16; }
	else if (m_num == 3) { m_num = 17; }
	else { ; }

	//描画
	Draw::Draw(m_num, &src, &dst, c, 0.0f);

}