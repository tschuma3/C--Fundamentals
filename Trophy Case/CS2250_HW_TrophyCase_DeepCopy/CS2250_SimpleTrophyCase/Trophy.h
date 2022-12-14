// Guard the header
#ifndef TROPHY_H
#define TROPHY_H

// include the libraries this class will need
#include <string>
#include <vector>
using namespace std;

// Create the color values
enum Color
{
	BRONZE,
	SILVER,
	GOLD
};

// Complete the Trophy class
class Trophy
{
public:
	// Constructors
	Trophy();
	Trophy(const string& name, int level, Color color);
	// Copy of the constructors
	Trophy(const Trophy& trophy);
	// Deconstructor
	~Trophy();
	// Assignmnet Opperator
	Trophy& operator=(const Trophy& trophy);
	bool operator<(const Trophy& trophyO) const;
	bool operator>(const Trophy& trophyO) const;
	bool operator==(const Trophy& trophyO) const;
	bool operator!=(const Trophy& trophyO) const;
	bool operator<=(const Trophy& trophyO) const;
	bool operator>=(const Trophy& trophyO) const;
	friend ostream& operator<<(ostream& sout, const Trophy& trophy);
	// Getters
	string getName();
	int getLevel();
	Color getColor();
	// Setters
	void setName(const string& name);
	void setLevel(int& level);
	void setColor(Color color);
	// Other functions
	int compareTrophy(const Trophy& trophy) const;
	void print();
private:
	// Variables
	string* trophyName;
	int* trophyLevel;
	Color* trophyColor;
};

// End the guard
#endif