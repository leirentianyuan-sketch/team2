#include "CSceneResult.h"
#include "../../../common.h"
#include "../../../Lib/Fade/CFade.h"
#include "../../../Lib/File/CFile.h"
#include "../../../Lib/Input/CInput.h"
#include "../../../Game/Object/UI/CUI.h"

static const char kari[][128] = {
	"Data/Images/Result/result.jpg" };

int SceneResult::Update()
{
	int ret = 0;

	switch (m_state)
	{
	case SceneResult::RESULT_INIT:
	
		for (int i = 0; i < hndl_NUM; i++)
		{
			m_hndl[i] = -1;
		}
		/*m_pos = VEC_ZERO;*/
		
		m_state = RESULT_LOAD;

		break;
	case SceneResult::RESULT_LOAD:
		
		if (m_hndl[0] == -1)
		{	
			for (int i = 0; i < hndl_NUM; i++)
			{
				m_hndl[i] = LoadGraph(kari[i]);
			}
		}
		
		Fade::RequestFadeIn();

		m_state = RESULT_START;
		
		break;
	case SceneResult::RESULT_START:
		if (Fade::IsEndFadeIn() == true)
		{
			m_state = RESULT_MAIN;
		}
		break;
	case SceneResult::RESULT_MAIN:

		if (KEYINPUT::IsPushTrg(KEY_SPACE))
		{
			Fade::RequestFadeOut();
			m_state = RESULT_ENDWAIT;
		}
		break;
	case SceneResult::RESULT_ENDWAIT:
		if (Fade::IsEndFadeOut())
		{
			m_state = RESULT_END;
		}
		break;
	case SceneResult::RESULT_END:
		
		if (m_hndl[0] != -1)
		{
			for (int i = 0; i < hndl_NUM; i++)
			{
				DeleteGraph(m_hndl[i]);
				m_hndl[i] = -1;
			}
		}

		m_state = RESULT_INIT;

		ret = 1;
		break;
	}
	return ret;
}

void SceneResult::Draw()
{
	switch (m_state)
	{
	case SceneResult::RESULT_START:
	case SceneResult::RESULT_MAIN:
	case SceneResult::RESULT_ENDWAIT:

		for (int i = 0; i < hndl_NUM; i++)
		{
			DrawRotaGraph(0.0f, 0.0f, 1.0f, 0.0f, m_hndl[i], TRUE);
		}
		break;
	}
}