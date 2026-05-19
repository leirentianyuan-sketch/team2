#include "Mouse.h"
#include "../Button/Button.h"
#include "../../common.h"
#include "../../Lib/Input/CInput.h"
#include "../../Lib/Mouse_Operation/Mouse_Operation.h"





void Mouse::Init()
{
	clickNum = 0;
	m_pos = VEC_ZERO;


	pos = WINDOW::CENTER;
	half = 128.0f / 2;

	for (int i = 0; i < 2; i++)
	{
		windowPos[i] = VEC_ZERO;
		halfX[i] = 0.0f;
		halfY[i] = 0.0f;
	}

	flag = false;
}



void Mouse::Step()
{
	m_botan.SetCircle(pos, half);
	m_hitcircle = { pos, half };
	
	for (int i = 0; i < 2; i++)
	{
		m_botan.SetWindow(windowPos[i], halfX[i], halfY[i]);
		m_hitWindow[i] = {windowPos[i], halfX[i], halfY[i]};
	}
	
	m_pos = mouse.Get_pos();
	mouse.Step();
	if (KEYINPUT::IsPushTrg(KEY_LCLICK) == true &&
		mouse.IsHitButton(m_pos, m_hitcircle) == true)
	{
		clickNum++;
	}

	for (int i = 0; i < 2; i++)
	{
		if (KEYINPUT::IsPushTrg(KEY_LCLICK) == true &&
			mouse.IsHitWindow(m_pos, m_hitWindow[i]) == true)
		{
			flag = true;
			//DrawExtendFormatStringF(0.0f, 0.0f, 10.0f, 10.0f, COLOR::RED, "ƒqƒbƒg");
		}
	}
}

void Mouse::Draw()
{
	DrawExtendFormatStringF(600.0f, 500.0f, 10.0f, 10.0f, COLOR::GREEN, "%d‰ñ", clickNum);

	if (flag == true)
	{
		DrawExtendFormatStringF(0.0f, 0.0f, 10.0f, 10.0f, COLOR::RED, "ƒqƒbƒg");
	}
}

void Mouse::SetPos(VECTOR pos)
{
	pos = m_pos;
}



