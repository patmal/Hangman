#include <iostream>
#include <fstream>
#include <string>


int wincheck(string str)
{
	int win = 1;
	for(unsigned int i = 0; i < str.length(); i++)
	{
		if(str[i] == '_')
			win = -1;
	}
	return win;
}
