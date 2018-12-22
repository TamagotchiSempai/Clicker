#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}


void Game::interface()
{
	cout << endl << "Gold:   " << Gold << endl;
	cout << "Attack: " << Attack << endl;
	cout << "Count:  " << count << endl;
	cout << endl << endl << "\t\t\t\t hp[mob(" << count << ")] = " << hp << endl;
	cout << "Please select an action: ";
}

int Game::attack(int Attack, int hp)
{
	hp -= Attack;
	Gold += count;
	return hp;
}

void Game::run()
{
	while (count <= 1000)
	{
		system("cls");
		interface();
		cin >> select;
		switch (select)
		{
		case 1:
		{
			hp = attack(Attack, hp);
			chek();
			break;
		}
		case 2:
		{
			system("cls");
			shopInterface();
			cout << "Please select an action: ";
			cin >> select;
			switch (select)
			{
			case 1:
			{
				buyAttack();
				break;
			}
			default:
				cout << "Error.";
			}
			break;
		}
		default:
			cout << "Error.";
		}
	}
}

Game::~Game()
{
}
