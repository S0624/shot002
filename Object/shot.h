#pragma once
#include "Vec2.h"

class Enemy;

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void setHandle(int handle) { m_handle = handle; }

	// 発射
	void start(Vec2 pos);

	// 更新
	void update();
	// 表示
	void draw();
	
	// 弾の進行方向決定
	void setVec(Vec2 vec) { m_vec = vec; }

	// 存在するか
	bool isExist()const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }
	
	// 存在するか
	bool isPlayerShot()const { return m_isPlayerShot; }
	void setPlayerShot(bool  isPlayerShot) { m_isPlayerShot = isPlayerShot; }
	
	// 敵との当たり判定
	bool isCol(Enemy& enemy);
private:
	// グラフィックハンドル
	int m_handle;
	//　存在フラグ
	bool m_isExist;

	// 表示位置
	Vec2	m_pos;
	// 移動
	Vec2	m_vec;
	//　プレイヤーが撃った弾かどうか
	bool m_isPlayerShot;
};