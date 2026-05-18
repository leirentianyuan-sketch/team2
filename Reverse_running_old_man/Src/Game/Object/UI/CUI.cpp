#include "../../../common.h"
#include "CUI.h"
#include "../../../Lib/File/CFile.h"

CFile File;

int CUI::m_Meter;
int CUI::m_HiScore;

void CUI::Init()
{
	/*Cnt = 0;
	Time = 0;
	milliseconds = 0;
	seconds = 0;
	min = 0;*/

	File.Init();

	m_Meter= 0;
	m_HiScore = 0;
	Cnt = 0;
}

void CUI::Load()
{
	File.Load(m_HiScore);
}

void CUI::Update()
{
	Cnt++;
	
	/*if (Cnt > 60)
	{
		Time++;
		Cnt = 0;
	}

	seconds = Time % 60;

	min = Time / 60;*/

	m_Meter = Cnt / 60;
}

void CUI::Draw()
{
 
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "%d:%02d", min,seconds);
	DrawFormatString(100, 100, GetColor(255,0,0), "HiScore : %03dメートル", m_HiScore);
	DrawFormatString(100, 120, GetColor(255, 0, 0), "現在 : %03dメートル", m_Meter);

}

void CUI::Exit()
{
	File.Write(m_Meter);
}

int CUI::GetMeter()
{
	return m_Meter;
}