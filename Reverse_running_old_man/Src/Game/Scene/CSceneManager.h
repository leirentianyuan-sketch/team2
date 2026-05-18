#pragma once

class SCENEMANAGER
{
public:
	SCENEMANAGER()
	{
		m_state = SCENE_TITLE;
	}
	~SCENEMANAGER()
	{

	}
	//	シーン全体の管理（計算処理用）
	int Step();
	//	シーン全体の管理（描画処理用）
	void Draw();


private:

	enum tagScene
	{
		SCENE_TITLE,
		SCENE_GAME,
		SCENE_RESULT,

		SCENE_NUM
	};

	//	ゲームの状態遷移管理
	tagScene m_state;


};

