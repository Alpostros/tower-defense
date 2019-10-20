#include "Tower.h"


Tower::Tower(void)
{
	x = 2;
	y = 10;
	level = 1;
	type = 4;
	setBackgroundColor(BLACK);
	setColor(WHITE);
	locate(x+10,y+3);
	cout << 0;
	draw(level,type);
	gunNumber = 12;
	guns = new Gun*[gunNumber];
	for (int i = 0; i < 5; i++)
	{
		guns[i] = new Gun(x+(2*i),y,3,"up", level);
		guns[9-i] = new Gun(x+(2*i),y+8,3,"down", level);
	}
	guns[10] = new Gun(x+8,y+1,21,"left", level);
	guns[11] = new Gun(x+8,y+7,21,"left", level);
}

Tower::Tower(int num)
{
	level = 1;
	switch (num)
	{
	case 1:
		x = 25;
		y = 13;
		type = 0;
		draw(level,type);
		gunNumber = 3;
		guns = new Gun*[gunNumber];
		guns[0] = new Gun(x+1,y,3,"up", level);
		guns[1] = new Gun(x+1,y+2,20,"down", level);
		guns[2] = new Gun(x+2,y+1,20,"left", level);
		break;
	case 2:
		x = 37;
		y = 7;
		type = 3;
		draw(level,type);
		gunNumber = 1;
		guns = new Gun*[gunNumber];
		guns[0] = new Gun(x+2,y+1,21,"left", level);
		break;
	case 3:
		x = 41;
		y = 16;
		type = 1;
		draw(level,type);
		gunNumber = 2;
		guns = new Gun*[gunNumber];
		guns[0] = new Gun(x+2,y+1,17,"left", level);
		guns[1] = new Gun(x+1,y,9,"up", level);
		break;
	case 4:
		x = 34;
		y = 23;
		type = 2;
		draw(level,type);
		gunNumber = 2;
		guns = new Gun*[gunNumber];
		guns[0] = new Gun(x+2,y+1,17,"left", level);
		guns[1] = new Gun(x+1,y+2,3,"down", level);
		break;
	}
	setBackgroundColor(BLACK);
	setColor(WHITE);
	locate(x-1,y);
	cout << num;
}

void Tower::draw(int level, int type)
{
	
	setColor(BLACK);
	switch(level)
	{
	case 1:
		setBackgroundColor(DARKGREY);
		break;
	case 2:
		setBackgroundColor(LIGHTBLUE);
		break;
	case 3:
		setBackgroundColor(LIGHTMAGENTA);
		break;
	}
	switch(type)
	{
	case 1:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				locate(x+i, y+j);
				cout << " ";
			}
			for (int i = 0; i < 3; i++)
			{
				locate(x+3,y+i);
				cout << ">"; 
			}
			locate(x,y);
			cout << "^^^";
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				locate(x+i, y+j);
				cout << " ";
			}
			for (int i = 0; i < 3; i++)
			{
				locate(x+3,y+i);
				cout << ">"; 
			}
			locate(x,y+2);
			cout << "vvv";
		}
		break;
	case 0:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				locate(x+i, y+j);
				cout << " ";
			}
			for (int i = 0; i < 3; i++)
			{
				locate(x+3,y+i);
				cout << ">"; 
			}
			locate(x,y);
			cout << "^^^";
			locate(x,y+2);
			cout << "vvv";
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				locate(x+i, y+j);
				cout << " ";
			}
			for (int i = 0; i < 3; i++)
			{
				locate(x+3,y+i);
				cout << ">"; 
			}
		}
		break;
	case 4:
		for (int i = 2; i < 12; i++)
		{
			for (int j = 10; j < 19; j++)
			{
				locate(i, j);
				cout << " ";
				if (j != 13 && j != 14 && j != 15) {
					locate(11, j);
					setColor(BLACK);
					cout << ">";
				}
				if (i != 11 && j == 10) {
					locate(i, j);
					cout << "^";
				}
				if (i != 11 && j == 18) {
					locate(i, j);
					cout << "v";
				}
			}
		}
		break;

	}
}

Tower::~Tower(void)
{
}

int Tower::getLevel() {
	return level;
}

void Tower::setLevel(int a) {
	level = a;
}

int Tower::getType(){
	return type;
}