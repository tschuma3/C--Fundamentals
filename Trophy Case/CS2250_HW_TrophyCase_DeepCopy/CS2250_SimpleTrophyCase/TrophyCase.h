// Guard the header
#ifndef TROPHYCASE_H
#define TROPHYCASE_H

#include "Trophy.h"
#include <iostream>
#include <string>
using namespace std;

class TrophyCase
{
public:
	// Constructor
	TrophyCase();
	// Copy Constructor
	TrophyCase(const TrophyCase& trophy);
	// Deconstructor	
	~TrophyCase();
	// Assignment Operator
	TrophyCase operator=(const TrophyCase& trophyCase);
	// Insertion Operator
	friend ostream& operator<<(ostream& sout, const TrophyCase& trophyCase);
	// Getting type of functions
	int getNbrOfTrophies() const;
	int getAllocatedSize() const;
	// Expands the trophycase
	void expandTrophycase();
	// Sorts the trophycase
	void sortTrophycase();
	// Searches for trophy
	int searchForTrophy(const string& name);
	// Adds a trophy
	void addTrophy(const string& name, int level, Color color);
	// Checks the state of the trophies
	bool copyTrophy(const string& name);
	bool deleteTrophy(const string& name);
	bool renameTrophy(const string& name, const string& newName);
	bool relevelTrophy(const string& name, int level);
	bool recolorTrophy(const string& name, Color color);	
private:
	int space;
	Trophy** trophyCase;
	int size;
};

// End the guard
#endif