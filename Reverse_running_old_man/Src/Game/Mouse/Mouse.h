#pragma once
#include <DxLib.h>
#include "../../Lib/Mouse_Operation/Mouse_Operation.h"
#include "../Button/Button.h"



class Mouse
{
public:

	void Init();

	void Step();

	void Draw();

	

	void SetPos(VECTOR pos);
	VECTOR GetPos();
	

private:
	int flag;
	

	int clickNum;

	VECTOR m_pos;

	int m_hndl;

	VECTOR m_hndlPos;



	Button m_botan;
	Mouse_Operation mouse;

	CIRCLE m_hitcircle;
	BOX m_hitWindow[2];

	VECTOR pos;

	float half;

	VECTOR  windowPos[2];
	float halfX[2];
	float halfY[2];
};