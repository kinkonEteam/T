//使用するヘッダーファイル
//#include"GameL\DrawFont.h"
//#include"GameL\WinInputs.h"

#include"GameHead.h"
#include"ObjCapture.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void ObjCapture::Init()
{
	m_alpha = 1.0f;


	//外部グラフィックを読み込み30番に登録(512×512ピクセル)
	Draw::LoadImage(L"操作説明ペイント.png", 40, TEX_SIZE_512);
}

//アクション
void ObjCapture::Action()
{

}

void ObjCapture::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,m_alpha, };

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


	//作成時受け取ったm_numの数をそのまま画像番号に入れる
	//描画
	Draw::Draw(m_num, &src, &dst, c, 0.0f);
}