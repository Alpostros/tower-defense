#pragma once
#include "Enemy.h"

class EnemyH: public Enemy
{
public:
	EnemyH(void);
	EnemyH(int k);
	void draw(string direction);
	~EnemyH(void);
};

