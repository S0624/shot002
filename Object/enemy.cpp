#include "DxLib.h"
#include "game.h"
#include "enemy.h"

namespace
{

}

Enemy::Enemy() :
	m_handle (-1),
	m_isExist(false),
	m_pos(),
	m_vec()
{
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

	m_isExist = true;
}

void Enemy::update()
{
	m_pos += m_vec;
}

void Enemy::draw()
{
	if (!m_isExist)return;
//	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	DrawTurnGraphF(m_pos.x, m_pos.y, m_handle, true);
}

float Enemy::getColWidth()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempX;
}

float Enemy::getColHeight()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempY;
}