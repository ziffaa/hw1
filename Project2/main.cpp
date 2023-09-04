#include "header.h"

using namespace std;

int main()
{
	while (true)
	{
		int action = 0;
		printmenu();
		cin >> action;

		switch (action)
		{
		case 1:
			addperson();
			break;
		case 2:
			removeperson();
			break;
		case 3:
			printbook();
			break;
		case 4:
			salarysearch();
			break;
		case 5:
			surnamesearch();
			break;
		case 6:
			savefile();
			break;
		case 7:
			loadfile();
			break;
		default:
			cout << "\nincorrect option\n\n";
			break;
		}
	}
}
