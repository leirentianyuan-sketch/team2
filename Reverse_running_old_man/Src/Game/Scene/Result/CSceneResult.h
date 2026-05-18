#pragma once
class SceneResult
{
public:
	
	//	ゲーム全体の管理（計算処理用）
	int Update();

	//	ゲーム全体の管理（描画処理用）
	void Draw();

private:

	enum tagResultScene
	{
		RESULT_INIT,	//	初期化
		RESULT_LOAD,	//	データロード
		RESULT_START,	//	ゲーム開始前
		RESULT_MAIN,	//	メイン処理
		RESULT_ENDWAIT,	//	ゲーム終了時の待機
		RESULT_END,		//	終了処理

		RESULT_NUM,
	};

	//	ハンドルネーム
	enum tagResultHndl
	{
		hndl_1,
		hndl_2,
		
		hndl_NUM
	};

	//	ステート
	tagResultScene m_state;

	int m_hndl[hndl_NUM];

	/*VECTOR m_pos;*/
};

