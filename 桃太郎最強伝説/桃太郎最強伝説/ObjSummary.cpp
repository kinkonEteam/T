//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameHead.h"
#include"ObjSummary.h"

#include <windows.h>


//使用するネームスペース
using namespace GameL;
//イニシャライズ
void CObjSummary::Init()
{
	m_time = 0;
	m_key_f = false;
	m_y = 0;
	m_ky= 30;
}

//アクション
void CObjSummary::Action()
{
	m_y+= 1.5;
	m_time += 1;


	//エンターキーを押してシーン：メイン移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_f == true)
		{
			Scene::SetScene(new CScenefloor1());
			m_key_f = false;
		}
	}
	else
	{
		m_key_f = true;
	}
	if(m_time==920)
	{
		Scene::SetScene(new CScenefloor1());
		m_key_f = false;
	}
}
//ドロー
void CObjSummary::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f }; 

	Font::StrDraw(L"むかしむかし、あるところに、おじいさんとおばあさんが住んでいました", 0, 500-m_y + m_ky, 24, c);
	Font::StrDraw(L"おじいさんは山へ芝刈りに、おばあさんは川へ洗濯に行きました", 60, 530-m_y + m_ky * 2, 23, c);
	Font::StrDraw(L"おばあさんが川へ洗濯をしていると、ドンブラコ,ドンブラコと", 60, 560 - m_y + m_ky * 3, 24, c);
	Font::StrDraw(L"大きな桃が流れてきました", 60, 590 - m_y + m_ky * 4, 23, c);
	Font::StrDraw(L"「おや．．．良いおみやげになるわ」", 70, 620 - m_y + m_ky * 5, 24, c);
	Font::StrDraw(L"おばあさんは大きな桃をひろいあげて家に持ち帰りました。", 60, 650 - m_y + m_ky * 6, 23, c);
	Font::StrDraw(L"そして、おじいさんとおばあさんが桃を食べようと桃を切ってみると", 0, 680 - m_y + m_ky * 7, 24, c);
	Font::StrDraw(L"なんと中から元気の良い男の赤ちゃんが飛び出してきました", 60, 710 - m_y + m_ky * 8, 23, c);
	Font::StrDraw(L"「これはきっと、神さまがくださったにちがいない」", 60, 740 - m_y + m_ky * 9, 24, c);
	Font::StrDraw(L"子どものいなかったおじいさんとおばあさんは、大喜びです", 60, 770 - m_y + m_ky * 10, 23, c);
	Font::StrDraw(L"桃から生まれた男の子を、おじいさんとおばあさんは桃太郎と名付けた", 0, 800 - m_y + m_ky * 11, 24, c);
	Font::StrDraw(L"桃太郎はすくすく成長して、強い男の子になりました", 60, 830 - m_y + m_ky * 12, 23, c);
	Font::StrDraw(L"そしてある日、桃太郎は言いました", 60, 860 - m_y + m_ky * 13, 24, c);
	Font::StrDraw(L"「ぼくは、鬼ヶ島へ行って、わるい鬼を退治します」", 60, 890 - m_y + m_ky * 14, 23, c);
	Font::StrDraw(L"おばあさんにきび団子を作ってもらうと、鬼ヶ島へ行ったのであった", 0, 920 - m_y + m_ky * 15, 24 , c);
	
}



