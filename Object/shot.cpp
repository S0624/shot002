#include "DxLib.h"
#include "shot.h"
#include "game.h"
#include "Enemy.h"


Shot::Shot() : 
	m_handle(-1),
	m_isExist(false),			//�R���X�g���N�^�������q
	m_pos(100.0f,100.f),		//�ŏ��ɒl��ݒ肵�ď��������邱�Ƃ��\�ɂȂ��x��Ԃ���Ȃ��Ȃ�
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
// �\��
void Shot::draw()
{
	if (!m_isExist)return;

	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}

bool Shot::isCol(Enemy& enemy)
{
	if (!m_isExist) return false;								//�e�����݂��Ȃ��ꍇ�͓�����Ȃ�
	if (!enemy.isExist()) return false;							//�G�����݂��Ȃ��ꍇ�͓�����Ȃ�

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

	if (enemyLeft > shotRight)return false;				//�G�l�~�[�̍����V���b�g�̉E��菬�����ꍇ
	if (enemyTop > shotButtom)return false;				//�G�l�~�[�̏オ�V���b�g�̉���菬�����ꍇ
	if (enemyRight < shotLeft)return false;				//�G�l�~�[�̉E���V���b�g�̍����傫���ꍇ
	if (enemyButtom < shotTop)return false;				//�G�l�~�[�̉����V���b�g�̏���傫���ꍇ

	return true;
}