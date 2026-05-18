#pragma once
#include "DxLib.h"

//	箱構造体
struct BOX
{
	VECTOR Pos;		//	箱の座標
	float halfX;	//	Xの半分
	float halfY;	//	Yの半分
};

//	円構造体
struct CIRCLE
{
	VECTOR Pos;		//	円の座標
	float Radius;	//	半径
};

class Collision
{
public:
	//	当たり判定の関数
	//	dotPos		:	点の座標
	//	BOX			:	四角形の構造体 {座標, Xの半分, Yの半分}
	//	CIRCLE		:	円の構造体 {座標, 半径}

	//	点と四角の当たり判定
	static bool IsHit(const VECTOR& dotPos, const BOX& box);	

	//	点と円の当たり判定
	static bool IsHit(const VECTOR& dotPos, const CIRCLE& circle);
	
	//	四角同士の当たり判定
	static bool IsHit(const BOX& a, const BOX& b);
	
	//	円同士の当たり判定
	static bool IsHit(const CIRCLE& a, const CIRCLE& b);

	//	円と四角の当たり判定
	static bool IsHit(const CIRCLE& circle, const BOX& box);
	static bool IsHit(const BOX& box, const CIRCLE& circle);

};

