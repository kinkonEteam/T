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
#include"Scenefloor5.h"
#include"GameHead.h"

//コンストラクタ
CScenefloor5::CScenefloor5()
{

}

//デストラクタ
CScenefloor5::~CScenefloor5()
{

}

//初期化メソッド
void CScenefloor5::InitScene()
{
	//ボス戦用BGM読み込み
	Audio::LoadAudio(1, L"ボス.wav", BACK_MUSIC);

	Audio::Start(1);//ボス用BGMをスタート

	//外部データの読み込み（階層5情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;			//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"Book5.csv", &size);//外部データ読み込み

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

	//グラフィック読み込み
	//外部グラフィックを読み込み0番に登録(512×512ピクセル)
	Draw::LoadImage(L"桃太郎.png", 0, TEX_SIZE_512);

	//外部グラフィックを読み込み1番に登録(141×47ピクセル)
	Draw::LoadImageW(L"マップチップ.png", 1, TEX_SIZE_141_47);

	//外部グラフィックを読み込み2番に登録(512×512ピクセル)
	Draw::LoadImage(L"OTOMO.GIF", 2, TEX_SIZE_512);

	//外部グラフィックを読み込み3番に登録(512×512ピクセル)
	Draw::LoadImage(L"Sword.png", 3, TEX_SIZE_512);

	//外部グラフィックを読み込み4番に登録(512×512ピクセル)
	Draw::LoadImage(L"アイテム.png", 4, TEX_SIZE_512);

	//外部グラフィックを読み込み5番に登録(512×512ピクセル
	Draw::LoadImage(L"青鬼.png", 5, TEX_SIZE_512);

	//外部グラフィックを読み込み6番に登録(512×512ピクセル)
	Draw::LoadImage(L"黄鬼.png", 6, TEX_SIZE_512);

	//外部グラフィックを読み込み8番に登録(512ピクセル)
	Draw::LoadImage(L"体力ゲージフル.png", 8, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み9番に登録
	Draw::LoadImage(L"赤鬼.png", 9, TEX_SIZE_151_200);

	//外部グラフィックファイルを読み込み10番に登録
	Draw::LoadImage(L"ファイアボール.png", 10, TEX_SIZE_151_200);

	//外部グラフィックを読み込み15番に登録(512×512ピクセル)
	Draw::LoadImage(L"暗闇最小.png", 15, TEX_SIZE_512);

	//外部グラフィックを読み込み16番に登録(512×512ピクセル)
	Draw::LoadImage(L"暗闇+1.png", 16, TEX_SIZE_512);

	//外部グラフィックを読み込み17番に登録(512×512ピクセル)
	Draw::LoadImage(L"暗闇+2.png", 17, TEX_SIZE_512);
	
	//外部グラフィックを読み込み11番に登録(512×512ピクセル)
	Draw::LoadImage(L"風エフェクト.png", 11, TEX_SIZE_512);

	//外部グラフィックを読み込み40番に登録(512×512ピクセル)
	Draw::LoadImage(L"操作説明ペイント.png", 40, TEX_SIZE_512);

	//階層5オブジェクト作成
	CObjMap5* objb = new CObjMap5(map);
	Objs::InsertObj(objb, OBJ_MAP5, 1);

	//主人公体力ゲージオブジェクト作成
	CObjHeroGauge* objg = new CObjHeroGauge();
	Objs::InsertObj(objg, OBJ_HEROGAUGE, 20);

	//文字表示作成
	ObjCharView* c = new ObjCharView();
	Objs::InsertObj(c, OBJ_CV, 20);

}

//実行中メソッド
void CScenefloor5::Scene()
{

}