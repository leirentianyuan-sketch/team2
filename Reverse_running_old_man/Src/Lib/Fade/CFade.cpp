#include "DxLib.h"
#include "../../common.h"
#include "CFade.h"

using namespace WINDOW;

#define FADE_SPEED (30)


tagFade Fade::m_state;
int Fade::m_Cnt;

//	フェード初期化
void Fade::Init()
{
	m_state = FADE_NON;
	m_Cnt = 0;
}

//	フェード更新
void Fade::Update()
{
	switch (m_state)
	{
		//	ゲーム画面が出る
	case FADE_IN:
		m_Cnt -= FADE_SPEED;
		if (m_Cnt <= 0)
		{
			m_Cnt = 0;
			m_state = FADE_NON;
		}
		break;
		//	黒い画面を出す
	case FADE_OUT:
		m_Cnt += FADE_SPEED;
		if (m_Cnt >= 255)
		{
			m_Cnt = 255;
			m_state = FADE_OUT_WAIT;
		}
		break;
	}
}

//	フェード描画
void Fade::Draw()
{
	//	FADEの時だけは何も表示しなくてよい
	switch (m_state)
	{
	case FADE_IN:
	case FADE_OUT:
	case FADE_OUT_WAIT:
		//	ここでアルファ値をセットする
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_Cnt);

		//	フェード用の黒い四角を表示
		DrawBox(0, 0, (int)MAX_X, (int)MAX_Y, GetColor(0, 0, 0), TRUE);

		//	ほかに影響を及ぼさないようにアルファ値を無効化
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		break;
	}
}

//	フェードインリクエスト
void Fade::RequestFadeIn()
{
	//	状態設定と画面を見えなくするための設定
	m_state = FADE_IN;
	m_Cnt = 255;
}

//	フェードアウトリクエスト
void Fade::RequestFadeOut()
{
	//	状態設定と画面を見えるようにするための設定
	m_state = FADE_OUT;
	m_Cnt = 0;
}

//	フェードインが終了したか？
bool Fade::IsEndFadeIn()
{
	//	フェードイン状態は終了と判断
	return (m_state != FADE_IN);
}

//	フェードアウトが終了したか？
bool Fade::IsEndFadeOut()
{
	//	フェードアウト状態以外は終了と判断
	return (m_state != FADE_OUT);
}