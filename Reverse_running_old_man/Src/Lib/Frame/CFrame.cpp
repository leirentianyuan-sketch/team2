#include <DxLib.h>
#include "CFrame.h"


double FPS::m_drawFps;
int FPS::m_nowTime;
int FPS::m_prevTime;
int FPS::m_prevDrawTime;
int FPS::m_count;


void FPS::Init()
{
	m_drawFps = 0.0;
	m_nowTime = 0;
	//	いったんPC時間を保存しておく
	m_prevTime = m_prevDrawTime = GetNowCount();
	m_count = 0;
}

bool FPS::IsNextFrame()
{
	//	最新の時間を取得し更新
	m_nowTime = GetNowCount();
	//	前回の時間から今回までの差分を取得
	int difTime = m_nowTime - m_prevTime;

	if (difTime >= FRAME_RATE_MILLI_SECOND)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void FPS::Step()
{
	//	ここまで来たら時間を更新
	m_prevTime = m_nowTime;

	//	想定通りなら1フレーム進んだはず
	m_count++;
	//	前回更新した時の時間と今回の時間の差を取得
	int difTime = m_nowTime - m_prevDrawTime;

	//	1秒以上経過したら計算開始
	if (difTime >= 1000)
	{
		//	想定通りなら1000ミリ秒経てばm_countはFRAME_RATEになっているはず
		float frameCnt = (float)(m_count * 1000);
		//	上記数字 / 経過時間で想定のFPSになる
		m_drawFps = frameCnt / difTime;
		//	カウントは0に戻す
		m_count = 0;
		//	現在時間と1秒前の時間を更新
		m_prevDrawTime = m_nowTime;
	}
}

void FPS::Draw()
{	
	//	FPSは常に表示を続ける
	DrawFormatString(2, 2, GetColor(255, 255, 255), "FPS: %.1lf", m_drawFps);
}