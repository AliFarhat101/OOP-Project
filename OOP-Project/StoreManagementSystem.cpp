#include "Customer.h"
#include "Dealer.h"
#include "Employee.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
!!NOTE: The file location needs to be changed in the code depending on the computer!! 
*/

void main()
{
	while (true)
	{
		cout << "Hello, Are you a customer?" << endl;
		bool logged;
		string answer;
		static int choice;
		cin >> answer;
		//main interface for customers**************************************
		if (answer == "yes" || answer == "Yes")
		{
			Customer C;
			cout << endl << "1)Sign in" << endl << "2)Login" << endl << "Enter any other number to go back" << endl << endl;
			do {
				cin >> choice;
				cin.clear();
				switch (choice)
				{
				case 1:
					C.signin();
					cout << "Sign in successful!" << endl;
					break;
				case 2:
					logged = C.login();
					if (logged == 1)
					{
						cout << endl << "Welcome, here's our products:" << endl;
						C.display();
						string newanswer;
						string pname;
						int pqty;
						double total = 0;
						int counter = 0;
						bool outofstock = 0;
						struct {
							string itemname[100]{ "Milk","Butter","Eggs","Cheese","Coffee","Biscuits","Juice","Yogurt","Bread","Cereal","Chips","Pancakes","Steak","Fish","Tomatoes","Beans" };
							double itemprice[100]{ 2.10,1.99,1.25,1.44,0.98,0.49,1.5,1.19,0.6,1.5,0.89,1.25,3.99,3.99,0.75,1.25 };
							int itemqty[100]{ 100,100,1000,100,500,500,500,100,1000,100,500,100,100,100,100,100 };
						}Itemlist;

						do {
							cout << endl << "Purchase a new item?" << endl;
							cin >> newanswer;
							counter++;
							if (newanswer == "yes" || newanswer == "Yes")
							{
								cout << "Enter product name and quantity:" << endl;
								cin >> pname >> pqty;
								//TRIAL START HERE
								struct {
									string pnamest[20];
									double ppricest[20];
									int pqtyst[20];
								} Productlist;

								ifstream infile;
								ofstream outfile;
								infile.open("C:\\Users\\User\\Desktop\\items.txt");
								outfile.open("C:\\Users\\User\\Desktop\\Grocery.txt", fstream::app);
								string line;
								unsigned int iscurLine = 0, iscurrline = 0;
								while (getline(infile, line))
								{
									iscurLine++;
									if (line.find(pname) != string::npos)
									{
										iscurrline = iscurLine;
									}
								}
								infile.clear();
								infile.seekg(0);
								int curLine = 0;
								while (!infile.eof())
								{
									curLine++;
									getline(infile, line);
									if (curLine == iscurrline) break;
								}
								outfile << line << endl;
								infile.clear();
								infile.seekg(0);
								infile.close();
								outfile.close();

								infile.open("C:\\Users\\User\\Desktop\\Grocery.txt");
								infile >> Productlist.pnamest[counter - 1] >> Productlist.ppricest[counter - 1];
								infile.ignore(2) >> Productlist.pqtyst[counter - 1];
								infile.close();
								infile.open("C:\\Users\\User\\Desktop\\Grocery.txt", std::ofstream::out | std::ofstream::trunc);
								infile.close();
								//function aquired item inside Productlist
								//changing quantity in struct
								for (int i = 0;i < 20;i++)
								{
									if (Itemlist.itemname[i] == Productlist.pnamest[counter - 1])
									{
										Itemlist.itemqty[i] = Itemlist.itemqty[i] - pqty;
										if (Itemlist.itemqty[i] < 0)
										{
											outofstock = 1;
										}
									}
								}
								if (outofstock == 0)
								{
									//printing struct into the file
									infile.open("C:\\Users\\User\\Desktop\\items.txt");
									static int linecount;
									for (int i = 0;i < 100;i++)
									{
										while (!infile.eof())
										{
											getline(infile, line);
											if (line != "")
											{
												linecount++;
											}
										}
									}

									infile.close();
									infile.open("C:\\Users\\User\\Desktop\\items.txt", std::ofstream::out | std::ofstream::trunc);
									infile.close();
									outfile.open("C:\\Users\\User\\Desktop\\items.txt");
									for (int i = 0; i < linecount; i++)
									{
										outfile << setw(15) << left << Itemlist.itemname[i] << setw(15) << right << Itemlist.itemprice[i] << " $" << setw(10) << Itemlist.itemqty[i] << endl;
									}
									outfile.close();
									linecount = 0;
									//TRIAL ENDS HERE
									total += (Productlist.ppricest[counter - 1] * pqty);
								}
								else
								{
									cout << endl << "Product would be out of stock" << endl;
									outofstock = 0;
								}
							}
						} while (newanswer == "yes" || newanswer == "Yes");
						cout << endl << "Thank you for shopping! Here is your total:" << endl << setw(30) << total << "$" << endl;
					}
					break;
				default:
					break;
				}
			} while (!cin);
		}
		//main interface for admins**************************************
		else if (answer == "No" || answer == "no")
		{
			Employee E;
			Dealer D;
			cout << endl << "1)Dealer Login" << endl << "2)Employee Login" << endl << "Enter any other number to go back" << endl << endl;
			do {
				cin >> choice;
				switch (choice)
				{
				case 1://############################################################################
				{logged = D.login();
				int deaanswer;
				string deasecanswer;
				if (logged == 1)
				{
					cout << endl << "Welcome, choose your action" << endl << "1)View Stock" << endl << "2)Restock" << endl << "3)Add" << endl << "4)Remove" << endl << endl;
					cin >> deaanswer;
					switch (deaanswer)
					{
					case 1:
					{
						E.display();
						cout << endl << "Do you want to restock?" << endl;
						cin >> deasecanswer;
						if (deasecanswer == "yes" || deasecanswer == "Yes");
						{
							string abc;
							int xyz;
							cout << endl << "Enter Product name and quantity to be stocked" << endl;
							cin >> abc >> xyz;
							D.Restock(abc, xyz);
						}
						break;
					}
					case 2:
					{
						string abc;
						int xyz;
						cout << endl << "Enter Product name and quantity to be stocked" << endl;
						cin >> abc >> xyz;
						D.Restock(abc, xyz);
						break;
					}
					case 3:
					{
						string A;
						double B;
						int C;
						cout << endl << "Enter the Product name, price and quantity:" << endl << endl;
						cin >> A >> B >> C;
						D.Add(A, B, C);
						cout << endl << "Item added: " << endl;
						D.display();
						break;
					}
					case 4:
					{
						string abc;
						D.display();
						cout << endl << "Enter Product name to be removed" << endl;
						cin >> abc;
						D.Remove(abc);
						break;
					}
					default:
						break;
					}
				}
				break;
				}
				case 2://############################################################################
				{logged = E.login();
				int empanswer;
				string empsecanswer;
				if (logged == 1)
				{
					cout << endl << "Welcome, choose your action" << endl << "1)View Stock" << endl << "2)Restock" << endl << endl;
					cin >> empanswer;
					switch (empanswer)
					{
					case 1:
					{
						E.display();
						cout << endl << "Do you want to restock?" << endl;
						cin >> empsecanswer;
						if (empsecanswer == "yes" || empsecanswer == "Yes")
						{
							string abc;
							int xyz;
							cout << endl << "Enter Product name and quantity to be stocked" << endl;
							cin >> abc >> xyz;
							E.Restock(abc, xyz);
						}
						break;
					}
					case 2:
					{
						string abc;
						int xyz;
						cout << endl << "Enter Product name and quantity to be stocked" << endl;
						cin >> abc >> xyz;
						E.Restock(abc, xyz);
						break;
					}
					default:
						break;
					}
				}
				break;
				}
				default:
					break;
				}
			} while (!cin);
		}
		//endp1
		cout << endl << endl << "Go Back ?" << endl;
		cin >> answer;
		if (answer == "yes" || answer == "Yes")
			system("pause");
		else break;
		cout << endl;
	}
}