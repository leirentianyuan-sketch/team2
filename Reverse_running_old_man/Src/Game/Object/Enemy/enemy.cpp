#include <DxLib.h>
#include "Enemy.h"
#include "../../../Lib/Func/Func.h"
#include "../../../common.h"

const float START_X[4] = { 150, 280, 410, 551 };
const float START_Y[4] = { -20, -120, -220, -320 };

static const char Hndl_Pas[][64] = { "Data/Images/Game/kari/blue_car.png", "Data/Images/Game/kari/red_car.png",
									 "Data/Images/Game/kari/truck.png",  "Data/Images/Game/kari/orange_car.png" };

void Enemy::Init()
{
	for (int i = 0; i < EHndl_NUM; i++)
	{
		m_hndl[i] = -1;
		m_isActive[i] = false;
		m_waitCnt[i] = 0;
	}
	FirstFrag = false;
	
}

void Enemy::Load()
{
	for (int i = 0; i < EHndl_NUM; i++)
	{
		m_hndl[i] = LoadGraph(Hndl_Pas[i]);
	}
}

void Enemy::Step()
{
	for (int i = 0; i < EHndl_NUM; i++)
	{
		//if (m_isActive[i] == false) continue;

		m_pos[i].y += m_speed + 3;

		if (m_pos[i].y > WINDOW::MAX_Y + 50)
		{
			m_isActive[i] = false;
		}

		if (m_waitCnt[i] > 0)
		{
			m_waitCnt[i]--;
		}
		else
		{
			if (m_isActive[i] == true) continue;

			m_isActive[i] = true;
			m_pos[i].y = -1450;
			// 一台目が画面端に到達したときの最後の車（４台目）のY座標から
			// 車間距離分引いた数が初期位置

			m_pos[i].x = START_X[GetRand(3)];

			//m_pos[i].y = START_Y[GetRand(3)];
			//m_waitCnt[i] = 120;
		}
	}
	if (FirstFrag == false)
	{
		m_pos[0].y = 0 - 50;
		m_pos[1].y = -600 - 50;
		m_pos[2].y = -1200 - 50;
		m_pos[3].y = -1800 - 50;

		FirstFrag = true;
		
	}
}

void Enemy::Draw()
{
	for (int i = 0; i < EHndl_NUM; i++)
	{
		if (m_isActive[i] == true)
		{
			DrawRotaGraph((int)m_pos[i].x, (int)m_pos[i].y, 0.25, Func::AngletoRazian(180), m_hndl[i], TRUE);
		}
	}
}

void Enemy::Exit()
{
	for (int i = 0; i < EHndl_NUM; i++)
	{
		DeleteGraph(m_hndl[i]);
		m_hndl[i] = -1;
	}
}

void Enemy::SetSpeed(int speed)
{
	m_speed = speed;
}