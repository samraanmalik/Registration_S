// Registration_S.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

class Admin
{
private:
	string name = "\0";
	long long int phone_no;
	int ID;
	string address = "\0";
	
public:
	Admin():phone_no(0),ID(0)
	{
		//default constructor//
		

	}


	void enterData()
	{
		cout << "Enter Name of Admin:-   " << endl;
		cin >> name;
	
		cout << "\nEnter Phone_Number(11 digits):-   " << endl;
		cin >> phone_no;

	    
		cout << "\nEnter Authenticate ID(2 to 4 digits):-   " << endl;
		cin >> ID;
		cin.ignore();
		cout << "\nEnter Address of Admin:-  " << endl;
		getline(cin, address);

		return;
	}

	string getAllData()
	{
		cout << "Admin Name is" << endl;
		cout << name;
		cout << "Phone No is:-  " << endl;
		stringstream ss;
		ss << phone_no;
		string store = ss.str();
		cout << store;

		cout << "ID number is:-   " << endl;
		stringstream s2;
		s2 << ID;
		string store1 = s2.str();
		cout << store1;

		cout << "Address of Admin is:-  " << endl;
		return address;
		
	}

	void storeAllData()
	{
		fstream fout("Admin's Data.dat", ios::app | ios::binary);
		if (!fout.good())
		{
			cout << "FILE could not be opened!!" << endl;
			
		}
		if (!fout.eof())
		{
			fout << "************ADMIN'S ACCOUNT*************" << endl;
			fout << "ADMIN'S NAME:-   " << name << endl;
			fout << "ADMIN'S PHONE_NO:-  " << phone_no << endl;
			fout << "ADMIN'S ID:- " << ID << endl;
			fout << "ADMIN'S ADDRESS:-  " << address << endl;
			
		}
		fout.close();

	}
	
	~Admin()
	{
		//destructor//
	}
};

class Client
{
private:
	string name = "\0";
	long long int phone_no;
	int ID;
	string address = "\0";
	int CNIC[13] = {};
	string pass_code[8] = {};
	string user_name = "\0";
public:
	Client() :phone_no(0), ID(0)
	{
		//default constructor//


	}


	void enterData()
	{
		cout << "Enter Name of Client:-   " << endl;
		getline(cin, name);

		cout << "\nEnter Phone_Number:-   " << endl;
		cin >> phone_no;

		cout << "\nEnter Authenticate ID:-   " << endl;
		cin >> ID;
		cin.ignore();
		cout << "\nEnter Address of Client:-  " << endl;
		cin >> address;
		cout << "\nEnter CNIC" << endl;
		for (int i = 0; i < 13; i++)
		{
			cin >> CNIC[i];
		}
		return;
	}

	string getAllData()
	{
		cout << "Client Name is:-  " << endl;
		cout<< name;

		cout << "\nPhone number:- " << endl;
		stringstream ss;
		ss << phone_no;
		string store = ss.str();
		cout<<store;

		cout << "ID number is:-   " << endl;
		stringstream s2;
		s2 << ID;
		string store1 = s2.str();
		cout<< store1;
		
		cout << "Address of Client is:-  " << endl;
		cout<< address;

	
		return "1";
	}

	void storeAllData()
	{
		fstream fout("Client's Data.dat", ios::app | ios::binary);
		if (!fout.good())
		{
			cout << "FILE could not be opened!!" << endl;
			
		}
		if (!fout.eof())
		{
			fout << "************CLIENT'S ACCOUNT*************" << endl;
			fout << "CLIENT'S NAME:-   " << name << endl;
			fout << "CLIENT'S PHONE_NO:-  " << phone_no << endl;
			fout << "CLIENT'S ID:- " << ID << endl;
			fout << "CLIENT'S ADDRESS:-  " << address << endl;
			for (int i = 0; i < 13; i++)
			{
				fout.write((char*)&CNIC, sizeof(Client));
		   }
		}
		fout.close();
	    
		for (int i = 0; i < 13; i++)
		{
			cout << CNIC[i] << endl;
		}
	}

	
	
	void storeLoginInfo()
	{
		fstream fout("Client's Login.dat", ios::app | ios::binary);
		if (!fout)
		{
			cerr << "FILE COULD NOT BE OPENED" << endl;
		}
		else {

		}

	}
	~Client()
	{
		//destructor//
	}



};

class Registration
{
private:
	Admin admin;
	Client client;
	char pass_code1[8] = {};
	string user_name1 = "\0";

	char pass_code2[8] = {};
	string user_name2 = "\0";
public:
	Registration() :admin(),client()
	{
		//default constructor//

	}


	void createAccount()
	{
		cout << "****************************~~~~~~~~~~~WELCOME TO REGISTRATION~~~~~~~~~~~~~**********************\n\n" << endl;
		cout << "************ENTER ACCOUNT FOR ADMIN( ~~~CREDENTIALS REQUIRED~~~~~)******************" << endl;

		cout << "\n\n";
	
		admin.enterData();
		cout << endl;
		cout<<admin.getAllData();
		admin.storeAllData();
		cout << "*******************ENTER REGISTRATION MANUAL FOR CLIENT*****************" << endl;
		cout << "\n\n";
		
		client.enterData();
		cout << endl;
		cout<<client.getAllData();
		client.storeAllData();
		

	}

	void setPassCodeForAdmin(char* password)
	{
		for (int i = 0; i < 8; i++)
		{
			pass_code1[i] = password[i];
		}
	}
	void setUserForAdmin(string username)
	{
		user_name1 = username;
	}

	
	void setPassForClient(char* pass)
	{
		for (int i = 0; i < 8; i++)
		{
			pass_code2[i] = pass[i];
		}
	}
	void setUser(string username)
	{
		user_name2 = username;
	}
	void storeLoginForAdmin()
	{
		fstream fout("Admin's Login.dat", ios::app | ios::binary);
		if (!fout.good())
		{
			cout << "FILE COULD NOT BE OPENED" << endl;
		}
		else {
			for (int i = 0; i < 8; i++)
			{
				fout.write((char*)&pass_code1[i], sizeof(Registration));
			}
			fout.write((char*)&user_name1, sizeof(Registration));
			fout.close();
		}
		for (int i = 0; i < 8; i++)
		{
			cout << pass_code1[i] << endl;
		}
		cout << user_name1;

	}

	void storeLoginForClient()
	{
		fstream fout("Client's Login.dat", ios::app|ios::binary);
		if (!fout.good())
		{
			cout << "FILE COULD NOT BE OPENED" << endl;
		}
		else {
			for (int i = 0; i < 8; i++)
			{
				fout.write((char*)&pass_code2[i], sizeof(Registration));
			}
			fout.write((char*)&user_name2, sizeof(Registration));
			fout.close();
		}
		for (int i = 0; i < 8; i++)
		{
			cout << pass_code2[i] << endl;
		}
		cout << user_name2;

	}
	bool loginSystem(char*pass_code,string user_name)
	{
		int count = 0;
		for (int i = 0; i < 8; i++)
		{
			if (pass_code1[i] != pass_code[i])
			{
				count = count + 1;
			}
			
		}
		if (count > 0)
		{
			cout << "WRONG PASSWORD!!" << endl;
			return false;
		}
		else {
			return true;
		}
		

		if (user_name1 != user_name)
		{
			cout << "INVALID USERNAME!!" << endl;
			return false;
		}
		else {
			return true;
		}
	}

	void reset(const char*fileName,char*password,char* passcode)
	{
		fileName = "Admin's Login.dat";
		fstream myFile("Admin's Login.dat", ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		for (int i = 0; i < 8; i++) {
			if (myFile.read((char*)&pass_code1[i], sizeof(Registration))) {
				if (pass_code1[i] != password[i]) {
					myFile_temp.write((char*)&pass_code1[i], sizeof(Registration));
				}
			}
		}
		myFile.close();
		myFile_temp.close();
		remove("Admin's Login.dat");
		
		fstream File("Client's Login.dat", ios::in | ios::out | ios::binary);
		ofstream myFile2_temp("temp1.bin", ios::app | ios::binary);
		for (int i = 0; i < 8; i++) {
			if (File.read((char*)&pass_code2[i], sizeof(Registration))) {
				if (pass_code2[i] != passcode[i]) {
					myFile2_temp.write((char*)&pass_code2[i], sizeof(Registration));
				}
			}
		}
		File.close();
		myFile2_temp.close();
		remove("Client's Login.dat");
		
		return;
		
	}
	~Registration()
	{

	}


};

int main()
{
	//main driver function//
	char pass_code[8] = {};
	string username = "\0";
	char pass_code1[8] = {};
	string user_name1 = "\0";
	Registration reg;
	Client client;
	Admin admin;
	reg.createAccount();
	back:
	cout << "Enter password for Admin(small letters):-  " << endl;
	for (int i = 0; i < 8; i++)
	{
		cin >> pass_code[i];

	}
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		if ((pass_code[i] >= 48 && pass_code[i] <= 57) || (pass_code[i] >= 65 && pass_code[i] <= 90) || (pass_code[i] >= 97 && pass_code[i] <= 122))
		{
			count = 0;
			continue;
		}
		else {
			count = count + 1;
			break;
		}

	}
	if (count == 0)
	{
		goto back;
	}
	else {
		for (int i = 0; i < 8; i++)
		{
			cout << pass_code[i] << "  ";
		}
	}
	start:
	cout << "\nEnter username:- " << endl;
	cin >> username;
	reg.setPassCodeForAdmin(pass_code);
	reg.setUserForAdmin(username);
	cout << "Enter password for Client(small letters):-  " << endl;
	for (int i = 0; i < 8; i++)
	{
		cin >> pass_code1[i];

	}
	 count = 0;
	for (int i = 0; i < 8; i++)
	{
	
		if ((pass_code1[i] >= 48 && pass_code1[i] <= 57) || (pass_code1[i] >= 65 && pass_code1[i] <= 90) || (pass_code1[i] >= 97 && pass_code1[i] <= 122))
		{
			count = 0;
			continue;
		}
		else {
			count = count + 1;
			break;
		}
		

	}
	if (count > 1)
	{
		goto start;
	}
	else {
		for (int i = 0; i < 8; i++)
		{
			cout << pass_code1[i] << "  ";
		}
	}
	cout << "\nEnter username for Client:- " << endl;
	cin>> user_name1;
	
	char password_1[8] = {};
	string username1 = "\0";
	cout << "\n**********************WELCOME TO LOGIN SCREEN*************************" << endl;
	cout << "ENTER PASSWORD FOR ADMIN ONLY:-  " << endl;
	for (int i = 0; i < 8; i++)
	{
		cin >> password_1[i];
	}
	cout << "Enter UserName:-  " << endl;
	cin >> username1;


	if (reg.loginSystem(password_1,username1)==1)
	{
		cout << "*******SUCCESSFULLY SINGUP************" << endl;
	}
	else {
	cout << "INCORRECT PASSWORD OR USERNAME!!" << endl;
	goto back;
		
	}

	//*************reset password**************//
	char choice = 0;
	cout << "DO YOU WANT TO RESET PASSWORD OR USERNAME( y or n):-  " << endl;
	cin >> choice;

	if (choice == 'y')
	{
		cout << "****RESETTING PASSWORD AND USERNAME OF ADMIN*****" << endl;
		reg.reset("Binaries.bin", pass_code,pass_code1);
	}
	else {
		cout << "THANKYOU!!" << endl;
	}

	return 0;


}