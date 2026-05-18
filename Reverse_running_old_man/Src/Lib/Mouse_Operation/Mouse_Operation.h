#pragma once
#include<DxLib.h>
#include "../../Lib/Collision/CCollision.h"

class Mouse_Operation
{
private:	
	int m_Mouse_X;	//マウス横
	 int m_Mouse_Y; //マウス縦
	 VECTOR m_pos;
public:
	void Init();
	void Step();

	//左クリック長押し物体にマウスの座標を入れる
	void Hold( VECTOR &pos, int size_X, int size_y);

	//何番目の物体とマウスが当たったかどうかを判断する
	bool IsHitObject(const VECTOR& pos, int size_X, int size_y);

	void ComHold(BOX& box, int id);

	//マウスの座標
	VECTOR Get_pos() { return m_pos; }
};