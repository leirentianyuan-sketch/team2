#include "CSceneGame.h"
#include "../../../common.h"
#include "../../../Lib/Fade/CFade.h"
#include "../../../Lib/Input/CInput.h"

// í«â¡ÇÃinclude==============
#include "../../Mouse/Mouse.h"
#include "../../Button/Button.h"


const char kari[] = { "Data/Images/Title/Title_Road.png" };

Mouse mouse;
//Button button;

int SceneGame::Update()
{
	int ret = 0;

	switch (m_state)
	{
	case SceneGame::GAMESCENE_INIT:
		
		mouse.Init();
		/*button.Init();*/

		m_hndl = -1;

		m_state = GAMESCENE_LOAD;
		break;
	case SceneGame::GAMESCENE_LOAD:

	/*	button.Load();*/
		mouse.Load();
		
		if (m_hndl == -1)
		{
			m_hndl = LoadGraph(kari);
		}
		
		Fade::RequestFadeIn();

		m_state = GAMESCENE_START;
		break;
	case SceneGame::GAMESCENE_START:
		
		if (Fade::IsEndFadeIn())
		{
			m_state = GAMESCENE_MAIN;
		}

		break;
	case SceneGame::GAMESCENE_MAIN:

		mouse.Step();
		/*button.Step();*/

		if (KEYINPUT::IsPushTrg(KEY_SPACE))
		{
			Fade::RequestFadeOut();
			m_state = GAMESCENE_ENDWAIT;
		}

#ifdef DEBUG
		if (KEYINPUT::IsPush(KEY_SPACE))//	Å¶ÉäÉUÉãÉgÇ…êiÇﬁèåè
		{
			Fade::RequestFadeOut();
			m_state = GAMESCENE_ENDWAIT;
			PRet = 2;
		}
#endif // DEBUG
	break;
	case SceneGame::GAMESCENE_ENDWAIT:
		
		if (Fade::IsEndFadeOut())
		{
			m_state = GAMESCENE_END;
		}

		break;
	case SceneGame::GAMESCENE_END:

		if (m_hndl != -1)
		{
			DeleteGraph(m_hndl);
			m_hndl = -1;
		}

		/*button.Exit();*/

		m_state = GAMESCENE_INIT;
		
		ret = 1;
		break;
	}
	return ret;
}

void SceneGame::Draw()
{
	switch (m_state)
	{
	case SceneGame::GAMESCENE_START:
	case SceneGame::GAMESCENE_MAIN:
	case SceneGame::GAMESCENE_ENDWAIT:
		
		//DrawRotaGraph(0.0f, 0.0f, 1.0f, 0.0f, m_hndl, TRUE);	âºÇÃâÊëú
		mouse.Draw();
		/*button.Draw();*/

		break;
	}
}