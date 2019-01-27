//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "ObjInventory.h"
#include "GameL\Audio.h"
//使用するネームスペース
using namespace GameL;

//Date.cpp内で宣言したグローバル変数をextern宣言----------------------保持データ
extern int HP;				//HP
extern bool OTOMO[3];		//お供所持情報
extern int item_list[7];	//
extern int c, s, m;
void CObjHero::SaveDATA() {		//セーブ関数----------------------データをセーブ
	HP = m_hp;					//シーン切り替え時のhpデータを、HPへ格納
	ObjCharView* cv = (ObjCharView*)Objs::GetObj(OBJ_CV);//オブジェ情報取得
	cv->SaveSM();//セーブ、セコンドミニッツ
}
void CObjHero::SetDATA() {		//セット関数----------------------データをセット
	HP = 5;						//ゲームオーバー後、HPを初期値に戻す
	for (int n = 0; n <= 2; n++)
		OTOMO[n] = false;
	c = 0, s = 0, m = 0;
}
//シーン表示時の暗闇作成()又は、イベントから関数を使って暗闇を開放していく時(false)
void CObjHero::SetYAMI(bool tipe) {//暗闇セット関数-----------------------暗闇
	m_image = 15;				//初期化
	for (int nam = 0; nam < 3; nam++) {//お供の数を確認して画像番号代入
		if (OTOMO[nam] == true)	//各お供が居るなら
			m_image += 1;		//画像番号+1
	}
	if (tipe == true){			//SetYAMI(true or 空白)
		ObjCapture* yami = new ObjCapture(m_image);	//暗闇作成
		Objs::InsertObj(yami, OBJ_CAPTURE, 3);		//登録
	}
	else{						//SetYami(false)
		ObjCapture* yami = (ObjCapture*)Objs::GetObj(OBJ_CAPTURE);
		yami->SetImage(m_image);
	}
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
	m_speed = 1.0f;			//速度

	
	m_Sf = true;		//ソード制御
	m_Kf = true;		//  キジ制御

	//OTOMO[0犬,1キジ,2猿] == true(ある) or false(ない)
	if (OTOMO[0] == true)		//犬が居る場合
	{
		m_hp_max = 6;			//最大HPを6にセット
	}
	if (OTOMO[1] == true)		//猿が居る場合
	{
		m_speed = 1.2f;			//速度
	}
	if (OTOMO[2] == true)		//キジが居る場合
	{
		m_Kf = false;			//制御を解除
	}
	SetYAMI();					//暗闇作成
	

	m_hp = HP;				//メンバhpにHPを代入
	m_time = 70;
	alpha = 1.0f;
	count = 10;

	m_posture = 0;	//正面(0) 左(1) 右(2) 背面(3)
	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレーム
	m_key_f = false;		//無敵時間行動制御
	m_If = true;			//持ち物リスト制御
	m_Mf = false;			//持ち物リスト表示フラグ管理
	m_Pf = false;
	m_Pf1 = true;
	m_stime = 13;
	m_Sf = true;
	m_of = true;
	m_of_d = false;

	df = true;
	mf = true;
	pf = true;
	

	//HitBox作成座標とサイズx,y、エレメントとオブジェクトを設定
	Hits::SetHitBox(this, m_px + 5, m_py + 3, 40, 47, ELEMENT_PLAYER, OBJ_HERO, 1);

	Audio::LoadAudio(2, L"アイテムゲット.wav", EFFECT);		//アイテム取得時SE
	Audio::LoadAudio(3, L"近接攻撃.wav", EFFECT);			//近接攻撃SE
	Audio::LoadAudio(4, L"kijiSE.wav", EFFECT);				//遠距離攻撃SE
	Audio::LoadAudio(5, L"damage.wav", EFFECT);				//ダメージSE
	Audio::LoadAudio(6, L"heal.wav", EFFECT);				//体力回復時SE
	Audio::LoadAudio(7, L"speeddown.wav", EFFECT);			//棍棒取得時用SE
	Audio::LoadAudio(8, L"ButtonSE.wav", EFFECT);				//コマンドSE

																//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//BGMボリュームを下げる
	float Volume = Audio::VolumeMaster(-0.95f);

}

//アクション
void CObjHero::Action()
{
	//ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + 5, m_py + 3);//HitBox主人公座標 + 位置調整


	//各情報を取得
	CObjPose* pob = (CObjPose*)Objs::GetObj(OBJ_POSE);
	CObjInventory* iob = (CObjInventory*)Objs::GetObj(OBJ_INVENTORY);
	CObjOD* od = (CObjOD*)Objs::GetObj(OBJ_OD);

	//操作説明表示中は動作を止める
	if (od != nullptr)
	{
		m_key_f = true;
	}

	//ポーズ
	if (pob == nullptr)
		m_Pf = false;
	while (1)
	{
		if (Input::GetVKey('M') == true)//Mキー入力時
		{

			if (m_Pf == true) {//m_fがtrueの場合
							   //コマンド用SEを鳴らす
				if (od == nullptr || iob == nullptr)
				{
					Audio::Start(8);
					while (1)
					{
						//ポーズが表示されていたらポーズを非表示にする

						if (m_Pf == true)
						{
							//Xを押してTitleに移行する
							if (Input::GetVKey('Z') == true)
							{
								//タイトルに移動
								Scene::SetScene(new CSceneTitle());
								break;

							}
						}
						if (Input::GetVKey('X') == true)//Zキー入力時
						{
							if (m_Pf == true) {

								Audio::Start(8);
								//ポーズオブジェクトを削除
								if (pob != nullptr)
									pob->SetAf(true);
								break;
							}
						}

					}
				}

			}

			if (m_Pf == false) {
				//ポーズオブジェクト作成
				CObjPose* po = new CObjPose();       //ポーズオブジェクト作成
				Objs::InsertObj(po, OBJ_POSE, 11);    //ポーズオブジェクト登録
				m_Pf = true;

			}
			else {}
		}
		break;
	}



	//持ち物リスト------------------------------------------------------------------------------
	//

	if (iob == nullptr)
		m_Mf = false;
	if (Input::GetVKey('I') == true)//Iキー入力時
	{

		if (m_If == true)
		{
			if (od == nullptr || pob == nullptr)
			{
				//コマンド用SEを鳴らす
				Audio::Start(8);
				//持ち物リストが表示されていたら持ち物リストを非表示にする
				if (m_Mf == true) {
					if (iob != nullptr)
						iob->SetEf(true);
				}

				if (m_Mf == false)
				{
					//持ち物リスト表示
					CObjInventory* it = new CObjInventory();       //持ち物オブジェクト作成
					Objs::InsertObj(it, OBJ_INVENTORY, 50);    //持ち物オブジェクト登録
															   //非表示フラグを立てる
					m_Mf = true;
				}
				m_If = false;
			}
		}
	}
	else //無入力時
	{
		m_If = true;

	}

	//操作説明

	if (od == nullptr)
		m_of_d = false;
	if (Input::GetVKey('H') == true)//Hキー入力時
	{

		if (m_of == true)
		{
			if (od == nullptr || pob == nullptr)
			{
				//コマンド用SEを鳴らす
				Audio::Start(8);
				//操作説明を非表示にする
				if (m_of_d == true) {
					od->SetOf(true);
				}

				if (m_of_d == false)
				{
					//操作説明表示
					CObjOD* od = new CObjOD();       //持ち物オブジェクト作成
					Objs::InsertObj(od, OBJ_OD, 50);    //持ち物オブジェクト登録
					//非表示フラグを立てる
					m_of_d = true;
				}
				m_of = false;
			}
		}
	}
	else //無入力時
	{
		m_of = true;

	}



	//通常攻撃処理---------------------------------------------------------------------
	if (m_key_f == false)
	{
		if (Input::GetVKey('A') == true && hit->CheckElementHit(ELEMENT_RED) == false)//Aキー入力時かつおともに当たっていないとき
		{
			CObjSword* sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);//剣の情報を取得
			if (sword == nullptr)//剣が無い場合
			{
				if (m_Sf == true) {//m_fがtrueの場合
					//近距離攻撃音を鳴らす
					Audio::Start(3);
					//剣オブジェクト作成			剣に座標と向きを渡す
					CObjSword* swd = new CObjSword(m_px, m_py, m_posture);
					Objs::InsertObj(swd, OBJ_SWORD, 3);//マネージャーに登録

					m_Sf = false;
				}
			}
		}
		else		//放している場合
			m_Sf = true;//trueを代入

		//キジ攻撃処理------------------------------------------------------------------
		//キジの情報を取得
		CObjFlyKiji* obj = (CObjFlyKiji*)Objs::GetObj(OBJ_FLYKIJI);
		if (Input::GetVKey('S') == true && hit->CheckElementHit(ELEMENT_RED) == false)//Sキー入力時かつおともに当たっていないとき
		{
			if (m_Kf == false) {
				if (obj == nullptr)//キジ情報が無い場合
				{
					//遠距離攻撃音を鳴らす
					Audio::Start(4);

					//キジオブジェクト作成				キジに座標と向きを渡す
					CObjFlyKiji* kiji = new CObjFlyKiji(m_px, m_py, m_posture);
					Objs::InsertObj(kiji, OBJ_FLYKIJI, 3);//マネージャーに登録

				}
			}
		}




		//主人公移動キー入力判定--------------------------------------------------------
		if (Input::GetVKey(VK_RIGHT) == true)//→
		{
			m_vx += m_speed;				//移動ベクトル加算(初期値1,お供バフ1.5)
			m_posture = 2;					//向き情報代入
			m_ani_time += 1;				//アニメーション時間加算
		}
		else if (Input::GetVKey(VK_UP) == true)	//↑
		{
			m_vy -= m_speed;
			m_posture = 3;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_DOWN) == true)//↓
		{
			m_vy += m_speed;
			m_posture = 0;
			m_ani_time += 1;
		}
		else if (Input::GetVKey(VK_LEFT) == true)//←
		{
			m_vx -= m_speed;
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
			Audio::Start(5);

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
				m_hp += 1; //HPを1回復
				Audio::Start(6);//回復音を鳴らす
			}
			else if (hit->CheckObjNameHit(OBJ_YELLOW_PEACH) != nullptr)
			{
				if (m_hp < m_hp_max - 1) {
					m_hp += 2;		//HPを2回復
				}
				else {
					m_hp += 1;	//HPを1回復
				}
				Audio::Start(6);//回復音			
			}
			else if (hit->CheckObjNameHit(OBJ_PLUM) != nullptr)
			{
				item_list[2]++;
				Audio::Start(2);//アイテム取得音
			}
			else if (hit->CheckObjNameHit(OBJ_HORN) != nullptr)
			{
				item_list[3]++;
				Audio::Start(2);//アイテム取得音
			}
			else if (hit->CheckObjNameHit(OBJ_GOLD_BULLION) != nullptr)
			{

				item_list[4]++;
				Audio::Start(2);//アイテム取得音
			}
			else if (hit->CheckObjNameHit(OBJ_SILVER_BULLION) != nullptr)
			{
				item_list[5]++;
				Audio::Start(2);//アイテム取得音
			}
			else if (hit->CheckObjNameHit(OBJ_CLUB) != nullptr)
			{
				item_list[6]++;
				Audio::Start(7);//デバフ音
			}
		}
		else //最大値の場合、回復出来ない
		{
			if (hit->CheckObjNameHit(OBJ_PEACH) != nullptr)
			{
				item_list[0]++;
				Audio::Start(2);//アイテム取得音
			}
			else if (hit->CheckObjNameHit(OBJ_YELLOW_PEACH) != nullptr)
			{
				item_list[1]++;
				Audio::Start(2);//アイテム取得音			
			}
			else if (hit->CheckObjNameHit(OBJ_PLUM) != nullptr)
			{
				item_list[2]++;
				Audio::Start(2);//アイテム取得音
			}
			else if (hit->CheckObjNameHit(OBJ_HORN) != nullptr)
			{
				item_list[3]++;
				Audio::Start(2);//アイテム取得音
			}
			else if (hit->CheckObjNameHit(OBJ_GOLD_BULLION) != nullptr)
			{
				item_list[4]++;
				Audio::Start(2);//アイテム取得音
			}
			else if (hit->CheckObjNameHit(OBJ_SILVER_BULLION) != nullptr)
			{
				item_list[5]++;
				Audio::Start(2);//アイテム取得音
			}
			else if (hit->CheckObjNameHit(OBJ_CLUB) != nullptr)
			{
				item_list[6]++;
				Audio::Start(7);//デバフ音
			}
		}
	}


	//おともの当たり判定
	HIT_DATA**hit_data;		//Hit時データ型、hit_dataを宣言
	hit_data = hit->SearchElementHit(ELEMENT_RED);//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる

	for (int i = 0; i < hit->GetCount(); i++)//同時に複数のHitBoxに当たった場合、
	{										 //当たった数だけ処理させる為のループ
		if (hit_data[i] == nullptr)
			continue;
		float r = hit_data[i]->r;
		if ((r < 45 && r >= 0) || r > 315)
		{
			if (Input::GetVKey(VK_RIGHT) == true) //→
				m_vx = 0.0f;
		}
		if (r >= 45 && r < 135)
		{
			if (Input::GetVKey(VK_UP) == true)//↑
				m_vy = 0.0f;
		}
		if (r >= 135 && r < 225)
		{
			if (Input::GetVKey(VK_LEFT) == true)//←
				m_vx = 0.0f;
		}
		if (r >= 225 && r < 315)
		{
			if (Input::GetVKey(VK_DOWN) == true)//↓
				m_vy = 0.0f;
		}
	}

	//おともイベント
	if (hit->CheckElementHit(ELEMENT_RED) == true)
	{
		if (Input::GetVKey('F') == true)//Fキー入力時
		{
			//持ち物リストが開いていたら閉じる
			CObjInventory* iob = (CObjInventory*)Objs::GetObj(OBJ_INVENTORY);
			if (iob != nullptr)
				iob->SetEf(true);


				if (hit->CheckObjNameHit(OBJ_DOG) && df ==true)//犬に当たった場合
				{
					//犬イベント発生
					CObjEveDog* evedog = new CObjEveDog();//オブジェクト作成
					Objs::InsertObj(evedog, OBJ_EVEDOG, 10);//マネージャに登録

				df = false;

				m_hp_max = 6;
				OTOMO[0] = true;
			}
			else if (hit->CheckObjNameHit(OBJ_MONKE) && mf == true)//猿に当たった場合
			{
				//猿イベント発生
				CObjEveMnky* evemonky = new CObjEveMnky();//オブジェクト作成
				Objs::InsertObj(evemonky, OBJ_EVEMNKY, 10);//マネージャに登録

				mf = false;

				m_speed = 1.2f;
				OTOMO[1] = true;
			}
			else if (hit->CheckObjNameHit(OBJ_PHEASANT) && pf == true)//キジに当たった場合
			{
				//雉イベント発生
				CObjEveKiji* kiji = new CObjEveKiji();//オブジェクト作成
				Objs::InsertObj(kiji, OBJ_EVEKIJI, 10);//マネージャに登録

				pf = false;

				m_Kf = false;
				OTOMO[2] = true;
			}
		}
	}

		//主人公の情報を取得
		CObjEveDog* evedog = (CObjEveDog*)Objs::GetObj(OBJ_EVEDOG);
		CObjEveKiji* evekiji = (CObjEveKiji*)Objs::GetObj(OBJ_EVEKIJI);
		CObjEveMnky* evemnky = (CObjEveMnky*)Objs::GetObj(OBJ_EVEMNKY);
		CObjText* text = (CObjText*)Objs::GetObj(OBJ_TEXT);
		if (text != nullptr || evedog != nullptr || evekiji != nullptr || evemnky != nullptr)
		{
			m_key_f = true;
		}
		else
			m_key_f = false;

	//HPが0になったら破棄------死亡判定----------------------------------------------------------------
	if (m_hp <= 0)
	{
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人公データ取得
		hero->SetDATA();//主人公のデータを初期化

		this->SetStatus(false);	//自身に削除命令を出す
		Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する。

		Scene::SetScene(new CSceneGameOver());
	}
	else {}

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