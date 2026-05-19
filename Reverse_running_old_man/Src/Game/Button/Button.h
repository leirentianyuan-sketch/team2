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
private:

	int m_hndl;

	VECTOR m_pos;

	float halfX = 128.0f / 2;


};