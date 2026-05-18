#include "CSceneManager.h"
#include "../../common.h"

//	この下に追加のシーンのヘッダーを書く
//	例　：　#include "SCENEGAME.h"
#include "Title/CSceneTitle.h"
#include "Game/CSceneGame.h"
#include "Result/CSceneResult.h"


//	===================================

SceneTitle Title;
SceneGame Game;
SceneResult Result;

int SCENEMANAGER::Step()
{
	int ret = 0;	//	ゲームがすべて終了したか、消すときのみ値が変わる
	int next = 0;	//	次の状態遷移に進むかどうか

	//	状態遷移
	switch (m_state)
	{
		//	タイトル画面
	case SCENEMANAGER::SCENE_TITLE:
		next = Title.Update();
		if (next == 1)
		{
			m_state = SCENE_GAME;
		}
		break;
		//	ゲーム本編
	case SCENEMANAGER::SCENE_GAME:
		next = Game.Update();
		if (next == 1)
		{
			m_state = SCENE_RESULT;
		}
		break;
		//	リザルト画面
	case SCENEMANAGER::SCENE_RESULT:
		next = Result.Update();
		if (next == 1)
		{
			m_state = SCENE_TITLE;
		}
		break;
	
	}
	return ret;

}


void SCENEMANAGER::Draw()
{
	switch (m_state)
	{
		//	タイトル画面
	case SCENEMANAGER::SCENE_TITLE:
		Title.Draw();
		break;
		//	ゲーム本編
	case SCENEMANAGER::SCENE_GAME:
		Game.Draw();
		break;
		//	リザルト画面
	case SCENEMANAGER::SCENE_RESULT:
		Result.Draw();
		break;
	}
}