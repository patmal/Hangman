#include <iostream>
#include <fstream>
#include <string>


void gallows(int *lives)
{
	switch(*lives)
	{
		case 0:
			cout << "\n\n\n"
			<< "         ______ \n"
			<< "         |    | \n"
			<< "         |    O \n"
			<< "         |   /|\\ \n"
			<< "         |   / \\ \n"
			<< "        _|_______ \n" << endl;
			break;
		case 1:
			cout << "\n\n\n"
			<< "         ______ \n"
			<< "         |    | \n"
			<< "         |    O \n"
			<< "         |   /|\\ \n"
			<< "         |   /  \n"
			<< "        _|_______ \n" << endl;
			break;
		case 2:
			cout << "\n\n\n"
			<< "         ______ \n"
			<< "         |    | \n"
			<< "         |    O \n"
			<< "         |   /|\\ \n"
			<< "         |      \n"
			<< "        _|_______ \n" << endl;
			break;
		case 3:
			cout << "\n\n\n"
			<< "         ______ \n"
			<< "         |    | \n"
			<< "         |    O \n"
			<< "         |   /| \n"
			<< "         |      \n"
			<< "        _|_______ \n" << endl;
			break;
		case 4:
			cout << "\n\n\n"
			<< "         ______ \n"
			<< "         |    | \n"
			<< "         |    O \n"
			<< "         |    | \n"
			<< "         |      \n"
			<< "        _|_______ \n" << endl;
			break;
		case 5:
			cout << "\n\n\n"
			<< "         ______ \n"
			<< "         |    | \n"
			<< "         |    O \n"
			<< "         |      \n"
			<< "         |      \n"
			<< "        _|_______ \n" << endl;
			break;
		case 6:
			cout << "\n\n\n"
			<< "         ______ \n"
			<< "         |    | \n"
			<< "         |      \n"
			<< "         |      \n"
			<< "         |      \n"
			<< "        _|_______ \n" << endl;
			break;
	}
}
