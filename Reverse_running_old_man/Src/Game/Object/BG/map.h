#pragma once
#include <DxLib.h>

class Stage
{
public:
	Stage()
	{
		Init();
	}
	~Stage()
	{
	}
public:
	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void SetSpeed(int speed);

	int GetSpeed();

private:

	VECTOR m_Pos[2];

	int m_hndl;
	int m_Meter;
	int m_speed;

};

