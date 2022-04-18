#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Account.h"
using namespace std;


// Saving Account Class
class sav_acct : public account
{


public:
	void deposit_savbal(); // function to desposit amount for SAVING account
	void withdraw_savbal(); // function to withdraw amount for given SAVING account
	void menus(); // For menu
};
// For menu
void sav_acct::menus() {
	system("CLS");
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\t  Saving ACCOUNT";
	cout << "\n\t\t\t\t======================\n";
	cout << "\n\t\t\t\t1. DEPOSIT AMOUNT";
	cout << "\n\t\t\t\t2. WITHDRAW AMOUNT";
	cout << "\n\t\t\t\t3. BALANCE ENQUIRY";
	cout << "\n\t\t\t\t4. Transaction History";
	cout << "\n\t\t\t\t5. Back To Menu";
}


// function to desposit amount for SAVING account
void sav_acct::deposit_savbal() {

	float deposit, interest;
	ofstream tr_write("transec.txt", ios::out | ios::app); // for transaction history
	cout << "\nEnter amount to Deposit :- ";
	cin >> deposit;
	savbal = savbal + deposit;
	interest = (savbal * 2) / 100;
	savbal = savbal + interest;
	tr_write << acno << " " << deposit << " " << "Deposit" << endl;

}


// function to withdraw amount for given SAVING account
void sav_acct::withdraw_savbal() {
	float withdraw;
	sav_acct ac;
	ofstream tr_write("transec.txt", ios::out | ios::app);
	//cout<<"\nBalance :- "<<savbal;
	cout << "\nEnter amount to be withdraw :-";
	cin >> withdraw;
	savbal = savbal - withdraw;
	if (withdraw > savbal)
	{
		cout << "\n\nYou have to take permission for Bank Overdraft Facility\n";
		savbal = savbal + withdraw;
	}
	else
		cout << "\nAfter Withdrawl your Balance revels : " << savbal;

	tr_write << acno << " " << withdraw << " " << "Withdraw" << endl;
}

void savdeposit(int);
void savwdraw(int);

void savdeposit(int n)
{
	bool found = false;
	sav_acct ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			if (ac.rettype() == 's' || ac.rettype() == 'S') {
				ac.show_account();
				ac.deposit_savbal();
				int pos = (-1) * static_cast<int>(sizeof(ac));
				File.seekp(pos, ios::cur);//fn1353
				File.write(reinterpret_cast<char*> (&ac), sizeof(account));
				cout << "\n\n\t\t\tRecord Updated";
				found = true;
			}
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n\t\t\tRecord Not Found ";
}

void savwdraw(int m) {
	bool found = false;
	sav_acct ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retacno() == m)
		{
			if (ac.rettype() == 's' || ac.rettype() == 'S') {
				ac.show_account();
				ac.withdraw_savbal();

				int pos = (-1) * static_cast<int>(sizeof(ac));
				File.seekp(pos, ios::cur);//fn1353
				File.write(reinterpret_cast<char*> (&ac), sizeof(account));
				cout << "\n\n\t\t\tRecord Updated";
				found = true;
			}
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n\t\t\tRecord Not Found ";

}


