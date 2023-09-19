//**************************************************
//
//�G�t�F�N�g
//Author::Takano Minto
//
//**************************************************
#ifndef _EFFECT_H_
#define _EFFECT_H_

#include"main.h"

//==================================================
//�G�t�F�N�g�̍\���̒�`
//==================================================
typedef struct
{
	D3DXVECTOR3 pos;						//�ʒu
	D3DXVECTOR3 move;						//�ړ���
	D3DXCOLOR col;							//�F����
	float fRadius;							//���a
	int nCounterAnim;						//�A�j���[�V�����J�E���^�[
	int nPatternAnim;						//�A�j���[�V�����p�^�[��
	int nLife;								//���C�t
	bool bUse;								//�e�g�p�����ۂ�
}EFFECT;

//==================================================
//�v���g�^�C�v�錾
//==================================================
void InitEffect();
void UninitEffect();
void UpdateEffect();
void DrawEffect();
void SetEffect(D3DXVECTOR3 pos, D3DXCOLOR col,float fRadius,int nLife);
EFFECT *GetEffect();

#endif // !_EFFECT_H_


