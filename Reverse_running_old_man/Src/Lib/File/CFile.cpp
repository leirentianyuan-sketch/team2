#include "../../common.h"
#include "CFile.h"

void CFile::Init()
{
	m_Score = 0;
	fopen_s(&fp, "Data/Saves/deta.txt", "r");
	if (!(fp == nullptr))
	{
		fscanf_s(fp, "HiScore : %d", &m_Score);
	}
	else
	{
		//	ì«Ç›çûÇ›é∏îs
		m_Score = 0;
	}
	if (fp != nullptr)
	{
		fclose(fp);
	}
	
}

void CFile::Load(int& num)
{
	num = m_Score;
	
}

void CFile::Write(int num)
{
	if (num < m_Score)
	{
		return;
	}
	else
	{
		m_Score = num;
	}

	fopen_s(&fp, "Data/Saves/deta.txt", "w");
	if (!(fp == nullptr))
	{
		fprintf_s(fp, "HiScore : %d", m_Score);
	}

	if (fp != nullptr)
	{
		fclose(fp);
	}
}