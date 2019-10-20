#include "Gun.h"


Gun::Gun(int x, int y, int range, string direction, int level)
{
	Gun::x = x;
	Gun::y = y;
	Gun::direction = direction;
	Gun::range = range;
	Gun::level = level;
	damage = 6 * level;
}

void Gun::resetXY()
{
	yE = y;
	xE = x;
}

void Gun::controlRoad()
{
	if(direction == "up")
	{
			yE--;
	}
	else if(direction == "down")
	{
			yE++;
	}
	else
	{
			xE++;
	}
}

void Gun::fire()
{
	if (yE == y) { // Shooting horizontally.
		for (int i = x; i <= xE-2; i++) {
			locate(i + 2, y );
			setColor(LIGHTRED);
			cout << "*";
		}
	}
	if (xE == x && y > yE) { // Shooting up.
		for (int i = y; i > yE+1; i--) {
			locate(xE, i - 1);
			setColor(LIGHTRED);
			cout << "*";
		}
	}
	else if (xE == x  && y <= yE) { // Shooting down.
		for (int i = y; i < yE; i++) {
			locate(xE, i + 1);
			setColor(LIGHTRED);
			cout << "*";
		}
	}
}

void Gun::fixBG()
{
	if (yE == y) { // Shooting horizontally.
		for (int i = x; i < xE-2; i++) {
			locate(i + 2, y );
			setColor(LIGHTRED);
			cout << " ";
		}
	}
	if (xE == x && y > yE) { // Shooting up.
		for (int i = y; i > yE; i--) {
			locate(xE, i - 1);
			setColor(LIGHTRED);
			cout << " ";
		}
	}
	else if (xE == x  && y < yE) { // Shooting down.
		for (int i = y; i < yE-2; i++) {
			locate(xE, i + 1);
			setColor(LIGHTRED);
			cout << " ";
		}
	}
}


int Gun::getRange()
{
	return(range);
}

string Gun::getDirection()
{
	return(direction);
}

void Gun::refreshGun(int level)
{
	Gun::level = level;
	damage = 5 * level;;
}



Gun::~Gun(void)
{
}
