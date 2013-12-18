#include <iostream>
#include <fstream>
#include <string>


// this function updates the guessed word on the interface

string show(string hidden, string word, char guess)
{
	string str;
	for(unsigned int i = 0; i < word.length(); i++)
	{
		if(guess == word[i])
			hidden[i] = word[i];
	}
	str = hidden;
	return str;
}
