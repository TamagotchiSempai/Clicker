#include "stdafx.h"
#include "Registration.h"


Registration::Registration()
{
	chek();
}


Registration::~Registration()
{
}

void Registration::registration()
{
	cout << "Enter Login:  ";
	cin >> Login;
	cout << "\nEnter Password: ";
	cin >> Password;
	cout << "\nEnter Nickname: ";
	cin >> Nickname;
	record(Nickname, Password, Nickname);
	finish(accountCreate);
}

void Registration::record(string Login, string Password, string Nickname)
{
	Player.open("Player.txt", fstream::in | fstream::out | fstream::app);
	if (!Player.is_open())
	{
		cout << "Error.";
	}

	else

	{
		accountCreate = true;
		//Player << Login << ":" << Password << endl;
		Player << accountCreate << "\t\t\t// 0 - не зарегистрирован / 1 - зарегистрирован / 2 - гм / 3 - админка.\nLogin: " << Login << "\nPassword: " << Password << "\nNickname: " << Nickname << endl;
	}

	Player.close();
}

void Registration::finish(bool accountCreate)
{
	accountCreate = true;
	return;
}

void Registration::chek()
{

	load();

	if (accountCreate == 1 && status !=0)
	{
		return;
	}

	else

	{
		cout << "Аккаунт не зарегистрирован. Хотите его создать? (y/n) ";
		selectt:
		
		cin >> select;

		switch (select)
		{
		case 'y':
		case 'Y':
		{
			registration();
			break;
		}

		case 'n':
		case 'N':
		{
			cout << "Без аккаунта нет возможности продолжать игру.";
			break;
		}
		default:
			cout << "Не правильный символ. Введите заново: ";
			goto selectt;
			break;
		}
	}	
}

void Registration::load()
{
	fstream file;
	file.open("Player.txt", fstream::in | fstream::out | fstream::app);
	if (!file.is_open())
	{
		cout << "Error.";
	}

	else

	{
		long file_size;
		file.seekg(0, ios::end);
		file_size = file.tellg();
		if (file_size == 0)
		{
			file.close();
			return;
		}

		else
		{
			Status();
			switch (status)
			{

			case 0:
			{
				accountCreate = false;
				break;
			}
			
			case 1:
			{
				accountCreate = 1;
				status = 1;
				file.close();
				break;
			}

			case 2:
			{
				accountCreate = 1;
				status = 2;
				break;
			}

			case 3:
			{
				accountCreate = 1;
				status = 3;
				break;
			}

			case 4:
			{
				accountCreate = 1;
				status = 4;
				break;
			}

			case 5:
			{
				accountCreate = 1;
				status = 5;
				cout << "Ваш аккаунт заблокирован.";
				break;
			}
			default:
				accountCreate = 1;
				status = 404;
				cout << "Ошибка";
				break;
			}
		}
		/*{
			int temp;
			file >> temp;
			if (temp == 1)
			{
				cout << "temp = 1";
				accountCreate = true;
				file.close();
				return;
			}

			else if (temp == 0)

			{
				cout << "temp = 0";
				file.close();
				return;
			}
		}*/
	}
}

void Registration::Status()
{
	fstream file;
	file.open("Player.txt", fstream::in | fstream::out | fstream::app);

	if(!file.is_open())
	{
		cout << "Error.";
	}

	else

	{
		int temp;
		file >> temp;
		if (temp == 1)
		{
			status = 1;
		}
		else if (temp == 0)
		{
			status = 0;
		}

		else if (temp == 2)
		{
			status = 2;
		}
		else if (temp == 3)
		{
			status = 3;
		}
		else if (temp == 4)
		{
			status = 4;
		}
		else if (temp == 5)
		{
			status = 5;
		}
		else status = 404;
	}
}