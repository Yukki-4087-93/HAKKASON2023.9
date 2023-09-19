//**************************************************
//
//�Q�[�����
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
//�O���[�o���ϐ�
//==================================================
bool g_bPause = false;

//==================================================
//������
//==================================================
void InitGame()
{
	InitBG();					//�w�i�̏�����
	InitPause();				//�|�[�Y�̏�����
	InitEffect();
	g_bPause = false;
	//PlaySound(SOUND_LABEL_BATTLEMEETING_VER_2);
}

//==================================================
//�I��
//==================================================
void UninitGame()
{
	//StopSound();
	UninitBG();				//�I������(�w�i)
	UninitEffect();
	UninitPause();
}

//==================================================
//�X�V
//==================================================
void UpdateGame()
{
#ifdef _DEBUG
	if (GetkeyboardTrigger(DIK_RETURN))
	{//P�L�[�Ƃ��̑�������낪�����ꂽ
		SetFade(MODE_RESULT);
	}
#endif // _DEBUG

	if (GetkeyboardTrigger(DIK_P) || 
		GetJoypadTrigger(JOYKEY_STRTE) || 
		GetJoypadTrigger(JOYKEY_BACK))
	{//P�L�[�Ƃ��̑�������낪�����ꂽ
		g_bPause = g_bPause ? false : true;
	}

	if (!g_bPause)
	{
		UpdateBG();					//BackGround�̍X�V����
		UpdateEffect();
	}
	else
	{
		UpdatePause();
	}
}

//==================================================
//�`��
//==================================================
void DrawGame()
{
	DrawBG();					//�w�i�̕`�揈��
	DrawEffect();
	if (g_bPause == true)
	{//�|�[�Y�Ȃ�
		DrawPause();
	}
}

//==================================================
//�|�[�Y�̐ݒ�
//==================================================
void SetEnablePause(bool bPause)
{
	g_bPause = bPause;
}