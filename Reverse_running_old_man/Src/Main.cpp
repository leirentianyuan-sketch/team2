#include <DxLib.h>						//	DxLibを使用するために必要
#include "Lib/Frame/CFrame.h"			//	FPS制御
#include "Lib/Fade/CFade.h"				//	フェード制御
#include "Lib/Input/CInput.h"			//	キー入力制御
#include "Game/Scene/CSceneManager.h"	//	シーンマネージャー
#include "common.h"						//	様々な定義が入っているヘッダー

#ifdef DEBUG
#pragma message("=====================================================================")
#pragma message("[WARNING]DEBUGが定義されています。Release時には定義しないでください。")
#pragma message("=====================================================================")
#endif // DEBUG


using namespace WINDOW;

//	クラスの宣言
SCENEMANAGER Scene;


//	main関数の代わり
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	ChangeWindowMode(true);		//　ウィンドウモードにするか

	SetGraphMode((int)MAX_X,(int)MAX_Y,16);	//	ウィンドウのサイズ

	SetAlwaysRunFlag(TRUE);

	//	DXライブラリ初期化、必須、基本これより後でDxLib関数を使う
	if (DxLib_Init() == -1)
	{
		MessageBox(nullptr, "DxLib_Init 失敗", "Error", MB_OK);
		return -1;	//	エラーが起きたら直ちに終了
	}

	//	マウスカーソルを表示するかの関数
	SetMouseDispFlag(TRUE);				

	//	画面のちらつきをなくす
	SetDrawScreen(DX_SCREEN_BACK);		

	//	最初に一度呼び出す必要がある関数
	FPS::Init();
	Fade::Init();



	//　ゲームメインループ
	while (ProcessMessage() != -1)// 問題が発生したら終了
	{
		//　「escキー」が押されたらゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;

		WaitTimer(1);

		if (FPS::IsNextFrame() == false)continue;

		//	描画した画像をすべて消す
		ClearDrawScreen();

		//	更新処理
		KEYINPUT::Update();

		//	ここの戻り値が0以外なら終了する流れ
		if (Scene.Step() != 0)break;

#ifdef DEBUG
		int mX = 0;
		int mY = 0;
		GetMousePoint(&mX, &mY);
#endif // DEBUG


		Fade::Update();
		FPS::Step();

		//	描画処理
		Scene.Draw();
		Fade::Draw();	//	フェードを表示


		//	FPSを表示
		FPS::Draw();	
#ifdef DEBUG
		DrawFormatString(100, 80,WHITE,"X:%d,Y:%d",mX,mY);
#endif // DEBUG

		
		//	作成した画面をモニターへ転送
		ScreenFlip();
	}

	DxLib_End();	//	DxLib使用終了時に呼ぶ　必須

	return 0;
}