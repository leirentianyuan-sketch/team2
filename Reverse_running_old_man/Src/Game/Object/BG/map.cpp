#include <DxLib.h>
#include "map.h"
#include "../../../common.h"

const float HNDL_SIZE = 1.0f;

const float Hndl_SizeY = 1170.0f;

const float Hndl_halfY = Hndl_SizeY * 0.5f;

const float	SPEED = (8.0f);


void Stage::Init()
{
	m_Pos[0] = {WINDOW::CENTER_X - 4.5f,WINDOW::CENTER_Y,0.0f };
	/*m_Pos[1] = {WINDOW::CENTER_X - 4.5f,WINDOW::CENTER_Y - 100.0f,0.0f};*/
	m_hndl = -1;
	m_speed = 0;
	m_Meter = 0;
}

void Stage::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("Data/Images/Game/kari/Road.png");
	}
}

void Stage::Step()
{
	if (m_Meter >= 70)
	{
		m_Meter = 70;
	}
	m_speed = (int)(SPEED + (float)m_Meter * 0.1f);
	m_Pos[0].y += m_speed;



	if (m_Pos[0].y >= WINDOW::MAX_Y+WINDOW::CENTER_Y)
	{
		m_Pos[0] = { WINDOW::CENTER_X - 4.5f,WINDOW::CENTER_Y,0.0f };
	}
	//if (m_Pos[1].y >= WINDOW::MAX_Y + WINDOW::CENTER_Y)
	//{
	//	m_Pos[1] = { WINDOW::CENTER_X - 4.5f,WINDOW::CENTER_Y,0.0f };
	//}

}

void Stage::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}

void Stage::Draw()
{
	DrawRotaGraphF(m_Pos[0].x, m_Pos[0].y, HNDL_SIZE, 0.0f, m_hndl, TRUE);
	DrawRotaGraphF(m_Pos[0].x, m_Pos[0].y - WINDOW::MAX_Y, HNDL_SIZE, 0.0f, m_hndl, TRUE);
#ifdef DEBUG
	DrawFormatString(100, 140, BLACK, "%dkm/h", m_Meter + 50);
#endif // DEBUG

	
}

void Stage::SetSpeed(int speed)
{
	m_Meter = speed;
}

int Stage::GetSpeed()
{
	return m_speed;
}