//**************************************************
//
//�T�E���h
//Author::Takano Minto
//
//**************************************************
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//==================================================
// �T�E���h�t�@�C��
//==================================================
typedef enum
{
	SOUND_LABEL_GAME = 0,				// BGM
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//==================================================
// �v���g�^�C�v�錾
//==================================================
HRESULT InitSound(HWND hWnd);
void UninitSound(void);
HRESULT PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound();

#endif
