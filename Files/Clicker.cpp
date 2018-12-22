#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "Registration.h"
#include "Game.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Registration registr;
	Game game;

	game.run();

	_getch();

    return 0;
}
