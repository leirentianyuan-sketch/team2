#pragma once
#include "DxLib.h"
#include "../../HitCheck/CHitCheck.h"

class PL_DATA {
private:
	//速さ
	float m_speed;
	//絵
	int m_hndl;
	float m_size;
	//ジャンプのON・OFF
	int m_jump;
	//画像座標
	VECTOR pos;
	
	
public:
	void Init();	
	void Load();
	void Draw();
	void Step();
	void Exit();
	int GetJump(int j) { m_jump; }
	void jumpAC();

	bool m_isActive;

	friend class CHitCheck;
};