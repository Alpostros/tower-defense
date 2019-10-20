#include "Enemy.h"


Enemy::Enemy(void)
{
	srand(time(NULL));
	way = (rand() % 5)+1;
	r = new Road(way);
	x = r->getX();
	y = r->getY();
}

Enemy::Enemy(int k)
{
	srand(time(NULL)); 
	way = (rand() % 5)+1;
	r = new Road(way);
	x = r->getX();
	y = r->getY();
}

string Enemy::findDirection(int x, int y)
{
	if(x > Enemy::x)
	{
		return("right");
	}
	else if(x < Enemy::x)
	{
		return("left");
	}
	else if(y < Enemy::y)
	{
		return("up");
	}
	else
	{
		return("down");
	}
}

void Enemy::moveTo()
{
	r->move(way);
	direction = findDirection(r->getX(), r->getY());
	clearRoad();
	x = r->getX();
	y = r->getY();
	msleep(15);
	draw(direction);
	
}

bool Enemy::hasWon()
{
	if(x < 1)
		return(true);
	return(false);
}

bool Enemy::isDead()
{
	if(health <= 0)
	{
		clearRoad();
		return(true);
	}
	return(false);
}

void Enemy::clearRoad()
{
	setBackgroundColor(BROWN);
	if (x >= 2 && x < 60 && y >= 2 && y < 27)
	{
		locate(x,y);
		cout << "   ";
		locate(x,y+1);
		cout << "   ";
		locate(x,y+2);
		cout << "   "; 
	}
}

Enemy::~Enemy(void)
{
	clearRoad();
	delete r;
}

int Enemy::getx() {
	return x;
}

int Enemy::gety() {
	return y;
}

int Enemy::getHealth()
{
	return(health);
}

void Enemy::setx(int x)
{
	this->x = x;
}

void Enemy::setHealth(int h)
{
	health = h;
}