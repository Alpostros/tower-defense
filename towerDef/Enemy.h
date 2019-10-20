#pragma once
#include <iostream>
#include <string>
#include "rlutil.h"
#include "Road.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace rlutil;

class Enemy
{
public:
	Enemy(void);
	Enemy(int k);
	virtual void draw(string direction) = 0;
	string findDirection(int x, int y);
	void clearRoad();
	bool hasWon();
	bool isDead();
	void moveTo();
	~Enemy(void);
	int getx();
	void setx(int x);
	int gety();
	int getHealth();
	void setHealth(int h);
protected:
	Road *r;
	string direction;
	int x,y,way, health;
};

