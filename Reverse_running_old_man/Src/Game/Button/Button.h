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

};