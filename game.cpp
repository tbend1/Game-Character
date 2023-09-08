#include "GameCharacter.h"

using namespace std;

int main()
{
	GameCharacter char1("Bob", 100, 10, 5);
	GameCharacter char2("Jim", 100, 5, 7);
	GameCharacter char3("Tim", 100, 15, 0);

	cout << "Character One Details: " << endl << char1 << endl;
	cout << "Character Two Details: " << endl << char2 << endl;
	cout << "Character Three Details: " << endl << char3 << endl;

	cout << char1.getName() << " attacks " << char2.getName() << endl;
	char1.attack(char2);
	cout << char3.getName()  <<" attacks " << char2.getName() << endl;
	char3.attack(char2);
	cout << char2.getName() << " attacks " << char3.getName() << endl;
	char2.attack(char3);

	cout << endl << "Character comparisons: " << endl;
	if(char1 > char3)
		cout << char1.getName() << " has more health than " << char3.getName() << endl;
	else
		cout << char3.getName() << " has more health than " << char1.getName() << endl;
	if(char1 > char2)
		cout << char1.getName() << " has more health than " << char2.getName() << endl;
	else
		cout << char2.getName() << " has more health than " << char1.getName() << endl;
	if(char3 > char2)
		cout << char3.getName() << " has more health than " << char2.getName() << endl;
	else 
		cout << char2.getName() << " has more health than " << char3.getName() << endl;

	cout << endl << "Final Results:" << endl;
	cout << char1 << endl;
	cout << char2 << endl;
	cout << char3 << endl;

}
