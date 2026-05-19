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

	

	int clickNum;

	VECTOR m_pos;

	int m_hndl;

	VECTOR m_hndlPos;

	Button m_botan;

	Mouse_Operation mouse;

	CIRCLE m_hitcircle;

	VECTOR pos ;

	float half;
};