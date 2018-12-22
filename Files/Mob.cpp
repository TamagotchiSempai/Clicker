#include "stdafx.h"
#include "Mob.h"


Mob::Mob()
{
	hp = 10;
	count = 1;
}

void Mob::refreshHp()
{
	hp = 10 * (1.2 * count) + (0.5 * (count + (count + 2 * 1.5)));
}

void Mob::chek()
{
	if (hp <= 0)
	{
		refreshHp();
		count++;
	}
}

Mob::~Mob()
{
}
