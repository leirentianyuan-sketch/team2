#pragma once

class FPS
{
public:

	static void Init();		//	変数初期化
	static bool IsNextFrame();	//	次のフレームに進めていいか
	static void Step();		//	FPS更新処理
	static void Draw();		//	FPS表示関数

private:

	//	===FPSの限界値=== 
	// ★イコールのあとの値を変更するとFPSが変わります。
	static const int FRAME_RATE = 60;

	//	絶対いじらんほうがいい
	static const int FRAME_RATE_MILLI_SECOND = (1000 / FRAME_RATE);

	static double m_drawFps;	//	実際に表示するFPS
	static int m_nowTime;		//	現在のPC時間
	static int m_prevTime;		//	ひとつ前のPC時間
	static int m_prevDrawTime;	//	
	static int m_count;		//	カウント用


};
