#include "CSceneTitle.h"
#include "../../../common.h"
#include "../../../Lib/Fade/CFade.h"
#include "../../../Lib/Input/CInput.h"

static const char hndl_Pas[][128] =
{
	"Data/Images/Title/1040494.jpg",
	"Data/Images/Title/Title_Logo.png"
};

int SceneTitle::Update()
{
	int ret = 0;

	switch (m_state)
	{
	case SceneTitle::TITLE_INIT:

		for (int i = 0; i < THndl_NUM; i++)
		{
			m_hndl[i] = -1;
		}

		m_pos = VEC_ZERO;

		m_state = TITLE_LOAD;

		break;

	case SceneTitle::TITLE_LOAD:

		for (int i = 0; i < THndl_NUM; i++)
		{
			m_hndl[i] = LoadGraph(hndl_Pas[i]);
		}

		Fade::RequestFadeIn();

		m_state = TITLE_START;

		break;
	case SceneTitle::TITLE_START:
		
		if (Fade::IsEndFadeIn() == true)
		{
			m_state = TITLE_MAIN;
		}

		break;
	case SceneTitle::TITLE_MAIN:
	
		if (KEYINPUT::IsPushTrg(KEY_SPACE))
		{
			Fade::RequestFadeOut();
			m_state = TITLE_ENDWAIT;
		}
		break;
	case SceneTitle::TITLE_ENDWAIT:
		
		if (Fade::IsEndFadeOut() == true)
		{
			m_state = TITLE_END;
		}

		break;
	case SceneTitle::TITLE_END:

		m_state = TITLE_INIT;
		
		ret = 1;
		break;
	}
	return ret;
}

void SceneTitle::Draw()
{
	switch (m_state)
	{
	case SceneTitle::TITLE_START:
	case SceneTitle::TITLE_MAIN:
	case SceneTitle::TITLE_ENDWAIT:
		
		for (int i = 0; i < THndl_NUM; i++)
		{
			DrawRotaGraph(0.0f, 0.0f, 1.0f, 0.0f, m_hndl[i], TRUE);
		}

		break;
	}
}