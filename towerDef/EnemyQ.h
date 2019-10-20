#pragma once
#include "Enemy.h"

class EnemyQ: public Enemy
{
public:
	EnemyQ(void);
	EnemyQ(int k);
	void draw(string direction);
	void findDirection(int x, int y);
	~EnemyQ(void);
private:
	int i, j;
};

