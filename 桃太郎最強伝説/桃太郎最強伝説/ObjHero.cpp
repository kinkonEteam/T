//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "Inventory.h"
#include "GameL\Audio.h"
#include "Itemlist.cpp"
//使用するネームスペース
using namespace GameL;

//Date.cpp内で宣言したグローバル変数をextern宣言----------------------保持データ
extern int HP;				//HP
extern bool OTOMO[3];		//お供所持情報
void CObjHero::SaveDATA() {		//セーブ関数の定義----------------------データをセーブ
	//シーン切り替え時のhpデータを、HPへ格納
	HP = m_hp;
}
void CObjHero::SetDATA() {		//セーブ関数の定義----------------------データをセット
								//シーン切り替え時のhpデータを、HPへ格納
	HP = 5;
}

CObjHero::CObjHero(float x, float y)
{//オブジェ作成時に渡されたx,y座標をメンバ変数に代入
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjHero::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_hp_max = 5;		//初期最大HP

	bool m_otm[3];

	//OTOMO[0犬,1キジ,2猿] == true(ある) or false(ない)
	if (OTOMO[0] == true)		//犬が居る場合
		m_hp_max += 1;			//最大HPに1加算
	if (OTOMO[1] == true)		//キジが居る場合
		m_Kf = false;			//制御を解除
	else { m_Kf = true; }		//居ないなら制御

	m_hp = HP;				//メンバhpに初期HPを代入
	m_time = 70;
	alpha = 1.0f;
	count = 10;

	m_posture = 0;	//正面(0) 左(1) 右(2) 背面(3)
	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレーム
	m_Sf = true;			//攻撃制御
	m_key_f = false;		//無敵時間行動制御

	//HitBox作成座標とサイズx,y、エレメントとオブジェクトを設定
	Hits::SetHitBox(this, m_px+5, m_py+3, 40, 47, ELEMENT_PLAYER, OBJ_HERO, 1);

	
	Audio::LoadAudio(4, L"近接攻撃.wav", EFFECT);			//近接攻撃SE
	Audio::LoadAudio(5, L"kijiSE.wav", EFFECT);				//遠距離攻撃SE
	Audio::LoadAudio(6, L"damage.wav", EFFECT);				//ダメージSE
	Audio::LoadAudio(8, L"heal.wav", EFFECT);				//体力回復時SE
	Audio::LoadAudio(9, L"speeddown.wav", EFFECT);			//棍棒取得時用SE
	Audio::LoadAudio(10, L"StairsSE.wav", EFFECT);			//近接攻撃SE

	//音量を0.9下げる
	float Volume = Audio::VolumeMaster(-0.9f);
}

//アクション
void CObjHero::Action()
{
	//ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//通常攻撃処理---------------------------------------------------------------------
	if (m_key_f==false)
	{
		if (Input::GetVKey('A') == true)//Aキー入力時
		{
			if (m_Sf == true){//m_fがtrueの場合
				//近距離攻撃音を鳴らす
				Audio::Start(4);
				//剣オブジェクト作成			剣に座標と向きを渡す
				CObjSword* swd = new CObjSword(m_px, m_py, m_posture);
				Objs::InsertObj(swd, OBJ_SWORD, 3);//マネージャーに登録

				m_Sf = false;
			}
		}
		else		//放している場合
			m_Sf = true;//trueを代入

		//キジ攻撃処理------------------------------------------------------------------
		//キジの情報を取得
		CObjFlyKiji* obj = (CObjFlyKiji*)Objs::GetObj(OBJ_FLYKIJI);
		if (Input::GetVKey('S') == true)//Sキー入力時
		{
			if (m_Kf == false) {
				if (obj == nullptr)//キジ情報が無い場合
				{
					//遠距離攻撃音を鳴らす
					Audio::Start(5);

					//キジオブジェクト作成				キジに座標と向きを渡す
					CObjFlyKiji* kiji = new CObjFlyKiji(m_px, m_py, m_posture);
					Objs::InsertObj(kiji, OBJ_FLYKIJI, 3);//マネージャーに登録
				}
			}
		}
		else { ; }//無入力時

		//主人公移動キー入力判定--------------------------------------------------------
		if (Input::GetVKey(VK_RIGHT) == true)//→
		{
			m_vx += 1.0f;					//移動ベクトル加算
			m_posture = 2;					//向き情報代入
			m_ani_time += 1;				//アニメーション時間加算
		}
		else if (Input::GetVKey(VK_UP) == true)	//↑
		{
			m_vy -= 1.0f;
			m_posture = 3;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_DOWN) == true)//↓
		{
			m_vy += 1.0f;
			m_posture = 0;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_LEFT) == true)//←
		{
			m_vx -= 1.0f;
			m_posture = 1;
			m_ani_time += 1;
		}
		else//移動キーの入力が無い場合
		{
			m_ani_frame = 1;	//静止フレームにする
			m_ani_time = 0;		//アニメーション時間リセット
		}
	}

	//アニメーション動作間隔(ここでアニメーション速度変更)---------------------------------
	if (m_ani_time > 6)		//時間が6より大きい場合
	{
		m_ani_frame += 1;	//フレーム変数を加算し、切り替える
		m_ani_time = 0;		//時間に0を代入
	}

	if (m_ani_frame == 4)	//フレームが4の場合
		m_ani_frame = 0;	//フレームに0を代入

	//移動ベクトルの正規化	斜め移動しない為不要
	//UnitVec(&m_vy, &m_vx);

	//スクロール
	CObjMap1*map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	CObjMap2*map2 = (CObjMap2*)Objs::GetObj(OBJ_MAP2);
	CObjMap3*map3 = (CObjMap3*)Objs::GetObj(OBJ_MAP3);
	CObjMap4*map4 = (CObjMap4*)Objs::GetObj(OBJ_MAP4);
	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);
		m_px = 375;
		m_py = 275;

	//ブロックとの当たり判定
		if (map1 != nullptr)
		{
			map1->Map1Hit(&m_px, &m_py, true,
				&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
				&m_block_type
			);
		}
		if (map2 != nullptr)
		{
			map2->Map2Hit(&m_px, &m_py, true,
				&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
				&m_block_type
			);
		}
		if (map3 != nullptr)
		{
			map3->Map3Hit(&m_px, &m_py, true,
				&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
				&m_block_type
			);
		}
		if (map4 != nullptr)
		{
			map4->Map4Hit(&m_px, &m_py, true,
				&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
				&m_block_type
			);
		}
		if (map5 != nullptr)
		{
			map5->Map5Hit(&m_px, &m_py, true,
				&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
				&m_block_type
			);
		}


	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px+5, m_py+3);//HitBox主人公座標 + 位置調整

	//ELEMENT_ENEMYを持つオブジェクトと接触したら
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
		{
			HIT_DATA**hit_data;		//Hit時データ型、hit_dataを宣言
			hit_data = hit->SearchElementHit(ELEMENT_ENEMY);//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる

			for (int i = 0; i < hit->GetCount(); i++)//同時に複数のHitBoxに当たった場合、
			{										 //当たった数だけ処理させる為のループ
				//敵の左右に当たったら
				if (hit_data[i] == nullptr)
					continue;

				//ダメージ音を鳴らす
				Audio::Start(6);

				float r = hit_data[i]->r;
				if ((r < 45 && r >= 0) || r > 315)
				{
					m_vx = -10.0f;//左に移動させる
				}
				if (r >= 45 && r < 135)
				{
					m_vy = 10.0f;//上に移動させる
				}
				if (r >= 135 && r < 225)
				{
					m_vx = 10.0f;//右に移動させる
				}
				if (r >= 225 && r < 315)
				{
					m_vy = -10.0f;//したに移動させる

				}
			}
			m_hp -= 1;
			m_f = true;
			m_key_f = true;
			hit->SetInvincibility(true);//無敵オン
		}

		if (m_f == true)
		{
			m_time--;//無敵時間開始

			if (m_time == 30)
				m_key_f = false;

			alpha = 0.5f;
		}
		if (m_time <= 0)
		{
			m_f = false;
			hit->SetInvincibility(false);//無敵オフ
			alpha = 1.0f;
			m_time = 70;
		}

		//アイテムに当たった場合以下の処理をする
		if (hit->CheckElementHit(ELEMENT_ITEM) == true)
		{
			if (m_hp != m_hp_max) {//HPが最大値でない場合のみ回復
				if (hit->CheckObjNameHit(OBJ_PEACH) != nullptr)
				{
					m_hp += 1;
					Audio::Start(8);//回復音を鳴らす
				}
				if (hit->CheckObjNameHit(OBJ_YELLOW_PEACH) != nullptr)
				{
					Audio::Start(8);//回復音を鳴らす
					m_hp += 3;
				}
			}
			else {}//最大値の場合、回復出来ない
			if (hit->CheckObjNameHit(OBJ_PLUM) != nullptr)
				Audio::Start(2);//アイテム取得音を鳴らす
			if (hit->CheckObjNameHit(OBJ_CLUB) != nullptr)
				Audio::Start(2);//アイテム取得音を鳴らす
			if (hit->CheckObjNameHit(OBJ_HORN) != nullptr)
				Audio::Start(2);//アイテム取得音を鳴らす

			if (hit->CheckObjNameHit(OBJ_GOLD_BULLION) != nullptr)
				Audio::Start(2);//アイテム取得音を鳴らす

			if (hit->CheckObjNameHit(OBJ_SILVER_BULLION) != nullptr)
				Audio::Start(2);//アイテム取得音を鳴らす

			if (hit->CheckObjNameHit(OBJ_CLUB) != nullptr)
				Audio::Start(9);//デバフ音を鳴らす
								//移動速度を0.8倍する
								//m_px *= 0.8;
								//m_py *= 0.8;
		}

		if (hit->CheckElementHit(ELEMENT_FIELD) == true)
		{
			//階段SEを鳴らす
			Audio::Start(10);
			//遅延
			Sleep(1000);
		}

	//HPが0になったら破棄------死亡判定----------------------------------------------------------------
	if (m_hp <= 0)
	{
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人公データ取得
		hero->SetDATA();//主人公のデータを初期化

		this->SetStatus(false);	//自身に削除命令を出す
		Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する。

		Scene::SetScene(new CSceneGameOver());
	}
}

//ドロー
void CObjHero::Draw()
{
	int AniData[4] = { 0,1,2,1, };
	//描画カラー情報　R=RED　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,alpha, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top   =50.0f *  m_posture - 1;	 //微調整-1
	src.m_left  = 0.0f + (AniData[m_ani_frame] * 48);
	src.m_right =48.0f + (AniData[m_ani_frame] * 48);
	src.m_bottom=50.0f * (m_posture + 1) - 3;//微調整-3

	//表示位置の設定
	dst.m_top   = 0.0f + m_py;
	dst.m_left  = 0.0f + m_px;
	dst.m_right =50.0f + m_px;
	dst.m_bottom=50.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}