//使用するヘッダーファイル
#include <stdlib.h>
#include <time.h>
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include <Windows.h>
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjMap5.h"

//使用するネームスペース
using namespace GameL;

CObjMap5::CObjMap5(int map[56][56])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(56 * 56));
}

void CObjMap5::Setwall(bool type)
{
	if (type == true)
		for (int i = 0; i < 56; i++)
		{
			for (int j = 0; j < 56; j++)
			{
				if (m_map[i][j] == 3)
					m_map[i][j] = 13;
			}
		}
}

//イニシャライズ
void CObjMap5::Init()
{
	m_f = 0;

	srand(time(NULL));

//	setstair();
//	setenemy();
//	sethero();


	//アイテム出現
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 5)
			{
				//アイテムオブジェクト作成
				CObjPeach* p = new CObjPeach(j * 50.0f, i * 50.0f);		//オブジェクト作成
				Objs::InsertObj(p, OBJ_PEACH, 2);	//マネージャに登録

			}
		}
	}

/*	//敵出現
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 10)
			{
				//青鬼オブジェクト作成
				CObjEnemy* e = new CObjEnemy(j*50.0f, i*50.0f);
				Objs::InsertObj(e, OBJ_ENEMY, 2);
			}
			if (m_map[i][j] == 11)
			{
				//黄鬼オブジェクト作成
				CObjEnemy2* e2 = new CObjEnemy2(j*50.0f, i*50.0f);
				Objs::InsertObj(e2, OBJ_ENEMY2, 2);
			}
					else if (m_map[i][j] == 12)
			{
			//緑鬼オブジェクト作成
			CObjEnemy3* e3 = new CObjEnemy3(j*50.0f, i*50.0f);
			Objs::InsertObj(e3, OBJ_ENEMY3, 5);
			}
		}
	}*/

	//BOSS出現
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 13)
			{
				//ボスオブジェクト
				CObjBoss*obj_boss_enemy = new CObjBoss(j*50.0f,i*50.0f);
				Objs::InsertObj(obj_boss_enemy, OBJ_BOSS, 2); 
			}
		}
	}

	//主人公出現
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 27)
			{
				//主人公オブジェクト作成
				CObjHero* obj = new CObjHero(j*50.0f, i*50.0f);//オブジェクト作成
				Objs::InsertObj(obj, OBJ_HERO, 10);//マネージャに登録

				m_scrollx = -j * 50.0f + 400;
				m_scrolly = -i * 50.0f + 300;
			}
		}
	}




}
//アクション
void CObjMap5::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//シーン切り替え
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 4)
			{
				//階段オブジェクト作成
				CObjstair* s = new CObjstair(j * 50.0f, i * 50.0f,5);		//オブジェクト作成
				Objs::InsertObj(s, OBJ_STAIR, 2);	//マネージャに登録
				m_map[i][j] = 0;
			}
		}
	}
	if (m_f == 0)
	{
		//主人公の位置を取得
		float hx = hero->GetX();
		float hy = hero->GetY();

		//スクロール
		hero->SetX(375);
		m_scrollx -= hero->GetVX() * 4;

		hero->SetY(275);
		m_scrolly -= hero->GetVY() * 4;
	}
}
//ドロー
void CObjMap5::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,0.5f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //マップチップによるblock配置
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] >= 0)
			{
				//表示位置の設定
				dst.m_top = i*50.0f + m_scrolly;				//マップサイズ,初期位置
				dst.m_left = j*50.0f + m_scrollx;
				dst.m_right = dst.m_left + 50.0f;
				dst.m_bottom = dst.m_top + 50.0f;
			}
			if (m_map[i][j] == 1)
			{
				//壁
				BlockDraw(47.0f, 0.0f, &dst, c);
			}
			else if (m_map[i][j] == 0 || m_map[i][j] == 2 || m_map[i][j] >= 5)
			{
				//床
				BlockDraw(0.0f, 0.0f, &dst, c);
			}
			else
			{
				//壁
				BlockDraw(47.0f, 0.0f, &dst, c);
			}
		}
	}
}

//BlockDrawMethod関数
//引数１　float	x	:リソース切り取り位置X
//引数２　float	y	:リソース切り取り位置Y
//引数３　RECT_F* dst :描画位置
//引数４　float	c[]	:カラー情報
//ブロックを64*64限定描画用。リソース切り取り位置のみx,yで
//設定できる
void CObjMap5::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 47.0f;
	src.m_bottom = src.m_top + 47.0f;
	//描画
	Draw::Draw(1, &src, dst, c, 0.0f);
}

//BlockHit変数
//引数１　float* x			：判定を行うobjectのX位置
//引数２　float* y			：判定を行うobjectのY位置
//引数３　bool  scroll		：判定を行うobjectはスクロールの影響与えるかどうか（true=与える、false=与えない）
//引数４　bool* up			：上下左右判定の上部分に当たっているかどうかを返す
//引数５　bool* down		：上下左右判定の下部分に当たっているかどうかを返す
//引数６　bool*left			：上下左右判定の左部分に当たっているかどうかを返す
//引数７　bool*right		：上下左右判定の右部分に当たっているかどうかを返す
//引数８　float* vx			：左右判定時の反発による移動方向・力の値を変えて返す
//引数９　float* vy			：上下判定時による自由落下運動の移動方向・力の値を変えて返す
//引数10　int* bt			：下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック50*50限定で、当たり判定と上下左右判定を行う
//その結果は引数４～10に返す
void CObjMap5::Map5Hit
(
	float *x, float *y, bool scroll_on,
	bool*up, bool* down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//主人公の衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 1 || m_map[i][j] == 3)
			{
				//要素番号を座標に変更
				float bx = j*50.0f;
				float by = i*50.0f;

				//スクロールの影響
				float scrollx = scroll_on ? m_scrollx : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scrollx) + 50.0f > bx) && (*x + (-scrollx) < bx + 50.0f) && (*y + (-scrolly) + 50.0f > by) && (*y + (-scrolly) < by + 50.0f))
				{
					//上下左右判定

					//Vectorの作成
					float rvx = (*x + (-scrollx)) - bx;
					float rvy = (*y + (-scrolly)) - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r >= 0) || r > 315)
						{
							*right = true;//オブジェクトの左部分が衝突している
							*x = bx + 50.0f + (scrollx);//ブロックの位置+オブジェクトの幅
							*vx = 0.5f;//-VX*反発係数
						}

						if (r > 45 && r < 135)
						{
							*down = true;//オブジェクトの下の部分が衝突している
							*y = by - 50.0f + (scrolly);//ブロックの位置-オブジェクトの幅
							*vy = -0.5f;
						}
						if (r > 135 && r < 225)
						{
							*left = true;//オブジェクトの右部分が衝突している
							*x = bx - 50.0f + (scrollx);//ブロックの位置-オブジェクトの幅
							*vx = -0.5f;//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							*up = true;//オブジェクトの上の部分が衝突している
							*y = by + 50.0f + (scrolly);//ブロックの位置+オブジェクトの幅							
							*vy = 0.5f;

						}
					}
				}
			}
		}
	}
}

/*void CObjMap5::setenemy()
{
	//敵出現位置の設定
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			//15を発見
			if (m_map[i][j] == 15)
			{
				//15の中から出現場所を決定する
				int herop = 0;
				herop = rand() % 2;
				if (herop == 0)
				{
					m_map[i][j] = 10;//青鬼
				}
				else if (herop == 1)
				{
					m_map[i][j] = 11;//黄鬼
				}
				/*				else if (herop == 2)
				{
				m_map[i][j] = 12;//緑鬼
				}
			}
		}
	}
}*/