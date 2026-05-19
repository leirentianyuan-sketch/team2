#include "Button.h"
#include "../Mouse/Mouse.h"
#include "../../common.h"
#include "../../Lib/Collision/CCollision.h"
#include "../../Lib/Mouse_Operation/Mouse_Operation.h"

static const char hndl_Pas[] = { "Data/Images/Game/botan/don.webp" };

static const char window_Pas[][128] = 
{ "Data/Images/Game/window/spiki_window.png", 
  "Data/Images/Game/window/sward.png" };

void Button::Init()
{
	m_hndl = -1;
	m_pos = WINDOW::CENTER;

	for (int i = 0; i < Hndl_Num; i++)
	{
		m_windowHndl[i] = -1;
		m_windowPos[i] = VEC_ZERO;
	}
}

void Button::Load()
{
	if (m_hndl = -1)
	{
		m_hndl = LoadGraph(hndl_Pas);
	}

	for (int i = 0; i < Hndl_Num; i++)
	{
		m_windowHndl[i] = LoadGraph(window_Pas[i]);
		m_windowPos[i] = basePos[i];
	}
}

void Button::Step()
{
	
}

void Button::Draw()
{
	DrawRotaGraphF(m_pos.x, m_pos.y, 1.0f, 0.0f, m_hndl, TRUE);

	for (int i = 0; i < Hndl_Num; i++)
	{
		DrawRotaGraphF(m_windowPos[i].x, m_windowPos[i].y, size[i], 0.0f, m_windowHndl[i], TRUE);
	}
}

void Button::Exit()
{
	
}