#pragma once
#include "shop.h"
#include <iostream>

using namespace std;

class Game : public shop
{
private:
	int select;
public:
	Game();
	void run();
	void interface();
	int attack(int Attack, int hp);
	~Game();
};

