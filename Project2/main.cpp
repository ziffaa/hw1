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
			addemployee();
			break;
		case 2:
			removeemployee();
			break;
		case 3:
			printbook();
			break;
		case 4:
			asort();
			break;
		case 5:
			salarysearch();
			break;
		case 6:
			surnamesearch();
			break;
		case 7:
			savefile();
			break;
		case 8:
			loadfile();
			break;
		default:
			errormsgwrongvalue();
			break;
		}
	}
}