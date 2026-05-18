#pragma once

class CUI
{
public:
	CUI()
	{
		Init();

	}
	~CUI()
	{

	}

	void Init();

	void Load();

	void Update();

	void Draw();

	void Exit();

	//	ƒ[ƒgƒ‹‚ğ“n‚·
	int GetMeter();

private:
	int Cnt;
	/*
	int Time;

	int milliseconds;

	int seconds;

	int min;
	*/

	static int m_Meter;
	static int m_HiScore;


};
