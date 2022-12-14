#include "TrophyCase.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Constructor
TrophyCase::TrophyCase()
{
	space = 10;
	size = 0;
	trophyCase = new Trophy*[space];
}
// Copy Constructor
TrophyCase::TrophyCase(const TrophyCase& otherTrophyCase)
{
	size = otherTrophyCase.getNbrOfTrophies();
	space = otherTrophyCase.getAllocatedSize();
	trophyCase = new Trophy*[space];

	// Iterates and copies
	for (int i = 0; i < size; i++)
	{
		this->trophyCase[i] = new Trophy(*otherTrophyCase.trophyCase[i]);
	}
}
// Deconstructor	
TrophyCase::~TrophyCase()
{
	// Iterates and deletes
	for (int i = 0; i < size; i++)
	{
		delete trophyCase[i];
		trophyCase[i] = nullptr;
	}
	// Deletes trophycase
	delete trophyCase;
	trophyCase = NULL;
}
// Assignment Operator
TrophyCase TrophyCase::operator=(const TrophyCase& trophyCase) 
{
	// If it is not a trophycase
	if (this != &trophyCase)
	{
		for (int i = 0; i < size; i++) 
		{
			delete this->trophyCase[i];
			this->trophyCase[i] = NULL;
		}

		// Creates an new trophy case
		size = trophyCase.getNbrOfTrophies();
		space = trophyCase.getAllocatedSize();
		
		// Deletes the trophy case
		delete[] this->trophyCase;

		// Assigns the new trophycase
		this->trophyCase = new Trophy*[space];

		// Copies the trophies to a new array
		for (int i = 0; i < size; i++)
		{
			this->trophyCase[i] = new Trophy(*trophyCase.trophyCase[i]);
		}
	}
	return *this;
}
// Insertion Operator
ostream& operator<<(ostream& sout, const TrophyCase& trophyCase)
{
	for (int i = 0; i < trophyCase.getNbrOfTrophies(); i++)
	{
		sout << *trophyCase.trophyCase[i] << endl;
	}
	return sout;
}
// Getting type of functions
int TrophyCase::getNbrOfTrophies() const
{
	return size;
}
int TrophyCase::getAllocatedSize() const
{
	return space;
}
// Expands the trophycase
void TrophyCase::expandTrophycase()
{
	// Expands by 10%
	space = space * 1.1;

	// Storage of the array
	Trophy** tempTrophyCase = new Trophy*[space];

	// Copies the old values
	for (int i = 0; i < size; i++)
	{
		tempTrophyCase[i] = trophyCase[i];
	}

	// Deletes the old values and add them to the new array
	delete[] trophyCase;
	trophyCase = tempTrophyCase;
}
// Sorts the trophycase
void TrophyCase::sortTrophycase()
{
	// Sorts by bubble sort
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			// If the trophy case is greater than the next one
			if (*trophyCase[j] > *trophyCase[j + 1])
			{
				// A temporary variable
				Trophy temp = *trophyCase[j];

				// Swaps the trophy cases
				*trophyCase[j] = *trophyCase[j + 1];
				*trophyCase[j + 1] = temp;
			}
		}
	}
}
// Searches for trophy
int TrophyCase::searchForTrophy(const string& name)
{
	// Iterates through the array
	for (int i = 0; i < size; i++)
	{
		// Compare the name
		if (trophyCase[i]->getName() == name)
		{
			return i;
		}
	}
	return -1;
}
// Adds a trophy
void TrophyCase::addTrophy(const string& name, int level, Color color)
{
	// Creates a new trophy
	Trophy* newTrophy = new Trophy(name, level, color);

	// Expands if needed
	if (size >= space)
	{
		expandTrophycase();
	}

	// Adds a new trophy to the case
	trophyCase[size] = newTrophy;
	size++;

	cout << "Before sort" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << *trophyCase[i] << endl;
	}
	sortTrophycase();
	cout << "After sort" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << *trophyCase[i] << endl;
	}

}
// Checks the state of the trophies
bool TrophyCase::copyTrophy(const string& name)
{
	// Variable
	int trophyPosition = searchForTrophy(name);

	// Checks to see if the trophy position is actually a position
	if (trophyPosition > -1)
	{
		// Expand if needed
		if (size >= space)
		{
			expandTrophycase();
		}

		// Copies into an array
		Trophy* newTrophy = new Trophy(*trophyCase[trophyPosition]);
		
		// Changes the size
		trophyCase[size] = newTrophy;
		size++;

		// Sorts the array
		sortTrophycase();
		return true;
	}
	else
	{
		return false;
	}
}
bool TrophyCase::deleteTrophy(const string& name)
{
	// Variable
	int trophyPosition = searchForTrophy(name);

	// Checks to see if the trophy position is actually a position
	if (trophyPosition > -1)
	{
		// Deletes the trophy
		delete trophyCase[trophyPosition];
		trophyCase[trophyPosition] = NULL;

		// Fills the back if needed
		for (int i = trophyPosition; i < size; i++)
		{
			trophyCase[i] = trophyCase[i + 1];
		}

		// Decrements and sets the out of range value to null
		size--;
		trophyCase[size] = nullptr;
		
		return true;
	}
	else
	{
		return false;
	}
}
bool TrophyCase::renameTrophy(const string& name, const string& newName)
{
	// Variable
	int trophyPosition = searchForTrophy(name);

	// Checks to see if the trophy position is actually a position
	if (trophyPosition > -1)
	{
		// Sets the new name
		trophyCase[trophyPosition]->setName(newName);

		// Sorts the trophies
		sortTrophycase();
		return true;
	}
	else
	{
		return false;
	}
}
bool TrophyCase::relevelTrophy(const string& name, int level)
{
	// Variable
	int trophyPosition = searchForTrophy(name);

	// Checks to see if the trophy position is actually a position
	if (trophyPosition > -1)
	{
		// Sets the new name
		trophyCase[trophyPosition]->setLevel(level);

		// Sorts the trophies
		sortTrophycase();
		return true;
	}
	else
	{
		return false;
	}
}
bool TrophyCase::recolorTrophy(const string& name, Color color)
{
	// Variable
	int trophyPosition = searchForTrophy(name);

	// Checks to see if the trophy position is actually a position
	if (trophyPosition > -1)
	{
		// Sets the new name
		trophyCase[trophyPosition]->setColor(color);

		// Sorts the trophies
		sortTrophycase();
		return true;
	}
	else
	{
		return false;
	}
}