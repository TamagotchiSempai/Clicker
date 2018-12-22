#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Registration
{
public:
	Registration();

	void registration();
	void record(string Login, string Password, string Nickname);
	void finish(bool accountCreate);
	void chek();
	void load();
	void Status();

	~Registration();

	fstream Player;
	string Login;
	string Password;
	string Nickname;
	bool accountCreate = 0;
	char select;
	int status;
};

