#include "../../common.h"
#include "CHitCheck.h"
#include "../../Lib/Collision/CCollision.h"

#include "../../Game/Object/Player/PL.h"
#include "../../Game/Object/Enemy/Enemy.h"

extern PL_DATA pl;
extern Enemy en;

const float CAR_HalfX = 470.0f * 0.2f * 0.5f;
const float CAR_HalfY = 700.0f * 0.2f * 0.5f;

bool CHitCheck::EnemyToPlayer()
{
	if (!pl.m_isActive)return false;

	int result = false;

	for (int enemyID = 0; enemyID < en.EHndl_NUM; enemyID++)
	{
		if (!en.m_isActive[enemyID])continue;

		bool Hit = Collision::IsHit({ pl.pos,CAR_HalfX,CAR_HalfY}, {en.m_pos[enemyID],CAR_HalfX,CAR_HalfY});

		if (Hit)
		{
			pl.m_isActive = false;
			result = true;
			break;
		}
	}
	return result;
}