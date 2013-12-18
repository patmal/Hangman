#include <iostream>
#include <fstream>
#include <string>


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
