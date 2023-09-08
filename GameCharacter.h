#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class GameCharacter
{
	private:
		string name;
		int maxHealth;
		int healthPoints;
		int attackPoints;
		int defensePoints;
		bool isAlive;
		void takeDamage(int);
	public:
		GameCharacter(string, int, int, int);
		string getName() const;
		int getMaxHealth() const ;
		int getHealthPoints() const ;
		int getAttackPoints() const;
		int getDefensePoints() const; 
		bool getIsAlive() const;
		void attack(GameCharacter&);
		GameCharacter& operator+(GameCharacter&);
		bool operator>(GameCharacter&);
		bool operator<(GameCharacter&);
		ofstream saveToFile(string fileName);
		ifstream loadFromFile(string fileName);


		friend ostream& operator<<(ostream&, GameCharacter&);	
	

};

#endif

