#include "DxLib.h"
#include "shot.h"
#include "game.h"
#include "Enemy.h"


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

bool Shot::isCol(Enemy& enemy)
{
	if (!m_isExist) return false;								//弾が存在しない場合は当たらない
	if (!enemy.isExist()) return false;							//敵が存在しない場合は当たらない

	float shotWidth = 0;
	float shotHeight = 0;
	GetGraphSizeF(m_handle, &shotWidth, &shotHeight);

	float shotLeft		= m_pos.x;
	float shotTop		= m_pos.y;
	float shotRight		= m_pos.x + shotWidth;
	float shotButtom	= m_pos.y + shotHeight;

	float enemyLeft		= enemy.getPos().x;
	float enemyTop		= enemy.getPos().y;
	float enemyRight	= enemy.getPos().x + enemy.getColWidth();
	float enemyButtom	= enemy.getPos().y + enemy.getColHeight();

	if (enemyLeft > shotRight)return false;				//エネミーの左がショットの右より小さい場合
	if (enemyTop > shotButtom)return false;				//エネミーの上がショットの下より小さい場合
	if (enemyRight < shotLeft)return false;				//エネミーの右がショットの左より大きい場合
	if (enemyButtom < shotTop)return false;				//エネミーの下がショットの上より大きい場合

	return true;
}