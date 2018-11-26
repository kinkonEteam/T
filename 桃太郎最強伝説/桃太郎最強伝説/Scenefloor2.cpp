//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
#include"GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"Scenefloor2.h"
#include"GameHead.h"

//コンストラクタ
CScenefloor2::CScenefloor2()
{

}

//デストラクタ
CScenefloor2::~CScenefloor2()
{

}

//初期化メソッド
void CScenefloor2::InitScene()
{
	//外部データの読み込み（階層2情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;			//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"Book2.csv", &size);//外部データ読み込み

	int map[56][56];
	int count = 1;
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			if (w >= 10)
			{
				count += 1;
			}

			count += 2;
		}
	}

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//グラフィック読み込み
	Draw::LoadImageW(L"マップチップ.png", 0, TEX_SIZE_141_47);

	//階層2オブジェクト作成
	CObjMap2* objb = new CObjMap2(map);
	Objs::InsertObj(objb, OBJ_MAP2, 9);
}

//実行中メソッド
void CScenefloor2::Scene()
{

}