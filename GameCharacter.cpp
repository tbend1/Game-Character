#include "GameCharacter.h"


GameCharacter::GameCharacter(string charName, int maxH, int aP, int dP)
{
	name = charName;
	maxHealth = maxH;
	attackPoints = aP;
	defensePoints = dP;
	healthPoints = maxHealth;
	isAlive = true;
	lastSaveTime = time(0);
}


string GameCharacter::getName() const
{
	return name;
}

int GameCharacter::getMaxHealth() const
{
	return maxHealth;
}

int GameCharacter::getHealthPoints() const
{
	return healthPoints;
}

int GameCharacter::getAttackPoints() const
{
	return attackPoints;
}

int GameCharacter::getDefensePoints() const
{
	return defensePoints;
}

bool GameCharacter::getIsAlive() const 
{
	return isAlive;
}

void GameCharacter::takeDamage(int damage)
{
	healthPoints -= damage;
	if(healthPoints <= 0)
		isAlive = false;
}

void GameCharacter::attack(GameCharacter& target)
{
	int damage = attackPoints - target.getDefensePoints();

	//protects against negative damage
	if(damage >= 0)
		target.takeDamage(damage);
}

GameCharacter& GameCharacter::operator+(GameCharacter& rhs)
{
	maxHealth += rhs.getMaxHealth();
	healthPoints = (healthPoints + rhs.getHealthPoints())/2;
	attackPoints = (attackPoints + rhs.getAttackPoints())/2;
	defensePoints = (defensePoints + rhs.getDefensePoints())/2;

	return *this;
}

bool GameCharacter::operator>(GameCharacter& rhs)
{
	return healthPoints > rhs.getHealthPoints();
}

bool GameCharacter::operator<(GameCharacter& rhs)
{
	return healthPoints < rhs.getHealthPoints();

}

ostream& operator<<(ostream& os, GameCharacter& rhs)
{
	os << "Name: " << rhs.getName() << endl;
	os << "Max Health: " << rhs.getMaxHealth() << endl;
	os << "Health Points: " << rhs.getHealthPoints() << endl;
	os << "Attack Points: " << rhs.getAttackPoints() << endl;
	os << "Defense Points: " << rhs.getDefensePoints() << endl;
	os << "Is Alive: " << rhs.getIsAlive() << endl;

	return os;
}


ofstream GameCharacter::saveToFile(string fileName)
{
	ofstream outFile(fileName);
	outFile << name << endl;
	outFile << maxHealth << endl;
	outFile << healthPoints << endl;
	outFile << attackPoints << endl;
	outFile << defensePoints << endl;
	outFile << isAlive << endl;

	lastSaveTime = time(0);

	return outFile;
}

ifstream GameCharacter::loadFromFile(string fileName)
{
	ifstream inFile(fileName);
	inFile >> name;
	inFile >> maxHealth;
	inFile >> healthPoints;
	inFile >> attackPoints;
	inFile >> defensePoints;
	inFile >> isAlive;
	
	return inFile;
}

void GameCharacter::displayDateTimeOfLastSave() const
{
	char* dt = ctime(&lastSaveTime);
	cout << "Last Saved Time: " << dt << endl;
}
	
void GameCharacter::displayTimeSinceLastSave() const
{
	cout << "Time from last saved time: " << difftime(time(0), lastSavedTime) << endl;
}





