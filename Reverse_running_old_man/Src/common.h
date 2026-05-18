#pragma once
#include "DxLib.h"


//	デバッグモード
//	リリース時には定義を消すまたは、定義をしないでください。
#define DEBUG
#undef DEBUG

//	★フレームレートを変更したい場合は "CFrame.h"　で変更してください。

//	ベクター初期化用
static const VECTOR VEC_ZERO = { 0.0f,0.0f,0.0f };

//	ウィンドウ系のネームスペース
namespace WINDOW
{
	constexpr auto MAX_X = 1280.0f;	//	ウィンドウのサイズ（横）
	constexpr auto MAX_Y = 720.0f;	//	ウィンドウのサイズ（縦）

	constexpr auto CENTER_X = (MAX_X * 0.5f);	//	ウィンドウのXの真ん中
	constexpr auto CENTER_Y = (MAX_Y * 0.5f);	//	ウィンドウのYの真ん中

	constexpr VECTOR CENTER = { CENTER_X,CENTER_Y,0.0f };	//	ウィンドウの中心

}

//	色のネームスペース
namespace COLOR
{
	const int BLACK = GetColor(0, 0, 0);		//	黒
	const int WHITE = GetColor(255, 255, 255);	//	白
	const int RED = GetColor(255, 0, 0);		//	赤
	const int GREEN = GetColor(0, 255, 0);		//	緑
	const int BLUE = GetColor(0, 0, 255);		//	青
}

//const int TitleScreen = MakeScreen(1600, 900,TRUE);
//const int GameScreen = MakeScreen(700, 900,TRUE);


