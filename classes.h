#include <iostream>
#include <string>
#include "functions.h"
#include<ctime> 
using namespace std;
class login
{
	private:
		string pass;
   		string user;
   		char data;
   		string role;
   	public:
   		login();
   		void log();
};

login::login()
{
	this->user = "";
	this->pass = "";
}
void login::log()
{
	time_t t;
	struct tm * tt;
	time (&t);
	tt = localtime(&t);
	
   	gotoxy(48,16);	
	cout << " $User>> ";
	gotoxy(57,16);
   	cin >> this->user;
   	gotoxy(49,20);
   	cout << "$password>> ";
   	this->data = _getch();
	while(this->data != 13) // 13 means enter touch in keyboard
	{
		this->pass.push_back(data); // pass += ch
		cout << "*";
		this->data = _getch();
	}
	Load();
	if(this->user == "emsi" && pass == "emsi2022")
	{
		this->role = "Adminstrateur";
		system("cls");
		BankArt(40,2); 
   		rect(114,30,7,12);
		rect(34,2,84,13);
		gotoxy(86,14);
		cout << "Date : " << asctime(tt); 
		rect(34,2,84,17);
		gotoxy(86,18);
		cout << "Role : " << this->role;
		mylist();
	} 
	else if(this->user == "123" && pass == "123")
	{
		this->role = "Directeur";
		system("cls");
		BankArt(40,2); 
   		rect(114,30,7,12);
		rect(34,2,84,13);
		gotoxy(86,14);
		cout << "Date : " << asctime(tt); 
		rect(34,2,84,17);
		gotoxy(86,18);
		cout << "Role : " << this->role;
	}
	else
	{
		exit(0);
	}
   	return;
}

