#include<iostream>
#include<fstream>
#include<string.h>
//#include <cstdlib>
using namespace std;
//<< dosyadan al >> dosyaya yaz

void login();
void registration();
void forgot();

int main() {

	int c;
	cout << "\t\t\t___________________________________________________\n\n\n";
	cout << "\t\t\t                welcome to login page              \n\n\n";
	cout << "\t\t\t________________        Menu         _______________\n\n\n";
	cout << "                                                             \n\n";
	cout << "\t| Press 1 to LOGIN                             |" << endl;
	cout << "\t| Press 2 to REGISTER                          |" << endl;
	cout << "\t| Press 3 if you forgot your PASSWORD          |" << endl;
	cout << "\t| Press 4 to EXÝT                              |" << endl;
	cout << "\n\t\t\t Please enter your choice : ";
	cin >> c;

	switch (c) 
	{
	case 1:
		login();
		break;
	case 2:
		registration();
		break;
	case 3:
		forgot();
		break;
	case 4:
		cout << "\t\t\t Thankyou ! \n\n";
		break;
	default:
		system("cls");
		cout << "\t\t\t Please select from the options given above \n";
		main();
	}


}
void login() {

	int count=0;
	string userId, password, id, pass;
	system("cls");
	cout << "\t\t\t Please enter the username and password : ";
	cout << "USERNAME : ";
	cin >> userId;
	cout << "PASSWORD : ";
	cin >> password;

	ifstream input("records.txt");

		while (input >> id >> pass)
		{
			if (id == userId && pass == password)
			{
				count = 1;
				system("cls");
			}
		}
		input.close();
		if (count == 1)
		{
			cout << userId << "\n Your LOGÝN is successful\n Thanks for logging in. \n";
			main();
		}
		else
		{
			cout << "\n LOGIN ERROR \n  Please check your username and password \n";
		}
}
void registration() 
{
	string ruserId, rpassword, rid, rpass;
	system("cls");
	cout << "\t\t\t Enter the username : ";
	cin >> ruserId;
	cout << "\t\t\t Enter the password : ";
	cin >> rpassword;

	ofstream f1("records.txt", ios::app);

	f1 << ruserId << ' ' << rpassword << endl;
	system("cls");
	cout << "\n\t\t\t Registration is successfull \n";
	main();
}
void forgot() {
	int option;
	system("cls");
	cout << "\t\t\t You forgot the password? no worries \n";
	cout << "Press 1 to search your id by username " << endl;
	cout << "Press 2 to go back to the main menu " << endl;
	cout << "*t\t\t Enter your choice : ";
	cin >> option;

	switch (option)
	{
	case 1:
		int count;
		string suserId, sId, spass;
		cout << "\n\t\t Enter the username which you remembred";
		cin >> suserId;
		fstream f2("records.txt");
		while (f2 >> sId >> spass)
		{
			if (sId == suserId)
			{
				count = 1;

			}
		}
		f2.close();
		if (count == 1)
		{
			cout << "\n\n Your accound is found ! \n";
			cout << "\n\n Your password is : " << spass;
			forgot();
		}
		else
		{
			cout << "\t\n Sorry! your account is not found!!! \n";
		}
		break;
	case 2:
		main();
		break;
	default:
		cout << "\t\t\t Wrong choice !! Please  try again " << endl;
		forgot();
	}
	
}