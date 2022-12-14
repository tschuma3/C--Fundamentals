#include "Trophy.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Implement the Trophy class
// Constructors
Trophy::Trophy()
{
	trophyName = new string("");
	trophyLevel = new int(1);
	trophyColor = new Color(BRONZE);
}
Trophy::Trophy(const string& name, int level, Color color)
{
	trophyName = new string(name);
	trophyLevel = new int(level);
	trophyColor = new Color(color);
}

// Copy of Constructor
Trophy::Trophy(const Trophy& trophy)
{
	trophyName = new string(*trophy.trophyName);
	trophyLevel = new int(*trophy.trophyLevel);
	trophyColor = new Color(*trophy.trophyColor);
}

// Assignment Opperator
Trophy& Trophy::operator=(const Trophy& trophy)
{
	*trophyName = *trophy.trophyName;
	*trophyLevel = *trophy.trophyLevel;
	*trophyColor = *trophy.trophyColor;
	return *this;
}
bool Trophy::operator<(const Trophy& trophyO) const
{
	if (compareTrophy(trophyO) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Trophy::operator>(const Trophy& trophyO) const
{
	if (compareTrophy(trophyO) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Trophy::operator==(const Trophy& trophyO) const
{
	if (compareTrophy(trophyO) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Trophy::operator!=(const Trophy& trophyO) const
{
	if (compareTrophy(trophyO) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Trophy::operator<=(const Trophy& trophyO) const
{
	if (compareTrophy(trophyO) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Trophy::operator>=(const Trophy& trophyO) const
{
	//return compareTrophy(trophyO) >= 0;
	if (compareTrophy(trophyO) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}
// Insertion Operator
ostream& operator<<(ostream& sout, const Trophy& trophy)
{
	// Prints out the name and level
	sout << "[ " << left << setw(30) << *trophy.trophyName << " : " << right << setw(2)
		<< *trophy.trophyLevel << left << " : ";

	// Prints out the correct color
	switch (*trophy.trophyColor)
	{
	case GOLD:
		sout << setw(6) << "GOLD";
		break;
	case SILVER:
		sout << setw(6) << "SILVER";
		break;
	case BRONZE:
		sout << setw(6) << "BRONZE";
		break;
	}
	sout << " ]";
	return sout;
}

// Deconstructor
Trophy::~Trophy()
{
	delete trophyName;
	trophyName = NULL;

	delete trophyLevel;
	trophyLevel = NULL;

	delete trophyColor;
	trophyColor = NULL;
}

// Gets the name, level, and color
string Trophy::getName() 
{
	return *trophyName;
}

int Trophy::getLevel() 
{
	return *trophyLevel;
}

Color Trophy::getColor() 
{
	return *trophyColor;
}

// Sets the name, level, and color
void Trophy::setName(const string& name)
{
	*trophyName = name;
}
void Trophy::setLevel(int& level)
{
	*trophyLevel = level;
}
void Trophy::setColor(Color color)
{
	*trophyColor = color;
}

// Compare trophies for different areas
int Trophy::compareTrophy(const Trophy& trophy) const
{
	if (*trophyLevel > *trophy.trophyLevel)
	{
		return 1;
	}
	else if (*trophyLevel < *trophy.trophyLevel)
	{
		return -1;
	}
	else //if (*trophyLevel == *trophy.trophyLevel)
	{
		if (*trophyColor > *trophy.trophyColor)
		{
			return 1;
		}
		else if (*trophyColor < *trophy.trophyColor)
		{
			return -1;
		}
		else //if (*trophyColor == *trophy.trophyColor)
		{
			if (*trophyName > * trophy.trophyName)
			{
				return 1;
			}
			else if (*trophyName < *trophy.trophyName)
			{
				return -1;
			}
			else //if (*trophyName == *trophy.trophyName)
			{
				return 0;
			}
		}
	}
}

// Prints the trophy in the correct format
void Trophy::print()
{
	switch (*trophyColor)
	{
	case GOLD:
		cout << "[ " << *trophyName << " : " << *trophyLevel << " : " << "GOLD" << " ]" << endl;
		break;
	case SILVER:
		cout << "[ " << *trophyName << " : " << *trophyLevel << " : " << "SILVER" << " ]" << endl;
		break;
	case BRONZE:
		cout << "[ " << *trophyName << " : " << *trophyLevel << " : " << "BRONZE" << " ]" << endl;
		break;
	}
}