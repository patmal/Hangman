#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "gallows.h"
#include "check.h"
#include "show.h"
#include "life.h"
#include "wincheck.h"


int main()
{
	string word;
	string hidden;
	char guess;
	int lives = 0;
	int length;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n    =====HANGMAN=====";
	gallows(&lives);
	char yn = 'y';
	int state = 1;


	while(yn == 'y')
	{
		switch(state)
		{
			case 1:
				cout << "Player 2, please look away from the screen." << endl;
				cout << "Player 1, please enter a word for Player 2 to guess: ";
				cin >> word;
				while(check(&word) < 0)
				{
					cout << "Invalid word. Try again: ";
					cin >> word;
				}
				length = word.length();
				hidden = string(length, '_');
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				state = 2;
				lives = 6;
				break;

			case 2:
				while(lives != 0)
				{
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					gallows(&lives);
					cout << "word:    " << hidden << "\n\n";
					cout << "Player 2, guess a letter: ";
					cin >> guess;
					if(life(guess, word) < 0)
						lives--;
					else
					{
						hidden = show(hidden, word, guess);
						if(wincheck(hidden) > 0)
						{
							state = 3;
							break;
						}
					}
				}
				if(state == 3)
					break;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				gallows(&lives);
				cout << "word:    " << hidden << "\n\n";
				cout << "TOO BAD! YOU COULDN'T GUESS THE WORD!\n\n";
				state = 4;
				break;
			case 3:
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				gallows(&lives);
				cout << "word:    " << hidden << "\n\n";
				cout << "CONGRATULATIONS! YOU GUESSED THE WORD!\n\n";
				state = 4;
				break;
			case 4:
				cout << "Play Again? y/n: ";
				cin >> yn;
				state = 1;
				break;

		}
	}


	return 0;
}
