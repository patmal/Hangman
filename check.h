#include <iostream>
#include <fstream>
#include <string>


// this function checks if the entered word is listed
// in the dictionary

int check(string *word)
{
	int found = -1;
	string line;
	ifstream file;
	file.open("dict.txt");

	while(!file.eof())
	{
		getline(file, line);
		if(*word == line)
			found = 1;
	}

	return found;
}
