#pragma once
#include <iostream>
#include <string>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

class Road
{
public:
	Road(int cho);
	void move(int cho);
	~Road(void);
	int getX();
	int getY();
private:
	int x, y;
	bool ctrl, ctrl2, ctrl3;
};

