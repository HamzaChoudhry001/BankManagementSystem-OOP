#pragma once
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include"Balance.h"
using namespace std;


//Account Class
class account
{
protected:
	long int acno;
	char name[50];
	long int balance, savbal;
	char type;
public:
	//Constractor
	account() {
		char name[50] = " ";
		balance = 0;
		savbal = 0;
	}
	void controlpanel(); //For ControlPanel
	void create_account(); //function to get data from user
	void show_account() const; //function to show data on screen
	void modify(); //function to Update Record
	void report() const; 
	int retacno() const; //function to return account number
	int retdeposit() const; //function to return balance amount
	char rettype() const;//function to return type of account

	void write_account(); //function to write record in file
	void display_sp(int); //function to display account details given by user
	void modify_account(int); //function to modify record of file
	void delete_account(int); //function to delete record of file
	void display_all(); //function to display all account details
};

//For ControlPanel
void account::controlpanel() {
	system("CLS");
	cout << "\t\t\t\t    ::MAIN MENU::\n";
	cout << "\n\t\t\t\t1. NEW ACCOUNT";
	cout << "\n\t\t\t\t2. ALL ACCOUNT HOLDER LIST";
	cout << "\n\t\t\t\t3. CLOSE AN ACCOUNT";
	cout << "\n\t\t\t\t4. MODIFY AN ACCOUNT";
	cout << "\n\t\t\t\t5. Back To Menu ";
}



//function to get data from user
void account::create_account()
{
	system("CLS");
	cout << "\n\t\t\tEnter the Account No. : ";
	cin >> acno;
	cout << "\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\n\t\t\tEnter Type of the Account (C/S) : ";
	cin >> type;
	if (type == 'c' || type == 'C')
	{
		cout << "\n\t\t\tEnter The Initial amount : ";
		cin >> balance;
		cout << "\n\n\t\t\tAccount Created..";
	}
	else if (type == 's' || type == 'S') {
		cout << "\n\t\t\tEnter The Initial amount : ";
		cin >> savbal;
		cout << "\n\n\t\t\tAccount Created..";
	}

}

//function to show data on screen
void account::show_account() const
{
	cout << "\n\t\t\tAccount No. : " << acno;
	cout << "\n\t\t\tAccount Holder Name : ";
	cout << name;
	cout << "\n\t\t\tType of Account : " << type;
	if (type == 'c' || type == 'C')
	{
		cout << "\n\t\t\tBalance amount : " << balance;
	}
	else if (type == 's' || type == 'S') {
		cout << "\n\t\t\tBalance amount : " << savbal;
	}
}

//function to show data on screen
void account::modify()
{
	cout << "\n\t\t\tAccount No. : " << acno;
	cout << "\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\n\t\t\tModify Account Type : ";
	cin >> type;
	if (type == 'c' || type == 'C')
	{
		cout << "\n\t\t\tEnter The Initial amount : ";
		cin >> balance;
		cout << "\n\n\t\t\tAccount Created..";
	}
	else if (type == 's' || type == 'S') {
		cout << "\n\t\t\tEnter The Initial amount : ";
		cin >> savbal;
		cout << "\n\n\t\t\tAccount Created..";
	}
}




void account::report() const
{
	cout << "\n";
	cout << "----------------------------------------------" << endl;
	cout << "Account No: \t\t\t\t" << acno << endl;
	cout << "Account Holder Name: \t\t\t" << name << setw(10) << endl;
	cout << "Type of Account : \t\t\t" << type << endl;
	if (type == 'c' || type == 'C')
	{
		cout << "Balance: \t\t\t\t" << balance << endl;
		cout << "----------------------------------------------" << endl;
	}
	else if (type == 's' || type == 'S') {
		cout << "Balance: \t\t\t\t" << savbal << endl;
		cout << "----------------------------------------------" << endl;
	}

}

//function to return account number
int account::retacno() const
{
	return acno;
}

//function to return balance amount
int account::retdeposit() const
{
	return balance;
}

//function to return type of account
char account::rettype() const
{
	return type;
}



//write record in file

void account::write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();
}

//Balance enquirey
void account::display_sp(int n)
{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\t\t\tBALANCE DETAILS\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		if (ac.retacno() == n)
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\n\t\t\tAccount number does not exist";
}



void account::modify_account(int n)
{
	bool found = false;
	account ac;
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
			ac.show_account();
			cout << "\n\n\t\t\tEnter The New Details of account" << endl;
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur); //fncallat1353
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t\t\tRecord Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n\t\t\tRecord Not Found ";
}



void account::delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		if (ac.retacno() != n)
		{
			outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\nRecord Deleted ..";
}

//Display record file handling
void account::display_all()
{
	system("CLS");
	account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//Introduction
void intro();
void intro()
{
	cout << "\n\n\t\t\t\tPROJECT" << endl;
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout << "\n\t\t\t\t======================\n";
	cout << "\n\n\t\t\t\tMADE BY ->";
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\t RollNo: 19014156-071\n";
	cout << "\t\t\t\t RollNo:  19014156-062";
	cout << "\n\t\t\t\t======================\n";
	cout << "\tPress Enter to Continue";
	cin.get();
}

void Transactionview(int);
void Transactionview(int x) {
	int number, amount, flag = 0;
	string status;
	account ac;
	ifstream tr_file_read("transec.txt", ios::in);
	cout << "\n\t" << "AccountNumber"
		<< " | " << "Amount" << " | " << "CR / DR " << endl;

	while (tr_file_read)
	{
		tr_file_read >> number;
		tr_file_read >> amount;
		tr_file_read >> status;
		if (tr_file_read.eof())
		{
			break;
		}
		if (x == number)
		{
			cout << "\t" << number << " | " << amount
				<< " | " << status << " | " << endl;
			flag = 1;
		}
	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";
	}
	tr_file_read.close();
}



