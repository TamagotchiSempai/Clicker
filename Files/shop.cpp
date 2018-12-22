#include "stdafx.h"
#include "shop.h"

shop::shop()
{
	prise = count * (hp / Attack + (Attack * (count + hp)));
}

void shop::refreshPrise()
{
	prise = count * (hp / Attack + (Attack * (count + hp)));
}

void shop::shopInterface()
{
	cout << "Gold: " << Gold << endl;
	cout << "Attack: " << Attack << endl << endl;
	cout << "1: Attack + 1 = " << prise << " gold." << endl;
}

void shop::buyAttack()
{
	if (Gold >= prise)
	{
		Gold -= prise;
		Attack++;
		refreshPrise();
	}
	else cout << "Error. Not enough money.";
}

shop::~shop()
{
}
