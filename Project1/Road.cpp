#include "Road.h"



Road::Road(int cho)
{
	switch (cho)
	{
	case 1:
		x = 64;
		y = 16;
		break;
	case 2:
		x = 64;
		y = 16;
		ctrl = 1;
		break;
	case 3:
		x = 61;
		y = 7;
		break;
	case 4:
		x = 61;
		y = 7;
		ctrl = 1;
		break;
	default:
		x = 52;
		y = 28;
		ctrl = 1;
		ctrl2 = 1;
		ctrl3 = 1;
		break;
	}
}

int Road::getX()
{
	return(x);
}

int Road::getY()
{
	return(y);
}

void Road::move(int cho)
{
	setBackgroundColor(BROWN);
	switch (cho)
	{
	case 1:
		if(x >= 46)
		{
			x--;
		}
		else if(y >= 14)
		{
			y--;
		}
		else if(x >= 30)
		{
			x--;
		}
		else if(y >= 11)
		{
			y--;
		}
		else if(x >= 13)
		{
			x--;
		}
		else if(y >= 8)
		{
			y--;
		}
		else if(x >= -1)
		{
			x--;
		}
		break;
	case 2:
		if(x >= 46)
		{
			x--;
		}
		else if(y >= 14 && ctrl)
		{
			y--;
		}
		else if(x >= 30)
		{
			ctrl = 0;
			x--;
		}
		else if(y <= 15)
		{
			y++;
		}
		else if(x >= 13)
		{
			x--;
		}
		else if(y <= 18)
		{
			y++;
		}
		else if(x >= -1)
		{
			x--;
		}
		break;
	case 3:
		if(x >= 42)
		{
			x--;
		}
		else if(y <= 12)
		{

			y++;
		}
		else if(x >= 30)
		{
			ctrl = 0;
			x--;
		}
		else if(y <= 15)
		{
			y++;
		}
		else if(x >= 13)
		{
			x--;
		}
		else if(y <= 18)
		{
			y++;
		}
		else if(x >= -1)
		{
			x--;
		}
		break;
	case 4:
		if(x >= 42)
		{
			x--;
		}
		else if(y <= 12 && ctrl)
		{
			y++;
		}
		else if(x >= 30)
		{
			ctrl = 0;
			x--;
		}
		else if(y >= 11)
		{
			y--;
		}
		else if(x >= 13)
		{
			x--;
		}
		else if(y >= 8)
		{
			y--;
		}
		else if(x >= -1)
		{
			x--;
		}
		break;
	default:
		if(y >= 24 && ctrl)
		{
			y--;
		}
		else if(x >= 40)
		{
			ctrl = 0;
			x--;
		}
		else if(y <= 25 && ctrl2)
		{
			y++;
		}
		else if(x >= 26)
		{
			ctrl2 = 0;
			x--;
		}
		else if(y >= 17 && ctrl3)
		{
			y--;
		}
		else if(x >= 13)
		{
			ctrl3 = 0;
			x--;
		}
		else if(y <= 18)
		{
			y++;
		}
		else if(x >= -1)
		{
			x--;
		}
		break;
	}
}


Road::~Road(void)
{
}
