#pragma once

#include "Vec2.h"

class SceneMain;

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	// SceneMainを設定
	void setMain(SceneMain* pMain) { m_pMain = pMain; }

	// グラフィックデータ設定
	void setHandle(int handle) { m_handle = handle; }

	// プレイヤーの初期化
	void init();

	// 処理
	void update();
	// 描画
	void draw();

	// 存在するか
	bool isExist()const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	// 当たり判定の幅、高さを取得
	float getColWidth();
	float getColHeight();

private:
	SceneMain* m_pMain;

	int m_handle;

	//　存在フラグ
	bool m_isExist;
	// ショットの発生間隔
	int m_shotInterval;
	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
};