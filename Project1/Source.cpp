// Copyright (c) 2019 Alpostros

#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "Tower.h"
#include "EnemyQ.h"
#include "EnemyH.h"
#include "Road.h"
using namespace std;
using namespace rlutil;

void draw();
void printMap();
void printMenu();
void upgradeTower(Tower* t);
void keyReg();
void createEnemy();
void createTower();
void gameOver();
void printEnemy();
bool hasShot();
void ctrlWin();
void gameWon();
Enemy* enemy[6];
Tower* tower[5];
int map_width = 60, map_height = 30, stage = 1, points = 0, basehealth = 2000, enemynumber, dead_enemy;

int main()
{
	draw();
	createTower();
	hidecursor();
	locate(20, 6);
	cout << "Press any key to start!";
	getkey();
	locate(20, 6);
	setBackgroundColor(GREEN);
	cout << "                             ";
	int bossCount = 0;
	bool ctrl = true;
	for (int i = 1; i <= 3 && basehealth > 0 && ctrl; i++) // Stage counter
	{
		stage = i;
		enemynumber = dead_enemy = 0;
		int step = 0;
		do {
			printMenu();
			step++;
			if (step % 21 == 1 && dead_enemy <= 14)
			{
				createEnemy();
			}
			printEnemy();
			locate(2, 2);
			hasShot();
			msleep(280 / sqrt(enemynumber * 3.14));
			ctrlWin();
			if (kbhit()) {
				char k = getch();
				if (k == '1') {
					keyReg();
				}
				if (k == 'e') {
					ctrl = false;
				}
			}
			if (dead_enemy > 14)
			{
				bossCount++;
			}

		} while (basehealth >= 0 && (dead_enemy < 14 || bossCount <= 90) && ctrl);
	}
	if (basehealth > 0)
	{
		gameWon();
	}
	else {
		gameOver();
	}

	getch();
}

void draw() {
	printMap();
	printMenu();
}

void printMap() { // Map borders
	for (int i = 1; i <= map_width; i++) {
		locate(i + 1, 1);
		setBackgroundColor(MAGENTA);
		cout << "*";
		locate(i, map_height - 1);
		cout << "*";
	}
	for (int i = 0; i < map_height; i++) {
		locate(1, i);
		cout << "*";
		locate(map_width + 2, i);
		cout << "*";
	}
	for (int i = 2; i < map_height - 1; i++) { // Coloring map
		for (int j = 2; j < map_width + 2; j++) {
			locate(j, i);
			setBackgroundColor(GREEN);
			cout << " ";
		}

	}
	for (int i = 2; i < 16; i++) { //Drawing paths, to right
		for (int j = 7; j < 10; j++) {
			setBackgroundColor(BROWN);
			locate(i - 1, j);
			cout << " ";
			locate(i, j);
			cout << " ";
			locate(i, j + 12);
			cout << " ";
			locate(i - 1, j + 12);
			cout << " ";
			locate(i + 10, j + 3);
			cout << " ";
			locate(i + 10, j + 9);
			cout << " ";
			locate(i + 17, j + 3);
			cout << " ";
			locate(i + 17, j + 9);
			cout << " ";
			locate(i + 27, j + 6);
			cout << " ";
			locate(i + 33, j + 6);
			cout << " ";
			locate(i + 42, j + 9);
			cout << " ";
			locate(i + 46, j + 9);
			cout << " ";
			locate(i + 36, j + 16);
			cout << " ";
			locate(i + 39, j + 16);
			cout << " ";
			locate(i + 25, j + 19);
			cout << " ";
			locate(i + 26, j + 19);
			cout << " ";
			locate(i + 43, j);
			cout << " ";
			locate(i + 46, j);
			cout << " ";
			locate(i + 47, j + 9);
			cout << " ";
			locate(i + 47, j);
			cout << " ";
		}
	}
	for (int i = 25; i < 29; i++) { // Drawing upper and lower paths.
		for (int j = 19; j < 29; j++) {
			locate(i, j);
			cout << " ";
			locate(i + 16, j - 12);
			cout << " ";
			if (j + 10 < 34) {
				locate(i + 26, j + 6);
				cout << " ";
			}
		}
	}
}

void printMenu() // A.Ö
{
	int controlsX = map_width + 10;
	setBackgroundColor(BROWN);
	setColor(WHITE);
	locate(controlsX, 1);
	cout << "Wawe : " << stage;
	locate(controlsX, 2);
	cout << "HEALTH : " << basehealth;
	if (basehealth <= 999) {
		locate(controlsX + 12, 2);
		cout << " ";
	}
	locate(controlsX, 3);
	cout << "Builder Points : " << points;
	locate(controlsX, 4);
	cout << "1 - Upgrade Tower";
	locate(controlsX, 5);
	cout << "e - Exit Game";
	setBackgroundColor(LIGHTBLUE);
	locate(controlsX, 6);
	cout << "---HOW TO PLAY---";
	locate(controlsX, 7);
	cout << "Enemies are thirsty for your blood!";
	locate(controlsX, 8);
	cout << "Upgrade your towers to survive 3 waves!";
	locate(controlsX, 9);
	cout << " Doing tower upgrades will increase damage.";
	locate(controlsX, 10);
	cout << "Enemies will get stronger withing waves!";
	locate(70, 26);
}

void upgradeTower(Tower* t) {
	if (t->getLevel() <= 3 && points >= t->getLevel() * 1000) {
		points -= t->getLevel() * 1000;
		t->setLevel(t->getLevel() + 1);
		t->draw(t->getLevel(), t->getType());
		locate(70, 26);
		cout << "Tower has been upgarded.";
	}
	else if (t->getLevel() == 3) {
		locate(70, 26);
		cout << "Tower level is already max.";
	}
	else if (points < t->getLevel() * 1000) {
		locate(70, 26);
		cout << "Insufficent points to upgrade tower.";
	}
	setBackgroundColor(BLACK);
	locate(70, 24);
	cout << "                         ";
	locate(70, 25);
	cout << "                                           ";
}

void createEnemy()
{
	srand(time(NULL));
	int x = enemynumber;
	for (int i = 0; i < enemynumber; i++)
	{
		if (enemy[i]->isDead())
		{
			points += (stage * 100);
			delete enemy[i];
			dead_enemy++;
			x = i;
			break;
		}
	}
	switch (rand() % 2)
	{
	case 0:
		enemy[x] = new EnemyH(stage);
		break;
	case 1:
		enemy[x] = new EnemyQ(stage);
		break;
	}
	if (x == enemynumber && enemynumber <= 6)
		enemynumber++;
}

void printEnemy()
{
	for (int i = 0; i < enemynumber; i++)
	{
		if (!enemy[i]->isDead())
			enemy[i]->moveTo();
	}
}

void createTower()
{
	tower[0] = new Tower;
	for (int i = 1; i < 5; i++)
	{
		tower[i] = new Tower(i);
	}
}

bool hasShot()
{
	int i, j, k, t;
	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < tower[j]->gunNumber; i++)
		{
			tower[j]->guns[i]->refreshGun(tower[j]->getLevel());
			tower[j]->guns[i]->resetXY();
			for (t = 0; t < tower[j]->guns[i]->getRange(); t++)
			{
				tower[j]->guns[i]->controlRoad();
				for (k = 0; k < enemynumber; k++)
				{

					if (tower[j]->guns[i]->getDirection() == "left")
					{
						if (tower[j]->guns[i]->xE == enemy[k]->getx() && tower[j]->guns[i]->yE == (enemy[k]->gety() + 1))
						{
							enemy[k]->setHealth(enemy[k]->getHealth() - tower[j]->guns[i]->damage);
							if (!enemy[k]->isDead())
							{
								tower[j]->guns[i]->fire();
								msleep(25);
								tower[j]->guns[i]->fixBG();
								return(true);
							}
						}
					}
					else
					{
						if (tower[j]->guns[i]->xE == enemy[k]->getx() + 1 && tower[j]->guns[i]->yE == (enemy[k]->gety()))
						{
							enemy[k]->setHealth(enemy[k]->getHealth() - tower[j]->guns[i]->damage);
							if (!enemy[k]->isDead())
							{
								tower[j]->guns[i]->fire();
								msleep(25);
								tower[j]->guns[i]->fixBG();
								return(true);
							}
						}
					}


				}
			}
		}
	}

	return(false);
}

void ctrlWin()
{
	for (int i = 0; i < enemynumber; i++)
	{
		if (enemy[i]->hasWon())
		{
			enemy[i]->setHealth(-100);
			basehealth -= 200;
			enemy[i]->setx(1);
		}

	}
}

void keyReg()
{
	int num;
	locate(70, 24);
	setBackgroundColor(LIGHTRED);
	setColor(WHITE);
	cout << "Game  has been paused.";
	locate(70, 25);
	setBackgroundColor(LIGHTRED);
	cout << "Select a tower and press enter to upgrade.";
	cin >> num;
	upgradeTower(tower[num]);
}

void gameOver() {
	for (int i = 0; i < map_height; i++) { // Coloring map
		for (int j = 0; j < map_width + 2; j++) {
			locate(j, i);
			setBackgroundColor(RED);
			cout << " ";
		}
	}
	locate(25, 15);
	cout << "---GAME OVER---";
}

void gameWon() {
	for (int i = 0; i < map_height; i++) { // Coloring map
		for (int j = 0; j < map_width + 2; j++) {
			locate(j, i);
			setBackgroundColor(GREEN);
			cout << " ";
		}
	}
	locate(25, 15);
	cout << "---YOU WIN!---";
}