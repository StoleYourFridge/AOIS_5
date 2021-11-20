#include "AOIS_5.h"

int main()
{
	int choice;
	cout << "1)Tests :: 2)Task" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: tests();
		break;
	case 2: task();
		break;
	default: cout << "Enter something possible to work with!!" << endl;
		return 0;
	}
	return 0;
}