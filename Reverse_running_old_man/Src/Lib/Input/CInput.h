#pragma once

//	----------使用するビットに割り当てる----------
#define KEY_LCLICK		(0b1)		//	左クリック
#define KEY_RCLICK		(0b10)		//	右クリック
#define KEY_HCLICK		(0b100)		//	マウスホイールクリック
//#define KEY_UPWHEEL		(0b1000)	//	マウスホイールアップ
//#define KEY_DOWNWHEEL	(0b10000)	//	マウスホイールダウン
//#define KEY_MOUSE_B01	(0b100000)	//	マウスボタン１
//#define KEY_MOUSE_B02	(0b1000000)	//	マウスボタン２
//
#define KEY_SPACE		(0b10000000)//	スペース

#define KEY_RIGHT	(0b1)		//	矢印　右
#define KEY_LEFT	(0b10)		//	矢印　左

class KEYINPUT
{
public:
	//	キー入力更新
	static void Update();

	//	キー入力判定（通常判定）
	static bool IsPush(const unsigned int key);
	//	キー入力判定（トリガー判定）
	static bool IsPushTrg(const unsigned int key);

private:
	static unsigned int m_nowkey;	//	今回入力したキー情報
	static unsigned int m_prevkey;	//	前回入力したキー情報

};

