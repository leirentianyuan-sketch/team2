#pragma once
#include <DxLib.h>

class Button
{


public:

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void SetCircle(VECTOR pos, float halfx)
	{
		pos = m_pos;
		halfx = halfX;
	}

	void SetWindow(VECTOR pos, float halfx, float halfy)
	{
		for (int i = 0; i < Hndl_Num; i++)
		{
			pos = basePos[i];
			halfx = windoHhalfX[i];
			halfy = windoHhalfY[i];
		}
	}

private:

	enum WindowHndl
	{
		Hndl_1,
		Hndl_2,

		Hndl_Num
	};

	int m_hndl;

	int m_windowHndl[Hndl_Num];

	VECTOR m_pos;

	VECTOR m_windowPos[Hndl_Num];

	float halfX = 128.0f / 2;

	const VECTOR basePos[Hndl_Num] =
	{
		{1000.0f, 100.0f, 0.0f},		// スピキ
		{1000.0f, 230.0f, 0.0f},		// 剣
	};

	const float size[Hndl_Num] =
	{
		{0.5f},		// スピキ
		{0.675f},		// 剣
	};

	const float windoHhalfX[Hndl_Num] =
	{
		{1000.0f * size[0]/ 2},		// スピキ
		{1000.0f * size[1]/ 2},	// 剣
	};

	const float windoHhalfY[Hndl_Num] =
	{
		{252.0f * size[0] / 2},		// スピキ
		{563.0f * size[1] / 2},	// 剣
	};

};