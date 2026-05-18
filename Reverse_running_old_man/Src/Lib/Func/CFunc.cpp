#include "../../common.h"
#include "math.h"


#include "Func.h"

VECTOR Func::GetOffset()
{
	return { FALSE,FALSE,FALSE };
}

float Func::AngletoRazian(const float angle)
{
	return angle * (DX_PI_F / 180.0f);
}

float Func::RazianToAngle(const float razian)
{
	return razian * (180.0f / DX_PI_F);
}

VECTOR Func::GetCirclePos(const float angle, const float radius, const VECTOR center)
{
	VECTOR pos;
	float radian = AngletoRazian(angle);
	pos.x = center.x + radius * cosf(radian);
	pos.y = center.y + radius * sinf(radian);
	return pos;
}

float Func::GetDistance(const VECTOR pos1, const VECTOR pos2)
{
	return sqrtf((pos2.x - pos1.x) * (pos2.x - pos1.x) + (pos2.y - pos1.y) * (pos2.y - pos1.y));
}

float Func::GetAngle(const VECTOR pos1, const VECTOR pos2)
{
	return RazianToAngle(atan2f(pos2.y - pos1.y, pos2.x - pos1.x));
}

VECTOR Func::VectorAdd(const VECTOR vec1, const VECTOR vec2)
{
	VECTOR result;
	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	return result;
}

VECTOR Func::VectorSub(const VECTOR vec1, const VECTOR vec2)
{
	VECTOR result;
	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	return result;
}

VECTOR Func::VectorScale(const VECTOR vec, const float scale)
{
	VECTOR result;
	result.x = vec.x * scale;
	result.y = vec.y * scale;
	return result;
}

VECTOR Func::VectorNormalize(const VECTOR vec)
{
	float length = sqrtf(vec.x * vec.x + vec.y * vec.y);
	if (length == 0)
	{
		return vec; // ’·‚³‚ª0‚Ìê‡‚Í‚»‚Ì‚Ü‚Ü•Ô‚·
	}
	VECTOR result;
	result.x = vec.x / length;
	result.y = vec.y / length;
	return result;
}

float Func::VectorDot(const VECTOR vec1, const VECTOR vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

float Func::VectorCross(const VECTOR vec1, const VECTOR vec2)
{
	return vec1.x * vec2.y - vec1.y * vec2.x;
}

float Func::VectorLength(const VECTOR vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

float Func::NormalizeAngle(float Angle)
{
	while (Angle > DX_PI_F)Angle -= DX_TWO_PI_F;
	while (Angle < -DX_PI_F)Angle += DX_TWO_PI_F;
	return Angle;
}
