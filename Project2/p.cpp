#include "header.h"

using namespace std;

void person::inputinfo()
{
	const char* incorrectphone = "INCORRECT PHONE NUMBER FORMAT\n";
	cout << "\nenter first name: ";
	cin >> firstname;
	cout << "enter surname: ";
	cin >> surname;
	bool correct = true;
	do {
		correct = true;
		cout << "enter phone number: ";
		cin >> phonenumber;
		int len = strlen(phonenumber);
		if (len != 12)
		{
			cout << incorrectphone;
			correct = false;
			continue;
		}
		for (int i = 0; i < len; i++)
		{
			switch (i)
			{
			case 0:
				if (phonenumber[i] == '(')
				{
					continue;
				}
				else
				{
					cout << incorrectphone;
					correct = false;
					i = len;
				}
			case 4:
				if (phonenumber[i] == ')')
				{
					continue;
				}
				else
				{
					cout << incorrectphone;
					correct = false;
					i = len;
				}
			default:
				if (int(phonenumber[i]) >= 48 && int(phonenumber[i]) <= 57)
				{
					continue;
				}
				else
				{
					cout << incorrectphone;
					correct = false;
					i = len;
				}
			}
		}

	} while (correct == false);
	cout << "enter salary: ";
	cin >> salary;
	cout << endl;
}
void person::print()
{
	cout << "\nfist name: " << firstname << endl;
	cout << "surnname: " << surname << endl;
	cout << "phone number: " << phonenumber << endl;
	cout << "salary: $" << salary << "\n\n";
}

person book[50];
int personcounter = 0;
int action;

void addperson()
{
	book[personcounter].inputinfo();
	personcounter++;
	system("CLS");
	return;
}

void removeperson()
{
	if (personcounter == 0)
	{
		cout << "\nTHE BOOK IS EMPTY\n";
		return;
	}
	cout << "\nselect the person you want to remove:\n";
	for (int i = 0; i < personcounter; i++)
	{
		cout << "[" << i + 1 << "]" << book[i].firstname << " " << book[i].surname << endl;
	}
	int n;
	while (true) {
		cin >> n;
		if (n >= 1 && n <= personcounter)
			return;
		cout << "\nINCORRECT NUMBER\n";
		cout << "select the person you want to remove:\n";
	}
	bool confirm;
	cout << "\nenter 1 to confirm, 0 to cancel: ";
	cin >> confirm;
	if (confirm == 0)
	{
		return;
	}
	for (int i = n; i < personcounter; i++)
	{
		book[n - 1] = book[n];
	}
	personcounter--;
	system("CLS");
	return;
}

void printbook()
{
	if (personcounter == 0)
	{
		errormsgempty();
		return;
	}
	for (int i = 0; i < personcounter; i++)
	{
		book[i].print();
	}
	system("pause");
	system("CLS");
	return;
}

void salarysearch()
{
	if (personcounter == 0)
	{
		errormsgempty();
		return;
	}
	double min = 0;
	double max = 0;
	cout << "\nEnter minimum salary: ";
	cin >> min;
	cout << "Enter maximum salary: ";
	cin >> max;
	for (int i = 0; i < personcounter; i++)
	{
		if (book[i].salary >= min && book[i].salary <= max)
		{
			book[i].print();
		}
	}
	system("pause");
	system("CLS");
	return;
}

void surnamesearch()
{
	if (personcounter == 0)
	{
		errormsgempty();
		return;
	}
	char* surname{ new char[100] };
	cout << "\nEnter surname: ";
	cin >> surname;
	for (int i = 0; i < personcounter; i++)
	{
		if (book[i].surname == surname)
		{
			book[i].print();
		}
	}
	system("CLS");
	return;
}

void savefile()
{
	ofstream out;
	out.open("book.txt");
	if (out.is_open())
	{
		for (int i = 0; i < personcounter; i++)
		{
			out << book[i].firstname << endl;
			out << book[i].surname << endl;
			out << book[i].phonenumber << endl;
			out << book[i].salary << endl;
		}
	}
	out.close();
	system("CLS");
	return;
}

void loadfile()
{
	string line1, line2, line3, line4;
	personcounter = 0;
	ifstream in("book.txt");
	if (in.is_open())
	{

		while (getline(in, line1) && getline(in, line2) && getline(in, line3) && getline(in, line4))
		{
			strcpy_s(book[personcounter].firstname, 100, line1.c_str());
			strcpy_s(book[personcounter].surname, 100, line2.c_str());
			strcpy_s(book[personcounter].phonenumber, 100, line3.c_str());
			book[personcounter].salary = stod(line4);
			personcounter++;
		}
	}
	in.close();
	system("CLS");
	return;
}

void asort() {
	for (int pass = 0; pass < personcounter - 1; pass++) {
		for (int j = 0; j < personcounter - pass - 1; j++) {
			int i = 0;
			while (book[j].surname[i] != '\0' && book[j + 1].surname[i] != '\0' && book[j].surname[i] == book[j + 1].surname[i]) {
				i++;
			}
			if (book[j].surname[i] > book[j + 1].surname[i]) {
				person temp = book[j + 1];
				book[j + 1] = book[j];
				book[j] = temp;
			}
		}
	}
	printbook();
}
void printmenu()
{
	cout << "[1] - add person\n";
	cout << "[2] - remove person\n";
	cout << "[3] - print\n";
	cout << "[4] - sort alphabetically\n";
	cout << "[5] - search by salary\n";
	cout << "[6] - search by surname\n";
	cout << "[7] - save to file\n";
	cout << "[8] - load from file\n";
	cout << "choose action: ";
}
void errormsgempty()
{
	system("CLS");
	cout << "ERROR: THE BOOK IS EMPTY\n";
	system("pause");
	system("CLS");
	return;
}