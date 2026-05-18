#pragma once
#include "DxLib.h"
#include <type_traits>

class Func
{
public:
	static VECTOR GetOffset();

	// 角度をラジアンに変換する関数
	static float AngletoRazian(const float angle);

	// ラジアンを角度に変換する関数
	static float RazianToAngle(const float razian);

	// 指定した中心点を基準に、指定した角度と半径から円周上の座標を取得する関数
	static VECTOR GetCirclePos(const float angle, const float radius, const VECTOR center);

	// 指定した2点間の距離を取得する関数
	static float GetDistance(const VECTOR pos1, const VECTOR pos2);

	// 指定した2点間の角度を取得する関数
	static float GetAngle(const VECTOR pos1, const VECTOR pos2);

	//ベクトルの加法
	static VECTOR VectorAdd(const VECTOR vec1, const VECTOR vec2);

	//ベクトルの減法
	static VECTOR VectorSub(const VECTOR vec1, const VECTOR vec2);

	//ベクトルのスカラー倍
	static VECTOR VectorScale(const VECTOR vec, const float scale);

	//ベクトルの正規化
	static VECTOR VectorNormalize(const VECTOR vec);

	//ベクトルの内積
	static float VectorDot(const VECTOR vec1, const VECTOR vec2);

	//ベクトルの外積
	static float VectorCross(const VECTOR vec1, const VECTOR vec2);

	//ベクトルの長さ
	static float VectorLength(const VECTOR vec);

	//	角度差を正規化する関数
	static float NormalizeAngle(float Angle);

	//	Enumをインデックスに変換する関数
	template<typename E>
	static constexpr auto toIndex(E e)
	{
		return static_cast<std::underlying_type_t<E>>(e);
	}

};

