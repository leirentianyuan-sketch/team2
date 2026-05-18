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

private:

	int m_hndl;

	VECTOR m_pos;

	const float halfX = 128.0f / 2;

	const float halfY = 128.0f / 2;

	//CIRCLE l;

};