#pragma once
#include "Player.h"
#include "Mob.h"
#include <iostream>

using namespace std;

class shop : public Player, public Mob
{
protected:
    int prise;
public:
	shop();
	void refreshPrise();
	void shopInterface();
	void buyAttack();
	~shop();
};

