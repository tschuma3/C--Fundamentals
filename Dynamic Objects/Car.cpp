#include "Car.h"

Car::Car(string newMake, string newModel, int newYear)
	:make(newMake), model(newModel), year(newYear)
{
}

Car::Car(const Car &other)
{	
	make = other.make;
	model = other.model;
	year = other.year;
}

string Car::getMake() const
{
	return make;
}

string Car::getModel() const
{
	return model;
}

int Car::getYear() const
{
	return year;
}

string Car::getPlate() const
{
	return plate;
}

void Car::setMake(string newMake)
{
}

void Car::setModel(string newModel)
{
}

void Car::setYear(int newYear)
{
}

void Car::setPlate(string newPlate)
{
	plate = newPlate;
}
