#include "Mouse.h"
#include "../Button/Button.h"
#include "../../common.h"
#include "../../Lib/Input/CInput.h"
#include "../../Lib/Mouse_Operation/Mouse_Operation.h"

static const char hndl_Pas[] = { "Data/Images/Game/don.webp" };

void Mouse::Init()
{
	clickNum = 0;
	m_pos = VEC_ZERO;

	m_hndl = -1;
	m_hndlPos = WINDOW::CENTER;//{ 200.0f, 200.0f, 0.0f };
}

void Mouse::Load()
{
	if (m_hndl = -1)
	{
		m_hndl = LoadGraph(hndl_Pas);
	}
}

void Mouse::Step()
{
	l = { m_hndlPos, halfX };
	m_pos = mouse.Get_pos();
	mouse.Step();
	if (KEYINPUT::IsPushTrg(KEY_LCLICK) == true &&
		mouse.IsHitButton(m_pos, l) == true)
	{
		clickNum++;
	}
}

void Mouse::Draw()
{
	DrawExtendFormatStringF(600.0f, 500.0f, 10.0f, 10.0f, COLOR::GREEN, "%d‰ñ", clickNum);

	DrawRotaGraphF(m_hndlPos.x, m_hndlPos.y, 1.0f, 0.0f, m_hndl, TRUE);
}

void Mouse::Exit()
{

}