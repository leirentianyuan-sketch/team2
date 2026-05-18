#include "CCollision.h"

// “_‚ÆŽlŠpŒ`
bool Collision::IsHit(const VECTOR& dotPos, const BOX& box)
{
	return (
		dotPos.x >= box.Pos.x - box.halfX &&
		dotPos.x <= box.Pos.x + box.halfX &&
		dotPos.y >= box.Pos.y - box.halfY &&
		dotPos.y <= box.Pos.y + box.halfY	);
}

// “_‚Æ‰~
bool Collision::IsHit(const VECTOR& dotPos, const CIRCLE& circle)
{
	return (
		dotPos.x >= circle.Radius &&
		dotPos.x <= circle.Radius &&
		dotPos.y >= circle.Radius &&
		dotPos.y <= circle.Radius
		);
}

// ŽlŠpŒ`“¯Žm
bool Collision::IsHit(const BOX& a, const BOX& b)
{
	return (
		a.Pos.x + a.halfX >= b.Pos.x - b.halfX &&
		a.Pos.x - a.halfX <= b.Pos.x + b.halfX &&
		a.Pos.y + a.halfY >= b.Pos.y - b.halfY &&
		a.Pos.y - a.halfY <= b.Pos.y + b.halfY	);
}

// ‰~“¯Žm
bool Collision::IsHit(const CIRCLE& a, const CIRCLE& b)
{
	float dx = a.Pos.x - b.Pos.x;
	float dy = a.Pos.y - b.Pos.y;

	float distSq = dx * dx + dy * dy;
	float r = a.Radius + b.Radius;

	return distSq <= r * r;
}