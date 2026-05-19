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
}



void Mouse::Step()
{

	m_botan.SetCircle(pos, half);

	m_hitcircle = { pos, half };

	m_pos = mouse.Get_pos();
	mouse.Step();
	if (KEYINPUT::IsPushTrg(KEY_LCLICK) == true &&
		mouse.IsHitButton(m_pos, m_hitcircle) == true)
	{
		clickNum++;
	}
}

void Mouse::Draw()
{
	DrawExtendFormatStringF(600.0f, 500.0f, 10.0f, 10.0f, COLOR::GREEN, "%d‰ñ", clickNum);
}

void Mouse::SetPos(VECTOR pos)
{
	pos = m_pos;
}



