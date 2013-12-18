#include <iostream>
#include <fstream>
#include <string>


int life(char guess, string word)
{
	int found = -1;
	for(unsigned int i = 0; i < word.length(); i++)
	{
		if(guess == word[i])
			found = 1;
	}
	return found;
}
