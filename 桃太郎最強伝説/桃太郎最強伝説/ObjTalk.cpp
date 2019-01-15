//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "ObjTalk.h"
#include "GameHead.h"

void CObjTalk::Init()
{
	m_page = 0;		//渡されたページ数
	m_sec = 0;		//秒数カウント
	m_line = 0;		//行数カウント
	m_picture = 9;	//画像番号変更用
}

void CObjTalk::Action()
{
	if (m_page == m_p) {//渡されたページ数と現在のページ数が同じになったら
		this->SetStatus(false);		//オブジェクト削除
	}

	//入力判定、押しっぱなし制御
	if (Input::GetVKey(VK_RETURN) == true)//エンターキー入力時
	{
		if (m_f == true){//m_fがtrueの場合
			m_page += 1;	//ページを１加算
			m_line = 0;		//行数リセット
			m_sec = 0;		//秒数リセット
			m_f = false;	//m_fにtrueを代入
		}
	}
	else//エンターキーを放している場合
		m_f = true;		//true代入
}

void CObjTalk::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	if (m_tipe == 0) {//tipe0は、吹き出し＆名前用画像を表示
		 //切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 128.0f;
		src.m_bottom = 64.0f;
		//表示位置の設定
		dst.m_top = 400.0f;
		dst.m_left = 20.0f;
		dst.m_right = 780.0f;
		dst.m_bottom = 580.0f;
		//描画
		Draw::Draw(m_picture, &src, &dst, c, 0.0f);

		if (m_p != 1) {//ページ数が1ではない場合
					   //同じ画像を名前用に上から表示
			CObjText* text = (CObjText*)Objs::GetObj(OBJ_TEXT);
			CObjSummary* summary = (CObjSummary*)Objs::GetObj(OBJ_SUMMARY);
			if (text != nullptr || summary != nullptr)
			{
				//表示位置の設定
				dst.m_top = 380.0f;
				dst.m_left = 30.0f;
				dst.m_right = 200.0f;
				dst.m_bottom = 420.0f;
			}
			else
			{
				//表示位置の設定
				dst.m_top = 380.0f;
				dst.m_left = 30.0f;
				dst.m_right = 100.0f;
				dst.m_bottom = 420.0f;
			}
			//描画
			Draw::Draw(m_picture, &src, &dst, c, 0.0f);
		}
		else { ; }
	}


	else if (m_tipe == 1) {//tipe1は、コメントを隠す画像表示
		if (m_sec <= 715) {//715(コメントの幅)まで時間経過
			m_sec += 5;	   //文字の表示スピード---------------------
		}				   //幅を超えると、行数を+1
		else {
			m_line += 1;
			m_sec = 0;
		}

		//切り取り位置の設定(画像の黒い部分に設定)
		src.m_top = 10.0f;
		src.m_left = 10.0f;
		src.m_right = 120.0f;
		src.m_bottom = 60.0f;

		if (m_p != 1) {
			if (m_line == 0) {//１行目ーーーーーーーーーーーーーーーーーーーーーーー
							  //表示位置の設定
				dst.m_top = 440.0f;
				if (m_line == 0)//１行目の時のみ動作
					dst.m_left = 50.0f + (m_sec*1.0f);
				else
					dst.m_left = 50.0f;
				dst.m_right = 765.0f;
				dst.m_bottom = 470.0f;
				//描画
				Draw::Draw(m_picture, &src, &dst, c, 0.0f);
			}//行が変わると、表示しない
			else { ; }
			if (m_line <= 1) {//２行目ーーーーーーーーーーーーーーーーーーーーーーーー
							  //表示位置の設定
				dst.m_top = 480.0f;
				if (m_line == 1)//２行目の時のみ動作
					dst.m_left = 50.0f + (m_sec*1.0f);
				else
					dst.m_left = 50.0f;
				dst.m_right = 765.0f;
				dst.m_bottom = 510.0f;
				//描画
				Draw::Draw(m_picture, &src, &dst, c, 0.0f);
			}//行が変わると、表示しない
			else { ; }
			if (m_line <= 2 && m_p != 1) {//３行目ーーーーーーーーーーーーーーーーーー
										  //表示位置の設定
				dst.m_top = 520.0f;
				if (m_line == 2)//３行目の時のみ動作
					dst.m_left = 50.0f + (m_sec*1.0f);
				else
					dst.m_left = 50.0f;
				dst.m_right = 765.0f;
				dst.m_bottom = 550.0f;
				//描画
				Draw::Draw(m_picture, &src, &dst, c, 0.0f);
			}//行が変わると、表示しない
			else { ; }
		}

		if (m_line <= 3 || m_p == 1) {//・・・ーーーーーーーーーーーーーーーー
			dst.m_top = 550.0f;
			if (m_line > 2 || m_p == 1)//３行目以降、動作
				if (m_sec <= 160)//表示位置を段階的に変更
					dst.m_left = 745.0f;
				else if (m_sec <= 280)
					dst.m_left = 760.0f;
				else if (m_sec <= 440)
					dst.m_left = 770.0f;
				else if (m_sec <= 600)
					dst.m_left = 730.0f;
				else { dst.m_left = 730.0f; m_sec = 0; }//カウントを０にして、元に戻す
			else
				dst.m_left = 730.0f;
			dst.m_right = 770.0f;
			dst.m_bottom = 575.0f;
			//描画
			Draw::Draw(m_picture, &src, &dst, c, 0.0f);
		}
		else { ; }
	}

	else if (m_tipe == 2) {
		//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
		float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
		RECT_F src; //描画元切り取り位置
		RECT_F dst; //描画先表示位置
					//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 600.0f;
		src.m_bottom = 600.0f;
		//表示位置の設定
		dst.m_top = 250.0f;
		dst.m_left = 50.0f;
		dst.m_right = 250.0f;
		dst.m_bottom = 450.0f;
		Draw::Draw(18, &src, &dst, c, 0.0f);
	}
	else if (m_tipe == 3) {
		//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
		float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
		RECT_F src; //描画元切り取り位置
		RECT_F dst; //描画先表示位置
					//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 600.0f;
		src.m_bottom = 600.0f;
		//表示位置の設定
		dst.m_top = 250.0f;
		dst.m_left = 50.0f;
		dst.m_right = 250.0f;
		dst.m_bottom = 450.0f;
		Draw::Draw(19, &src, &dst, c, 0.0f);
	}
	else if (m_tipe == 4) {
		//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
		float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
		RECT_F src; //描画元切り取り位置
		RECT_F dst; //描画先表示位置
					//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 800.0f;
		//表示位置の設定
		dst.m_top = 250.0f;
		dst.m_left = 50.0f;
		dst.m_right = 250.0f;
		dst.m_bottom = 450.0f;
		Draw::Draw(20, &src, &dst, c, 0.0f);
	}
}