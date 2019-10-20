#include "EnemyH.h"


EnemyH::EnemyH(void)
{
	health = 105;
}

EnemyH::EnemyH(int k)
{
	health = 105 * k;
}

void EnemyH::draw(string direction)
{
	setBackgroundColor(BROWN);
	setColor(BLACK);
	if (x >= 2 && x < 60 && y >= 2 && y < 27)
	{
		locate(x,y);
		cout << " o";
		locate(x,y+1);
		cout << "/|\\";
		locate(x,y+2);
		cout << "/-\\"; 
	}
}

EnemyH::~EnemyH(void)
{
}
