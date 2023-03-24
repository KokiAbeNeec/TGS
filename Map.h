#pragma once
#include "Player.h"

const int width = 20;
const int length = 10;

class Map
{
public:
	void Initialize(Player* _player);	// 初期化
	void Update();		// 更新
	void Draw();		// 描画
public:

private:
	enum MAPBLOCK
	{
		NONE,
		BLOCK
	};
	
	Player* player_ = nullptr;
};

