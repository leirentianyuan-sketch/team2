#pragma once
#include <string>
#include<dxlib.h>
#include "../Mouse.h"
#include "../../../common.h"
#include "../../../Lib/Input/CInput.h"

using namespace std;

enum class MOUSE_TYPE
{
	AIANHAND,
	CANDY,
	FIRE,
	FROZEN,
	ICE,
	KUMA,
	SANDAR,
	SPIAKI,
	SWORD,

	NUM,

};

//マウスの画像ハンドルパス
static const string Mouse_Pass[static_cast<int>(MOUSE_TYPE::NUM)] =
{
	"Data/Images/Game/Mouse/aianhnd.png",//アイアンハンド
	"Data/Images/Game/Mouse/candy.png",//キャンディ
	"Data/Images/Game/Mouse/fire.png",//ファイヤー
	"Data/Images/Game/Mouse/frozen.png",//フローズン
	"Data/Images/Game/Mouse/ice.png",//アイス
	"Data/Images/Game/Mouse/kuma.png",//くま
	"Data/Images/Game/Mouse/sandar.png",//サンダー
	"Data/Images/Game/Mouse/speaki.jpg",//すぴき
	"Data/Images/Game/Mouse/sword.png",//ソード
};

class C_Circle
{
private:

	int m_hndl[static_cast<int>(MOUSE_TYPE::NUM)];
	 
	VECTOR m_pos;

	MOUSE_TYPE m_state;

	Mouse m_mouse;

	
	
public:

	void Init()
	{
		m_pos = VEC_ZERO;
		for (int i = 0; i < static_cast<int>(MOUSE_TYPE::NUM); i++)
		{
			m_hndl[i] = -1;
		}

		m_state = MOUSE_TYPE::NUM;
		
		
	}

	void Load()
	{
		for (int i = 0; i < static_cast<int>(MOUSE_TYPE::NUM); i++)
		{
			m_hndl[i] = LoadGraph(Mouse_Pass[i].c_str());
		}
	}

	void Exit()
	{
		for (int i = 0; i < static_cast<int>(MOUSE_TYPE::NUM); i++)
		{
			DeleteGraph(m_hndl[i]);
		}
	}

	void Step()
	{
		m_mouse.SetPos(m_pos);

		if (KEYINPUT::IsPushTrg(KEY_RIGHT))
		{
			m_state = static_cast<MOUSE_TYPE>(static_cast<int>(m_state) + 1);
		}
		if (KEYINPUT::IsPushTrg(KEY_LEFT))
		{
			m_state = static_cast<MOUSE_TYPE>(static_cast<int>(m_state) - 1);
		}


		int x, y;
		GetMousePoint(&x, &y);
		DrawRotaGraph(x, y, 1.0f, 0.0f, m_hndl[static_cast<int>(m_state)], TRUE);
		
		if (static_cast<int>(m_state) <= 0 || static_cast<int>(m_state) >= 9)
		{
			SetMouseDispFlag(TRUE);				// マウスカーソル表示
		}
		else
		{
			SetMouseDispFlag(FALSE);				// マウスカーソル表示
		}
	}



};

