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
	string word;	// user-entered word
	string hidden;	// displayed blanks/letters
	char guess;	// guessed letter
	int lives = 0;	// lives left on the hangman
	int length;	// length of the word
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n    =====HANGMAN=====";	// clears the screen and displays the title
	gallows(&lives);	// displays the gallows
	char yn = 'y';	// continue answer
	int state = 1;	// initial state of the game state machine


	// game runs as long as the user enters 'y'
	while(yn == 'y')
	{
		// finite state machine for the game
		switch(state)
		{
			// game start
			case 1:
				cout << "Player 2, please look away from the screen." << endl;
				cout << "Player 1, please enter a word for Player 2 to guess: ";
				cin >> word;
				// checks the entered word against the included dictionary
				while(check(&word) < 0)
				{
					cout << "Invalid word. Try again: ";
					cin >> word;
				}
				length = word.length();
				// creates a string of blanks to be displayed
				hidden = string(length, '_');
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				state = 2;	// next state
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
					// lose a life if guess is incorrect
					if(life(guess, word) < 0)
						lives--;
					else
					{
						hidden = show(hidden, word, guess);
						// if word is correctly guessed go to win state
						if(wincheck(hidden) > 0)
						{
							state = 3;
							break;
						}
					}
				}
				if(state == 3)
					break;
				// you lose
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				gallows(&lives);
				cout << "word:    " << hidden << "\n\n";
				cout << "TOO BAD! YOU COULDN'T GUESS THE WORD!\n\n";
				state = 4;
				break;
			// you win
			case 3:
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				gallows(&lives);
				cout << "word:    " << hidden << "\n\n";
				cout << "CONGRATULATIONS! YOU GUESSED THE WORD!\n\n";
				state = 4;
				break;
			// play again?
			case 4:
				cout << "Play Again? y/n: ";
				cin >> yn;
				state = 1;
				break;

		}
	}


	return 0;
}
