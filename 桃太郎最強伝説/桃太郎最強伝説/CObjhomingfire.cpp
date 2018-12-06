//使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"CObjhomingfire.h"
#include"GameHead.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;

CObjHomingfire::CObjHomingfire(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjHomingfire::Init()
{
	m_vx = -1.0f;
	m_vy = 0.0f;
	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);
	//当たり判定用Hitboxを作成
	Hits::SetHitBox(this, m_x, m_y, 50, 50, ELEMENT_ENEMY, OBJ_BULLET, 1);
}

//アクション
void CObjHomingfire::Action()
{
	//主人公機と誘導弾丸で角度を取る
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//主人公機が存在する場合、誘導角度の計算する
	if (obj != nullptr)
	{
		CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);
		
		float x = 400 - (m_x + map5->GetScrollx());
		float y = 300 - (m_y + map5->GetScrolly());
		float ar = GetAtan2Angle(x, y);

		//弾丸の現在の向いている角度を取る
		float br = GetAtan2Angle(m_vx, m_vy);

		//主人公機と敵機角度があんまりにもかけ離れたら
		m_vx = cos(3.14 / 180 * ar);
		m_vy = sin(3.14 / 180 * ar);
		
		UnitVec(&m_vx, &m_vy);
	}
	//移動
	m_x += m_vx * 3.0f;
	m_y += m_vy * 3.0f;

	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + map5->GetScrollx(), m_y + map5->GetScrolly());

	//主人公オブジェクトと接触したら敵機弾丸削除
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr || hit->CheckElementHit(ELEMENT_MAGIC) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}
//ドロー
void CObjHomingfire::Draw()
{
	//描画カラー情報　R=RED　G=Green　B=Blue　A=alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;

	CObjMap5*map5 = (CObjMap5*)Objs::GetObj(OBJ_MAP5);

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 300.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y + map5->GetScrolly();
	dst.m_left = 0.0f + m_x + map5->GetScrollx();
	dst.m_right = 50.0f + m_x + map5->GetScrollx();
	dst.m_bottom = 50.0f + m_y + map5->GetScrolly();

	float r = 0.0f;
	//主人公機と誘導弾丸で角度を取る
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//主人公機が存在する場合、誘導角度の計算する
	if (obj != nullptr)
	{
		float x = 375 - dst.m_top;
		float y = 275 - dst.m_left;
		r = GetAtan2Angle(x, y)+30;

	}
	//8番目に登録したグラフィックをsrc・dst・cの元に描画
	Draw::Draw(10, &src, &dst, c, r);

}