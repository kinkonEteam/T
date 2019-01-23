//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjPose.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjPose::Init()
{
	m_Af = false;
	
}

//アクション
void  CObjPose::Action()
{
	if (Input::GetVKey('Z') == true)
	{
		this->SetStatus(false);	//自身に削除命令を出す			

	}
	if (Input::GetVKey('X') == true)
	{
		Scene::SetScene(new CSceneTitle());
	}
			
	
}

//ドロー
void  CObjPose::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"タイトルに戻りますか?", 200, 120, 45, c);
	Font::StrDraw(L"いいえ(Z)", 450, 300, 30, c);
	Font::StrDraw(L"はい(X)", 250, 300, 30, c);
	


}
