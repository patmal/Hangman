#include <iostream>
#include <fstream>
#include <string>


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
