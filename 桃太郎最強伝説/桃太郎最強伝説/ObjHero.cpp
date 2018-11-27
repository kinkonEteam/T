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

extern int HP;		//Date.cpp内で宣言したグローバル変数をextern宣言

CObjHero::CObjHero(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjHero::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;

	m_hp = HP;			//初期HP５
	m_time = 70;
	alpha = 1.0f;
	count = 10;

	m_posture = 0.0f;	//正面(0.0f) 左(1.0f) 右(2.0f) 背面(3.0f)
	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレーム
	m_Sf = true;			//攻撃制御
	m_Kf = true;			//キジ攻撃制御
	m_key_f = false;		//無敵時間行動制御
	m_t = false;

	//HitBox作成座標とサイズx,y、エレメントとオブジェクトを設定
	Hits::SetHitBox(this, m_px+5, m_py+3, 40, 47, ELEMENT_PLAYER, OBJ_HERO, 1);

	Audio::LoadAudio(4, L"近接攻撃.wav", EFFECT);			//近接攻撃SE
	Audio::LoadAudio(5, L"kijiSE.wav", EFFECT);				//遠距離攻撃SE
	Audio::LoadAudio(6, L"damage.wav", EFFECT);				//ダメージSE
	Audio::LoadAudio(8, L"heal.wav", EFFECT);				//体力回復時SE
	Audio::LoadAudio(9, L"speeddown.wav", EFFECT);			//棍棒取得時用SE

	//音量を0.9下げる
	float Volume = Audio::VolumeMaster(-0.9f);
}

//アクション
void CObjHero::Action()
{
	//ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	
	if (m_key_f==false)
	{
		//攻撃の入力判定、押しっぱなし制御
		if (Input::GetVKey('A') == true)
		{
			if (m_Sf == true)
			{
				//近距離攻撃音を鳴らす
				Audio::Start(4);
				//剣オブジェクト作成		ここで剣に座標と向きを渡す
				CObjSword* swd = new CObjSword(m_px, m_py, m_posture);//作成
				Objs::InsertObj(swd, OBJ_SWORD, 3);	//マネージャーに登録

				m_Sf = false;
			}
		}
		else//放している場合
			m_Sf = true;


		//キジの情報を取得
		CObjFlyKiji* obj = (CObjFlyKiji*)Objs::GetObj(OBJ_FLYKIJI);
		if (Input::GetVKey('S') == true)
		{
			if (obj == nullptr)//キジ情報が存在しない場合
			{
				//遠距離攻撃音を鳴らす
				Audio::Start(5);

				//キジオブジェクト作成				キジに座標と向きを渡す
				CObjFlyKiji* kiji = new CObjFlyKiji(m_px, m_py, m_posture);//作成
				Objs::InsertObj(kiji, OBJ_FLYKIJI, 3);	//マネージャーに登録
			}
		}
		else //押してない場合
		{
			;//何もしない
		}

		//主人公の移動にベクトルを入れる
		if (Input::GetVKey(VK_RIGHT) == true)//→
		{
			m_vx += 1.0f;
			m_posture = 2.0f;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_UP) == true)	//↑
		{
			m_vy -= 1.0f;
			m_posture = 3.0f;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_DOWN) == true)//↓
		{
			m_vy += 1.0f;
			m_posture = 0.0f;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_LEFT) == true)//←
		{
			m_vx -= 1.0f;
			m_posture = 1.0f;
			m_ani_time += 1;
		}
		else
		{
			m_ani_frame = 1;	//キー入力がない場合は静止フレームにする
			m_ani_time = 0;
		}
	}


	if (m_ani_time > 6)		//アニメーション動作間隔(※ここでアニメーション速度変更出来る)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
		m_ani_frame = 0;	//フレーム4で0に戻す

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//スクロール
	CObjMap1*b = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
		m_px = 375;
		m_py = 275;

	//ブロックとの当たり判定
	CObjMap1*pb = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	pb->Map1Hit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px+5, m_py+3);

	//ELEMENT_ENEMYを持つオブジェクトと接触したら
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
		{
			//主人公が敵とどの角度で当たっているかを確認
			HIT_DATA**hit_data;							//当たった時の細かな情報を入れるための構造体
			hit_data = hit->SearchElementHit(ELEMENT_ENEMY);//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる

			for (int i = 0; i < hit->GetCount(); i++)
			{
				//ダメージ音を鳴らす
				Audio::Start(6);

				//敵の左右に当たったら
				float r = hit_data[i]->r;
				if ((r < 45 && r >= 0) || r > 315)
				{
					m_t = true;
					if (m_t == true)
					{
						m_vx += -1.0f;//左に移動させる
					}
				}
				if (r > 45 && r < 135)
				{
					m_vy = 10.0f;//上に移動させる
				}
				if (r > 135 && r < 225)
				{
					m_vx = 10.0f;//右に移動させる
				}
				if (r > 225 && r < 315)
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
			if (hit->CheckObjNameHit(OBJ_PLUM) != nullptr)
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
	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		CObjMap1* map1 = (CObjMap1*)Objs::GetObj(OBJ_MAP1);//外すとエラーが出る
		map1->Setenemy(1);
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