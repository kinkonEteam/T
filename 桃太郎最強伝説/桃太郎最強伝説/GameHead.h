#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_MAP1,
	OBJ_MAP2,
	OBJ_MAP3,
	OBJ_MAP4,
	OBJ_MAP5,
	OBJ_BOSS,
	OBJ_HERO,
	OBJ_SWORD,
	OBJ_FLYKIJI,
	OBJ_ITEM,
	OBJ_PEACH,
	OBJ_YELLOW_PEACH,
	OBJ_PLUM,
	OBJ_HORN,
	OBJ_GOLD_BULLION,
	OBJ_SILVER_BULLION,
	OBJ_CLUB,
	OBJ_ENEMY,
	OBJ_ENEMY2,
	OBJ_DOG,
	OBJ_MONKE,
	OBJ_PHEASANT,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_CLEAR,
	OBJ_TALK,
	OBJ_EVEDOG,
	OBJ_HEROGAUGE,
	OBJ_EVEKIJI,
	OBJ_EVEMNKY,
	OBJ_ITEMEFFE,
	OBJ_YAMI,
	OBJ_BULLET,
	OBJ_HOMING_FIRE,
	OBJ_POSE,
	OBJ_OD,
	OBJ_STAIR,
	OBJ_CAPTURE,		
	OBJ_CV,	
	OBJ_INVENTORY,
	OBJ_SCORE,
	OBJ_ITEMSETSUMEI,
	OBJ_TEXT,
	OBJ_SUMMARY,
	OBJ_SELL,
	OBJ_TEXT3,
	OBJ_TEXT4,
	OBJ_TEXT5,

};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
				 //以下　同じ属性同士では当たり判定は実行されない
				 //属性は追加可能だが、デバック時の色は初期設定分しか無い
				 ELEMENT_PLAYER,
				 ELEMENT_ENEMY,
				 ELEMENT_ITEM,
				 ELEMENT_MAGIC,
				 ELEMENT_FIELD,
				 ELEMENT_RED,
				 ELEMENT_GREEN,
				 ELEMENT_BLUE,
				 ELEMENT_BLACK,
				 ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	int m_point;	//GameMainで得たポイント
	int m_ranking[10];//ランキング情報
	int m_timerank[10][3];//タイムランク
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--
enum ITEM
{
	PEACH,				//アイテム　桃
	YELLOW_PEACH,		//アイテム　黄桃
	PLUM,				//アイテム　すもも
	HORN,				//アイテム　つの
	GOLD_BULLION,		//アイテム　金の延べ棒
	SILVER_BULLION,	//アイテム　銀の延べ棒
	CLUB,				//アイテム　棍棒
};
//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjMap1.h"
#include "ObjMap2.h"
#include "ObjMap3.h"
#include "ObjMap4.h"
#include "ObjMap5.h"
#include "ObjBoss.h"
#include "ObjHero.h"
#include"ObjPeach.h"
#include "ObjYellowPeach.h"
#include "ObjPlum.h"
#include "ObjHorn.h"
#include"ObjDog.h"
#include"ObjMonke.h"
#include"ObjPheasant.h"
#include"CObjSword.h"
#include"CObjFlyKiji.h"
#include"ObjEnemy.h"
#include"ObjEnemy2.h"
#include"ObjTitle.h"
#include"ObjInventory.h"
#include"ObjGameOver.h"
#include"ObjClear.h"
#include"ObjTalk.h"
#include"CObjEveDog.h"
#include"CObjEveKiji.h"
#include"CObjEveMnky.h"
#include"CObjhomingfire.h"
#include"CObjSummary.h"
#include"ObjHeroGauge.h"
#include"ObjCapture.h"
#include"ObjClub.h"
#include"Objstair.h"
#include"ObjCharView.h"
#include"ObjPose.h"
#include"ObjOD.h"
#include"ObjScore.h"
#include"ObjItemsetsumei.h"
#include"CObjText.h"
#include"ObjSell.h"
#include"ObjGoldBullion.h"
#include"ObjSilverBullion.h"
#include"CObjText3.h"
#include"CObjText4.h"
#include"CObjText5.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------

#include "Scenefloor1.h"
#include "Scenefloor2.h"
#include "Scenefloor3.h"
#include "Scenefloor4.h"
#include "Scenefloor5.h"


#include "SceneTitle.h"
#include"SceneGameOver.h"
#include"ScecneClear.h"
#include"SceneSummary.h"
#include"SceneOD.h"
#include"SceneScore.h"
#include"SceneItemsetsumei.h"
#include"SceneSell.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
//#define SET_GAME_START  CScenefloor5
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------