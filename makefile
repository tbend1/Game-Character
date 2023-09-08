math: GameCharacter.o game.o
	c++ GameCharacter.o game.o -o math
	
GameCharacter.o: GameCharacter.cpp
	c++ -c GameCharacter.cpp
	
game.o: game.cpp
	c++ -c game.cpp
	
clean:
	rm *.o math