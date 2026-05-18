#pragma once
#include <DxLib.h>
#include "../../Lib/Mouse_Operation/Mouse_Operation.h"

class Mouse
{
public:

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

private:

	int clickNum;

	VECTOR m_pos;

	int m_hndl;

	VECTOR m_hndlPos;

	const float halfX = 128.0f / 2;

	Mouse_Operation mouse;

	CIRCLE l;
};