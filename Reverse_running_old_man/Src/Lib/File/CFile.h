#pragma once
#include "DxLib.h"


class CFile
{
public:
	CFile()
	{
		Init();
	}
	void Init();

	void Load(int& num);

	void Write(int num);

private:
	FILE* fp;
	int m_Score;

};

