#include "Button.h"
#include "../Mouse/Mouse.h"
#include "../../common.h"
#include "../../Lib/Collision/CCollision.h"
#include "../../Lib/Mouse_Operation/Mouse_Operation.h"

static const char hndl_Pas[] = { "Data/Images/Game/botan/don.webp" };

void Button::Init()
{
	m_hndl = -1;
	m_pos = WINDOW::CENTER;
}

void Button::Load()
{
	if (m_hndl = -1)
	{
		m_hndl = LoadGraph(hndl_Pas);
	}
}

void Button::Step()
{
	
}

void Button::Draw()
{
	DrawRotaGraphF(m_pos.x, m_pos.y, 1.0f, 0.0f, m_hndl, TRUE);
}

void Button::Exit()
{
	
}