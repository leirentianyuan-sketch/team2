#pragma once
#include "DxLib.h"


//	フェード一連の流れ
//	FADE_NON -> FADE_OUT -> FADE_OUT_WAIT の順で画面が消え、
//	FADE_OUT_WAIT -> FADE_IN -> FADE_NON の順で画面が消える
enum tagFade
{
	FADE_NON,
	FADE_IN,
	FADE_OUT,
	FADE_OUT_WAIT
};

//	Fadeクラス
class Fade
{
private:
	static tagFade m_state;			//	フェード状態
	static int m_Cnt;				//	フェード時間のカウント

public:
	static void Init();				//	フェード初期化
	static void Update();			//	フェード更新

	static void Draw();				//	フェード描画

	static void RequestFadeIn();	//	フェードインリクエスト
	static void RequestFadeOut();	//	フェードアウトリクエスト

	static bool IsEndFadeIn();		//	フェードインが終了したか？
	static bool IsEndFadeOut();		//	フェードアウトが終了したか？

};

