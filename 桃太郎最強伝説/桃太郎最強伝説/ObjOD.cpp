//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjOD.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjOD::Init()
{
	m_Of = false;
}

//アクション
void CObjOD::Action()
{




	
}


//ドロー
void CObjOD::Draw()
{

	if (m_Of == true)
	{
		this->SetStatus(false);	//自身に削除命令を出す
	}
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


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
	Draw::Draw(40, &src, &dst, c, 0.0f);

}
