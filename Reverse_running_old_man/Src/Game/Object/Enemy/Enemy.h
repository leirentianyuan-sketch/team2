#pragma once
#include "DxLib.h"
#include "../../HitCheck/CHitCheck.h"

class Enemy
{
public:
	Enemy()
	{
		Init();
	}

	~Enemy()
	{

	}
public:

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void SetSpeed(int speed);

private:

enum tagEnemyHndl
	{
		EHndl_1,
		EHndl_2,
		EHndl_3,
		EHndl_4,

		EHndl_NUM
	};
	VECTOR m_pos[EHndl_NUM];

	int m_hndl[EHndl_NUM];

	bool m_isActive[EHndl_NUM];

	int m_waitCnt[EHndl_NUM];

	int m_speed;

	bool FirstFrag;
	friend class CHitCheck;

};
