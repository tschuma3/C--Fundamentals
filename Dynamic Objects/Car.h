#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car
{
public:
	Car(string newMake, string newModel, int newYear);
	Car(const Car& other);

	string getMake() const;
	string getModel() const;
	int getYear() const;
	string getPlate() const;

	void setMake(string newMake);
	void setModel(string newModel);
	void setYear(int newYear);
	void setPlate(string newPlate);

private:
	string make;
	string model;
	int year;
	string plate;
};

#endif