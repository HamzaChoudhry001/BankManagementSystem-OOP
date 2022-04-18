#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Account.h"
using namespace std;


//Current BALANCE INFO CLASS
class bal : public account {
public:
	void dep(); // function to desposit amount for given account
	void Withdraw(); // function to withdraw amount for given account
	void menu(); // For Menu
};

// For Menu
void bal::menu() {
	system("CLS");
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\t CURRENT ACCOUNT";
	cout << "\n\t\t\t\t======================\n";
	cout << "\n\t\t\t\t1. DEPOSIT AMOUNT";
	cout << "\n\t\t\t\t2. WITHDRAW AMOUNT";
	cout << "\n\t\t\t\t3. BALANCE ENQUIRY";
	cout << "\n\t\t\t\t4. Transaction History";
	cout << "\n\t\t\t\t5. Back To Menu";
}


// function to desposit amount for given account
void bal::dep()
{

	float x;
	ofstream tr_write("transec.txt", ios::out | ios::app);
	cout << "\nEnter amount to Deposit :  ";
	cin >> x;
	balance = balance + x;
	cout << "\nAfter Deposit your Balance revels : " << balance;
	tr_write << acno << " " << x << " " << "CR" << endl;
}


// function to withdraw amount for given account
void bal::Withdraw()
{
	bool found = false;
	float withdraw, tax, d;

	// cout<<"\n\nBalance :- "<<deposit;
	bal ac;
	ofstream tr_write("transec.txt", ios::out | ios::app);
	cout << "\nEnter amount to be withdraw : ";
	cin >> withdraw;
	
	if (withdraw > 50000 && balance > 50000)
	{
		balance = balance - withdraw;
		cout << "\n\nTax deduction if(withdraw amount > 50000)\n";
		tax = (withdraw - 50000) / 100;
		balance = balance - tax;
	}
	else if (withdraw <= 0) {
		cout << "Insufficient Balance ";
		balance = balance + withdraw;
	}
	else if (withdraw > balance) {

		balance = balance + withdraw;
	}
	else
		balance = balance - withdraw;
		cout << "\nAfter Withdrawl your Balance revels : " << balance;
	tr_write << acno << " " << withdraw << " " << "DR" << endl;
}

void deposit(int);
void wdraw(int);
void deposit(int n)
{
	bool found = false;
	bal ac;
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
			if (ac.rettype() == 'C' || ac.rettype() == 'c') {
				ac.show_account();
				ac.dep();
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

void wdraw(int m) {
	bool found = false;
	bal ac;
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
			if (ac.rettype() == 'C' || ac.rettype() == 'c') {
				ac.show_account();
				ac.Withdraw();

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
