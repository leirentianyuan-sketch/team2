#include"Mouse_Operation.h"
#include"../Input/CInput.h"
#include"../Collision/CCollision.h"
#include "../../common.h"


void Mouse_Operation::Init()
{	// マウスを表示状態にする
	m_Mouse_X = 0;
	m_Mouse_Y = 0;
	m_pos = { 0.0f,0.0f,0.0f };

}

void Mouse_Operation::Step()
{// マウスの位置を取得
	GetMousePoint(&m_Mouse_X, &m_Mouse_Y);
	//マウスポスをベクターに入れる
	m_pos = { (float)m_Mouse_X, (float)m_Mouse_Y, 0.0f };
	// 座標表示デバック

	DrawFormatString(0, 20, GetColor(255, 255, 255), "座標Ｘ %d　　座標Ｙ %d", m_Mouse_X, m_Mouse_Y);


	
	// 自分が調べたいボタンが押されていたらビットを立てていく
}
//void Mouse_Operation::Hold(VECTOR &pos,int size_X,int size_y)
//{
//	// クリックを押したか
//	if (KEYINPUT::IsPush(KEY_LCLICK))
//	{//マウスと物体が当たったら
//
//		bool Hit = CheckHitDotToSquare(m_pos, pos, size_X / 4, size_y / 4);
//		if (Hit == true)
//		{
//			pos = m_pos;
//		}
//	}
//}
bool Mouse_Operation::IsHitButton(const VECTOR &pos, CIRCLE& b)
{
	// クリックを押したか
	if (KEYINPUT::IsPush(KEY_LCLICK) == false) return false;

	bool Hit = Collision::IsHit(m_pos, b);
	if (Hit == true)
	{
		return true;
	}
	return false;
}

bool Mouse_Operation::IsHitWindow(const VECTOR& pos, BOX& box)
{
	// クリックを押したか
	if (KEYINPUT::IsPush(KEY_LCLICK) == false) return false;

	bool Hit = Collision::IsHit(m_pos, box);
	if (Hit == true)
	{
		return true;
	}
	return false;
}