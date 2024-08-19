#pragma once

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Dealer
{
	string username, password;
public:
	Dealer()
	{
		this->username = "";
		this->password = "";
	}

	bool login()
	{
		bool logged = 0;
		string username, password;
		ifstream infile;
		infile.open("C:\\Users\\User\\Desktop\\Dealers.txt");
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

	void Restock(string abc, int xyz)
	{
		ifstream infile;
		ofstream outfile;
		infile.open("C:\\Users\\User\\Desktop\\items.txt");
		static int linecount;
		string line;
		while (!infile.eof())
		{
			getline(infile, line);
			if (line != "")
			{
				linecount++;
			}
		}
		infile.clear();
		infile.seekg(0);
		string linex;
		unsigned int curLine = 0, foundit = 0;
		while (getline(infile, linex))
		{
			curLine++;
			if (linex.find(abc, 0) != string::npos)
			{
				foundit = curLine - 1;
			}
		}
		infile.clear();
		infile.seekg(0);

		struct
		{
			string* pname = new string[linecount];
			double* pprice = new double[linecount];
			int* pqty = new int[linecount];
		} Shelf;
		for (int i = 0; i < linecount; i++)
		{
			infile >> Shelf.pname[i] >> Shelf.pprice[i];
			infile.ignore(2) >> Shelf.pqty[i];
			Shelf.pqty[foundit] = xyz;
		}
		infile.close();
		outfile.open("C:\\Users\\User\\Desktop\\items.txt", std::ofstream::out | std::ofstream::trunc);
		outfile.close();
		outfile.open("C:\\Users\\User\\Desktop\\items.txt");
		for (int i = 0;i < linecount;i++)
		{
			outfile << setw(15) << left << Shelf.pname[i] << right << setw(15) << Shelf.pprice[i] << " $" << setw(10) << Shelf.pqty[i] << endl;
		}
		linecount = 0;
		outfile.close();

	}

	void Remove(string abc)
	{
		ifstream infile;
		ofstream outfile;
		infile.open("C:\\Users\\User\\Desktop\\items.txt");
		static int linecount;
		string line;
		while (!infile.eof())
		{
			getline(infile, line);
			if (line != "")
			{
				linecount++;
			}
		}
		infile.clear();
		infile.seekg(0);
		string linex;
		unsigned int curLine = 0, foundit = 0;
		while (getline(infile, linex))
		{
			curLine++;
			if (linex.find(abc, 0) != string::npos)
			{
				foundit = curLine - 1;
			}
		}
		infile.clear();
		infile.seekg(0);

		struct
		{
			string* pname = new string[linecount];
			double* pprice = new double[linecount];
			int* pqty = new int[linecount];
		} Shelf;
		for (int i = 0; i < linecount; i++)
		{
			infile >> Shelf.pname[i] >> Shelf.pprice[i];
			infile.ignore(2) >> Shelf.pqty[i];
			Shelf.pname[foundit] = "(Removed)";
			Shelf.pprice[foundit] = 0;
			Shelf.pqty[foundit] = 0;
		}
		infile.close();
		outfile.open("C:\\Users\\User\\Desktop\\items.txt", std::ofstream::out | std::ofstream::trunc);
		outfile.close();
		outfile.open("C:\\Users\\User\\Desktop\\items.txt");
		for (int i = 0;i < linecount;i++)
		{
			if (Shelf.pname[i] != "(Removed)")
			{
				outfile << setw(15) << left << Shelf.pname[i] << right << setw(15) << Shelf.pprice[i] << " $" << setw(10) << Shelf.pqty[i] << endl;
			}
		}
		linecount = 0;
		outfile.close();
	}

	void Add(string a, double b, int c)
	{
		ifstream infile;
		ofstream outfile;
		infile.open("C:\\Users\\User\\Desktop\\items.txt");
		static int linecount;
		string line;
		while (!infile.eof())
		{
			getline(infile, line);
			if (line != "")
			{
				linecount++;
			}
		}
		infile.clear();
		infile.seekg(0);

		struct
		{
			string* pname = new string[linecount + 1];
			double* pprice = new double[linecount + 1];
			int* pqty = new int[linecount + 1];
		} Shelf;
		for (int i = 0; i < linecount; i++)
		{
			infile >> Shelf.pname[i] >> Shelf.pprice[i];
			infile.ignore(2) >> Shelf.pqty[i];
			Shelf.pname[linecount] = a;
			Shelf.pprice[linecount] = b;
			Shelf.pqty[linecount] = c;
		}
		infile.close();
		outfile.open("C:\\Users\\User\\Desktop\\items.txt", std::ofstream::out | std::ofstream::trunc);
		outfile.close();
		outfile.open("C:\\Users\\User\\Desktop\\items.txt");
		for (int i = 0;i < linecount + 1;i++)
		{
			if (Shelf.pname[i] != "(Removed)")
			{
				outfile << setw(15) << left << Shelf.pname[i] << right << setw(15) << Shelf.pprice[i] << " $" << setw(10) << Shelf.pqty[i] << endl;
			}
		}
		linecount = 0;
		outfile.close();
	}

};