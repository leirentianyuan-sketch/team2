#include "PL.h"
#include"../../../Lib/Input/CInput.h"
//プレイヤーの座標
#define PL_X (350.0f)
#define PL_Y (750.0f)
#define PL_SIZE (0.25f)

//プレイヤーの速さ
#define PL_SPEED (7.0f)

//プレイヤーのバフ・デバフ
#define PL_DAWN (0.8f)
#define PL_Jump (1.2f)

void PL_DATA::Init() {
	m_speed = 0;
	m_hndl = -1;
	m_jump = 0;
	m_size = PL_SIZE;
	pos.x = PL_X;
	pos.y = PL_Y;
	m_isActive = true;
}
void PL_DATA::Load() {
	if (m_hndl == -1)
	{
		//m_hndl = LoadGraph("Data/Images/Game/kari/red_car.png");
		m_hndl = LoadGraph("Data/Images/Game/kari/speaki_material.webp");
	}
}

void PL_DATA::Step() {

	//左右ボタンの反応

	if (m_isActive)
	{
		//左右移動
		if (KEYINPUT::IsPush(KEY_RIGHT)) {
			pos.x += PL_SPEED;

		}
		if (KEYINPUT::IsPush(KEY_LEFT)) {
			pos.x -= PL_SPEED;
		}
		
	}

	if (pos.x >= 550) {
		pos.x = 550;
	}
	if (pos.x <= 150) {
		pos.x = 150;
	}
	
}

//ジャンプ台が当たった反応
void PL_DATA::Exit() {
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}
//GetJumpを使ってジャンプの判定をもらう

void PL_DATA::jumpAC() {
	m_speed *= PL_Jump;

	//ここサイズ変更のプログラミング
}

//作る暇があるならスピードが限界値を超えた場合のデバフを作る
void PL_DATA::Draw() {
	if (m_isActive)
	{
		DrawRotaGraphF(pos.x, pos.y, m_size, 0.0f, m_hndl, TRUE);

	}
}

