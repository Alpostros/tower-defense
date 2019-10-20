#include "EnemyQ.h"


EnemyQ::EnemyQ(void)
{
	health = 75;
}

EnemyQ::EnemyQ(int k)
{
	health = 75 * k;
}


void EnemyQ::draw(string direction)
{
	setBackgroundColor(BROWN);
	setColor(BLACK);
	if (x >= 2 && x < 60 && y >= 2 && y < 27)
	{
		if(direction == "right")
		{
			locate(x,y);
			cout << "##";
			locate(x,y+1);
			cout << "###";
			locate(x,y+2);
			cout << "##";
		}
		else if(direction == "left")
		{
			locate(x,y);
			cout << " ##";
			locate(x,y+1);
			cout << "###";
			locate(x,y+2);
			cout << " ##";
		}
		else if(direction == "up")
		{
			locate(x,y);
			cout << " #";
			locate(x,y+1);
			cout << "###";
			locate(x,y+2);
			cout << "###";
		}
		else if(direction == "down")
		{
			locate(x,y);
			cout << "###";
			locate(x,y+1);
			cout << "###";
			locate(x,y+2);
			cout << " #";
		} 
	}
}



EnemyQ::~EnemyQ(void)
{
}
