#pragma once

class SceneGame
{
public:
	//	コンストラクタ
	SceneGame()
	{
		m_state = GAMESCENE_INIT;
		m_hndl = -1;
		PRet = 0;
	}
	
	
	//	ゲーム全体の管理（計算処理用）
	int Update();

	//	ゲーム全体の管理（描画処理用）
	void Draw();



private:
	enum tagGameScene
	{
		GAMESCENE_INIT,
		GAMESCENE_LOAD,
		GAMESCENE_START,
		GAMESCENE_MAIN,
		GAMESCENE_ENDWAIT,
		GAMESCENE_END,


		GAMESCENE_NUM,
	};

	tagGameScene m_state;

	int PRet;

	int m_hndl;

};

