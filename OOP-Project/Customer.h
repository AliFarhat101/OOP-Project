#pragma once
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Customer
{
	string username, password;
public:
	Customer()
	{
		this->username = "";
		this->password = "";
	}

	void signin()
	{
		ifstream infile;
		ofstream outfile;
		string Fname, Lname, username, password;
		infile.open("C:\\Users\\User\\Desktop\\Customer.txt");
		outfile.open("C:\\Users\\User\\Desktop\\Customer.txt", fstream::app);
		cout << "Enter your full name" << endl;
		cin >> Fname >> Lname;
		cout << "Enter your username" << endl;
		cin >> username;
		string line;
		unsigned int curLine = 0;
		while (getline(infile, line))
		{
			curLine++;
			if (line.find(username, 0) != string::npos)
			{
				cout << endl << "!Username already used!" << endl << endl;
			}
		}
		cout << "Enter your password" << endl;
		cin >> password;
		outfile << fixed << showpoint << setw(10) << left << Fname << setw(10) << Lname << right << setw(30) << username << " " << password << endl;

		infile.close();
		outfile.close();

	}

	bool login()
	{
		bool logged = 0;
		string username, password;
		ifstream infile;
		infile.open("C:\\Users\\User\\Desktop\\Customer.txt");
		cout << "Enter your username" << endl;
		cin >> username;
		cout << "Enter your password" << endl;
		cin >> password;
		string line, ispass;
		int passk;
		unsigned int curLine = 0;
		while (getline(infile, line))
		{
			curLine++;
			if (line.find(username, 0) != string::npos)
			{
				passk = line.find(username);
				ispass = line.substr(passk + username.length() + 1, string::npos);
				if (ispass == password)
				{
					cout << "Login successful!" << endl;
					logged = 1;
					system("color 2");
					system("pause");
					system("color 7");
				}
				else
				{
					cout << "Wrong password" << endl;
					logged = 0;
					system("color 4");
					system("pause");
					system("color 7");

				}
				break;
			}
			else
			{
				cout << "Username not found. Try signing in" << endl;
				break;
			}
		}
		infile.close();
		this->username = username;
		this->password = password;
		return logged;
	}

	void display() const
	{
		ifstream infile;
		infile.open("C:\\Users\\User\\Desktop\\items.txt");
		string line;
		unsigned int curLine = 0;
		while (getline(infile, line))
		{
			curLine++;
			cout << line << endl;
		}
		infile.close();
	}
};