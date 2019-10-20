#pragma once
#include <iostream>
#include <string>
#include "rlutil.h"
#include "Enemy.h"

using namespace std;
using namespace rlutil;

class Gun
{
public:
	Gun(int x, int y, int range, string direction, int level);
	void controlRoad();
	void resetXY();
	void fire();
	string getDirection();
	void fixBG();
	~Gun(void);
	int xE, yE;
	int getRange();
	int damage;
	void refreshGun(int level);
private:
	int x, y, range, level;
	string direction;
};

