#include<iostream>
#include<fstream>
#include<iomanip>
#include"Balance.h"
#include"Sav_balance.h"
using namespace std;

int main()
{
	intro(); //Group members intro
    FirstMenu:
	bal ac; // current account class object
	sav_acct acc; // saving account class object
	char ch;
	int num, numr;
	
	do
	{
		system("CLS");
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
		cout << "\n\t\t\t\t======================\n";

		cout << "\n\n\t\t\t\t****************" << endl;
		cout << "\n\t\t\t\t1)ACCOUNT INFO" << endl;
		cout << "\n\t\t\t\t2)Current Account BALANCE INFO" << endl;
		cout << "\n\t\t\t\t3)Saving Account BALANCE INFO" << endl;
		cout << "\n\t\t\t\t4)Exit" << endl;
		cout << "\n\n\t\t\t\t****************" << endl;
		cout << "\n\n\t\t\t\tSelect Your Option (1-4): ";
		cin >> ch;
		
		switch (ch) {
			char c;

		case '1':
			
			//ACCOUNT INFO
			do {
				cout << "\n\n\t\t\t\tLOGIN" << endl;
				
				ac.controlpanel();
				cout << "\n\n\t\t\t\tSelect Your Option (1-5): ";
				cin >> c;
				switch (c) {
				case '1':
					ac.write_account();

					break;
				case '2':
					ac.display_all();

					break;
				case '3':
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
					ac.delete_account(num);
					break;
				case '4':
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
					ac.modify_account(num);
					break;
				case '5':
					system("CLS");
					goto FirstMenu;

				default:cout << "\n\nINVALID CHOICE\n";
				}
				cin.ignore();
				cin.get();
			} while (c != '5');
			break;

		case '2':
			// Current Acount BALANCE INFO
			char s;

			do {
				ac.menu();
				cout << "\n\n\t\t\t\tSelect Your Option (1-4): ";
				cin >> s;
				switch (s) {

				case '1':
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
					deposit(num);
					break;
				case '2':
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
					wdraw(num);
					break;
				case '3':
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
					ac.display_sp(num);
					break;
				case '4':
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
					Transactionview(num);
					break;
				case '5':
					system("CLS");
					goto FirstMenu;

				default:cout << "\n\nINVALID CHOICE\n";
				}
				cin.ignore();
				cin.get();

			} while (s != '5');

			break;



			//Saving Aco
		case '3':
			char b;
			do {
				acc.menus();
				cout << "\n\n\t\t\t\tSelect Your Option (1-4): ";
				cin >> b;
				switch (b) {

				case '1':
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
					savdeposit(num);
					break;
				case '2':
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> numr;
					savwdraw(numr);
					break;
				case '3':
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
					acc.display_sp(num);
					break;
				case '4':
				
					system("CLS");
					cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
					Transactionview(num);
					break;
				case '5':
					system("CLS");
					goto FirstMenu;

				default:cout << "\n\nINVALID CHOICE\n";
				}
				cin.ignore();
				cin.get();

			} while (b != '5');

			break;



		case '4':
			system("CLS");
			exit(0);

		default:cout << "\n\nINVALID CHOICE\n";
		}
		cin.ignore();
		cin.get();
	} while (ch != '4');
	return 0;
}
