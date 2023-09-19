//**************************************************
//
//ゲーム画面
//Author::Takano Minto
//
//**************************************************
#include"input.h"
#include"sound.h"
#include"time.h"
#include"bg.h"
#include"fade.h"
#include"effect.h"
#include"pause.h"

//==================================================
//グローバル変数
//==================================================
bool g_bPause = false;

//==================================================
//初期化
//==================================================
void InitGame()
{
	InitBG();					//背景の初期化
	InitPause();				//ポーズの初期化
	InitEffect();
	g_bPause = false;
	//PlaySound(SOUND_LABEL_BATTLEMEETING_VER_2);
}

//==================================================
//終了
//==================================================
void UninitGame()
{
	//StopSound();
	UninitBG();				//終了処理(背景)
	UninitEffect();
	UninitPause();
}

//==================================================
//更新
//==================================================
void UpdateGame()
{
#ifdef _DEBUG
	if (GetkeyboardTrigger(DIK_RETURN))
	{//Pキーとその他もろもろが押された
		SetFade(MODE_RESULT);
	}
#endif // _DEBUG

	if (GetkeyboardTrigger(DIK_P) || 
		GetJoypadTrigger(JOYKEY_STRTE) || 
		GetJoypadTrigger(JOYKEY_BACK))
	{//Pキーとその他もろもろが押された
		g_bPause = g_bPause ? false : true;
	}

	if (!g_bPause)
	{
		UpdateBG();					//BackGroundの更新処理
		UpdateEffect();
	}
	else
	{
		UpdatePause();
	}
}

//==================================================
//描画
//==================================================
void DrawGame()
{
	DrawBG();					//背景の描画処理
	DrawEffect();
	if (g_bPause == true)
	{//ポーズなう
		DrawPause();
	}
}

//==================================================
//ポーズの設定
//==================================================
void SetEnablePause(bool bPause)
{
	g_bPause = bPause;
}