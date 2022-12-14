#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

void printCar(const Car& car)
{
	cout << " [ " << car.getMake() << " : "
		<< car.getModel() << " : "
		<< car.getYear() << " : "
		<< car.getPlate() << " ] " << endl;
}

int main()
{
	{
		//////////////////////////////////////////////////////
		// STATIC CONSTRUCTION TESTS
		//////////////////////////////////////////////////////

		cout << "CONSTRUCTOR TEST" << endl;
		Car c1("Nissan", "Pulsar", 1988);
		Car c2("BMW", "Z3", 2004);
		printCar(c1);
		printCar(c2);

		cout << "COPY CONSTRUCTOR TEST" << endl;
		Car c3(c1);
		Car c4(c2);
		Car c5(c3);
		Car c6(c4);
		printCar(c3);
		printCar(c4);
		printCar(c5);
		printCar(c6);

		cout << "SET PLATE TEST" << endl;
		printCar(c1);
		printCar(c2);
		c1.setPlate("123ASB");
		printCar(c1);
		c1.setPlate("890WER");
		printCar(c1);
		c2.setPlate("613HWE");
		printCar(c2);
		c2.setPlate("789RTY");
		printCar(c2);
	}

	{
		//////////////////////////////////////////////////////
		// DYNAMIC CONSTRUCTION TESTS
		// TODO: turn all of the following Cars into Pointers
		// to Cars!  Example:
		// Car* c1 = ..... (what goes over here...)
		//////////////////////////////////////////////////////

		cout << "CONSTRUCTOR TEST" << endl;
		Car* c1 = new Car("Nissan", "Pulsar", 1988);
		Car* c2 = new Car("BMW", "Z3", 2004);
		printCar(*c1);
		printCar(*c2);

		cout << "COPY CONSTRUCTOR TEST" << endl;
		Car* c3 = new Car(*c1);
		Car* c4 = new Car(*c2);
		Car* c5 = new Car(*c3);
		Car* c6 = new Car(*c4);
		printCar(*c3);
		printCar(*c4);
		printCar(*c5);
		printCar(*c6);

		cout << "SET PLATE TEST" << endl;
		printCar(*c1);
		printCar(*c2);
		c1->setPlate("123ASB");
		printCar(*c1);
		c1->setPlate("890WER");
		printCar(*c1);
		c2->setPlate("613HWE");
		printCar(*c2);
		c2->setPlate("789RTY");
		printCar(*c2);
		
		// TODO: Delete all of the cars here....
		delete c1;
		delete c2;
		delete c3;
		delete c4;
		delete c5;
		delete c6;
	}
	return 0;
}