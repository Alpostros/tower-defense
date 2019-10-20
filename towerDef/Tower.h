#pragma once
#include <iostream>
#include "rlutil.h"
#include "Gun.h"
using namespace std;
using namespace rlutil;

class Tower
{
private:
	int level;
	static int number;
	int x;
	int y;
	int type;
public:
	Gun **guns;
	int gunNumber;
	Tower(void);
	Tower(int num);
	void draw(int level, int type);
	~Tower(void);
	int getLevel();
	void setLevel(int);
	void shoot(int,int);
	void mtshoot(int, int);
	int getType();
};

