CFLAGS ?= -Wall -g

Hangman: game.o
	g++ -o $@ $^

%.o: %.cpp
	g++ $(CFLAGS) -c -o $@ $^
