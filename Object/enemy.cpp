#include "DxLib.h"
#include "game.h"
#include "enemy.h"

namespace
{

}

Enemy::Enemy()
{
	m_handle = -1;
}

Enemy::~Enemy()
{
	
}

void Enemy::init()
{
	m_pos.x = Game::kScreenWidth - 80.0f;
	m_pos.y = Game::kScreenHeight / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
}

void Enemy::update()
{
	m_pos += m_vec;
}

void Enemy::draw()
{
//	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	DrawTurnGraphF(m_pos.x, m_pos.y, m_handle, true);
}