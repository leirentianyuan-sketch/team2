#include "Mouse.h"
#include "../../common.h"
#include "../../Lib/Input/CInput.h"

void Mouse::Init()
{
	clickNum = 0;
	m_pos = VEC_ZERO;
}

void Mouse::Load()
{

}

void Mouse::Step()
{
	m_pos = mouse.Get_pos();
	mouse.Step();
	if (KEYINPUT::IsPushTrg(KEY_LCLICK) == true)
	{
		clickNum++;
	}
}

void Mouse::Draw()
{
	DrawExtendFormatStringF(600.0f, 500.0f, 10.0f, 10.0f, COLOR::GREEN, "%d‰ñ", clickNum);
}

void Mouse::Exit()
{

}