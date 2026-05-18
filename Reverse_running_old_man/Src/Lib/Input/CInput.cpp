#include "DxLib.h"
#include "CInput.h"

unsigned int KEYINPUT::m_nowkey = 0;
unsigned int KEYINPUT::m_prevkey = 0;

void KEYINPUT::Update()
{
	m_prevkey = m_nowkey;

	m_nowkey = 0;

	int mouse = GetMouseInput();

	//	マウスの入力判定
	if ((mouse & MOUSE_INPUT_LEFT) != 0)
	{
		m_nowkey |= KEY_LCLICK;
	}
	if ((mouse & MOUSE_INPUT_RIGHT) != 0)
	{
		m_nowkey |= KEY_RCLICK;
	}
	if ((mouse & MOUSE_INPUT_MIDDLE) != 0)
	{
		m_nowkey |= KEY_HCLICK;
	}

	// キーボードの入力判定
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_nowkey |= KEY_SPACE;
	}

	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_nowkey |= KEY_LEFT;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_nowkey |= KEY_RIGHT;
	}
}

bool KEYINPUT::IsPush(const unsigned int key)
{
	return (m_nowkey & key) != 0;
}

bool KEYINPUT::IsPushTrg(const unsigned int key)
{
	return (((m_nowkey & key) != 0) && ((m_prevkey & key) == 0));
}