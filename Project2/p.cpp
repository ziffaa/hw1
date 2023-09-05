#include "header.h"

using namespace std;

void employee::inputinfo()
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
	while (true)
	{
		cout << "enter salary: ";
		cin >> salary;
		if (cin.fail())
		{
			cout << "ERROR: INCORRECT VALUE\n";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		else
		{
			break;
		}
	}
	cout << endl;
}
void employee::print()
{
	cout << "\nfist name: " << firstname << endl;
	cout << "surnname: " << surname << endl;
	cout << "phone number: " << phonenumber << endl;
	cout << "salary: $" << salary << "\n\n";
}

employee book[50];
int employeecounter = 0;
int action;

void addemployee()
{
	book[employeecounter].inputinfo();
	employeecounter++;
	system("CLS");
	return;
}

void removeemployee()
{
	if (employeecounter == 0)
	{
		errormsgempty();
		return;
	}
	cout << "\nselect the employee you want to remove:\n";
	for (int i = 0; i < employeecounter; i++)
	{
		cout << "[" << i + 1 << "]" << book[i].firstname << " " << book[i].surname << endl;
	}
	int n;
	cin >> n;
	if (cin.fail() || n <= 0 || n > employeecounter)
	{
		errormsgwrongvalue();
		return;
	}
	int confirm;
	cout << "\nenter 1 to confirm, 0 to cancel: ";
	cin >> confirm;
	if (cin.fail() || confirm != 1 || confirm != 0)
	{
		errormsgwrongvalue();
		return;
	}
	if (confirm == 0)
	{
		return;
	}
	for (int i = n; i < employeecounter; i++)
	{
		book[n - 1] = book[n];
	}
	employeecounter--;
	system("CLS");
	return;
}

void printbook()
{
	if (employeecounter == 0)
	{
		errormsgempty();
		return;
	}
	for (int i = 0; i < employeecounter; i++)
	{
		book[i].print();
	}
	system("pause");
	system("CLS");
	return;
}

void salarysearch()
{
	if (employeecounter == 0)
	{
		errormsgempty();
		return;
	}
	double min = 0;
	double max = 0;
	cout << "\nEnter minimum salary: ";
	cin >> min;
	if (cin.fail())
	{
		errormsgwrongvalue();
		return;
	}
	cout << "Enter maximum salary: ";
	cin >> max;
	if (cin.fail())
	{
		errormsgwrongvalue();
		return;
	}
	for (int i = 0; i < employeecounter; i++)
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
	if (employeecounter == 0)
	{
		errormsgempty();
		return;
	}
	char* surname{ new char[100] };
	cout << "\nEnter surname: ";
	cin >> surname;
	for (int i = 0; i < employeecounter; i++)
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
		for (int i = 0; i < employeecounter; i++)
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
	employeecounter = 0;
	ifstream in("book.txt");
	if (in.is_open())
	{

		while (getline(in, line1) && getline(in, line2) && getline(in, line3) && getline(in, line4))
		{
			strcpy_s(book[employeecounter].firstname, 100, line1.c_str());
			strcpy_s(book[employeecounter].surname, 100, line2.c_str());
			strcpy_s(book[employeecounter].phonenumber, 100, line3.c_str());
			book[employeecounter].salary = stod(line4);
			employeecounter++;
		}
	}
	in.close();
	system("CLS");
	return;
}

void asort() {
	for (int pass = 0; pass < employeecounter - 1; pass++) {
		for (int j = 0; j < employeecounter - pass - 1; j++) {
			int i = 0;
			while (book[j].surname[i] != '\0' && book[j + 1].surname[i] != '\0' && book[j].surname[i] == book[j + 1].surname[i]) {
				i++;
			}
			if (book[j].surname[i] > book[j + 1].surname[i]) {
				employee temp = book[j + 1];
				book[j + 1] = book[j];
				book[j] = temp;
			}
		}
	}
	printbook();
}
void printmenu()
{
	cout << "[1] - add employee\n";
	cout << "[2] - remove employee\n";
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
void errormsgwrongvalue()
{
	system("CLS");
	cout << "\nERROR: INCORRECT VALUE\n\n";
	cin.clear();
	cin.ignore(100, '\n');
	system("pause");
	system("CLS");
	return;
}