#pragma once
#include "DxLib.h"
#include "../../../common.h"

const int WaitCNt = 60;

class SceneTitle
{
public:
	//	ゲーム全体の管理（計算処理用）
	int Update();

	//	ゲーム全体の管理（描画処理用）
	void Draw();

private:
	enum tagTitleScene
	{
		TITLE_INIT,		//	初期化
		TITLE_LOAD,		//	データロード
		TITLE_START,	//	ゲーム開始前
		TITLE_MAIN,		//	メイン処理
		TITLE_ENDWAIT,	//	ゲーム終了時の待機
		TITLE_END,		//	終了処理

		TITLE_NUM,
	};

	enum tagTitleHndl
	{
		THndl_1,

		THndl_NUM
	};

	int m_hndl[THndl_NUM];
	VECTOR m_pos;

	tagTitleScene m_state = TITLE_INIT;

};
