//**************************************************
//
//サウンド
//Author::Takano Minto
//
//**************************************************
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//==================================================
// サウンドファイル
//==================================================
typedef enum
{
	SOUND_LABEL_GAME = 0,				// BGM
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//==================================================
// プロトタイプ宣言
//==================================================
HRESULT InitSound(HWND hWnd);
void UninitSound(void);
HRESULT PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound();

#endif
