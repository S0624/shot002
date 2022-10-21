#include "DxLib.h"
#include "shot.h"
#include "game.h"


Shot::Shot() : 
	m_handle(-1),
	m_isExist(false),			//コンストラクタ初期化子
	m_pos(100.0f,100.f),		//最初に値を設定して初期化することが可能になり二度手間じゃなくなる
	m_vec(8.0f, 0.0f)
{
}

Shot::~Shot()
{

}

void Shot::start(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;
}

void Shot::update()
{
	if (!m_isExist)return;

	m_pos += m_vec;
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}
// 表示
void Shot::draw()
{
	if (!m_isExist)return;

	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}
