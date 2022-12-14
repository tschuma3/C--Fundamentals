#include <iostream>
#include <string>
#include "Vector2.h"

using namespace std;

int nbrFailed = 0;

void PrintVector(const Vector2& v)
{
	cout << "(" << v.getX() << ", " << v.getY() << ")" << endl;
}

void executeSingleParamTest(const string& testName, int x, int y)
{
	cout << testName << endl;
	Vector2 vector(x);
	vector.print();
	if (vector.getX() != x) { cout << "FAILED: x == " << x << endl; ++nbrFailed; }
	else { cout << "PASSED x == " << x << endl; }
	if (vector.getY() != y) { cout << "FAILED: y == " << y << endl;  ++nbrFailed; }
	else cout << "PASSED y == " << y << endl;
}

void executeDoubleParamTest(const string& testName, int x, int y)
{
	cout << testName << endl;
	Vector2 vector(x, y);
	vector.print();
	if (vector.getX() != x) { cout << "FAILED: x == " << x << endl; ++nbrFailed; }
	else { cout << "PASSED x == " << x << endl; }
	if (vector.getY() != y) { cout << "FAILED: y == " << y << endl;  ++nbrFailed; }
	else cout << "PASSED y == " << y << endl;
}

void executeSetTest(const string& testName, int x, int y)
{
	cout << testName << endl;
	Vector2 vector;
	vector.setX(x);
	vector.setY(y);
	vector.print();
	if (vector.getX() != x) { cout << "FAILED: x == " << x << endl; ++nbrFailed; }
	else { cout << "PASSED x == " << x << endl; }
	if (vector.getY() != y) { cout << "FAILED: y == " << y << endl;  ++nbrFailed; }
	else cout << "PASSED y == " << y << endl;
}


void executeAssignmentTest(const string& testName, int x, int y)
{
	cout << testName << endl;
	Vector2 vector;
	Vector2 vector1(x, y);
	vector = vector1;
	vector.print();
	vector1.print();
	if (vector.getX() != x) { cout << "FAILED: x == " << x << endl; ++nbrFailed; }
	else { cout << "PASSED x == " << x << endl; }
	if (vector.getY() != y) { cout << "FAILED: y == " << y << endl;  ++nbrFailed; }
	else cout << "PASSED y == " << y << endl;
}

void executeCopyConstructorTest(const string& testName, int x, int y)
{
	cout << testName << endl;
	Vector2 vector1(x, y);
	Vector2 vector(vector1);
	vector.print();
	vector1.print();
	if (vector.getX() != x) { cout << "FAILED: x == " << x << endl; ++nbrFailed; }
	else { cout << "PASSED x == " << x << endl; }
	if (vector.getY() != y) { cout << "FAILED: y == " << y << endl;  ++nbrFailed; }
	else cout << "PASSED y == " << y << endl;
}


int main()
{
	{
		cout << "DEFAULT CONSTRUCTOR TESTING" << endl;
		int x = 0;
		int y = 0;
		Vector2 vector;
		if (vector.getX() != x) { cout << "FAILED: x == " << x << endl; ++nbrFailed; }
		else { cout << "PASSED x == " << x << endl; }
		if (vector.getY() != y) { cout << "FAILED: y == " << y << endl;  ++nbrFailed; }
		else cout << "PASSED y == " << y << endl;
		vector.print();
	}

	executeSingleParamTest("SINGLE PARAMETER CONSTRUCTOR TESTING - POSITIVE VALUE", 5, 0);
	executeSingleParamTest("SINGLE PARAMETER CONSTRUCTOR TESTING - NEGATIVE VALUE", -5, 0);
	executeSingleParamTest("SINGLE PARAMETER CONSTRUCTOR TESTING - ZERO VALUE", 0, 0);

	executeDoubleParamTest("SINGLE PARAMETER CONSTRUCTOR TESTING - POSITIVE VALUE", 5, 10);
	executeDoubleParamTest("SINGLE PARAMETER CONSTRUCTOR TESTING - NEGATIVE VALUE", -5, -10);
	executeDoubleParamTest("SINGLE PARAMETER CONSTRUCTOR TESTING - ZERO VALUE", 0, 0);
	executeDoubleParamTest("SINGLE PARAMETER CONSTRUCTOR TESTING - MIXED VALUE", -5, 10);
	executeDoubleParamTest("SINGLE PARAMETER CONSTRUCTOR TESTING - MIXED VALUE", 5, -10);

	executeSetTest("SET TESTING - POSITIVE VALUE", 5, 10);
	executeSetTest("SET TESTING - NEGATIVE VALUE", -5, -10);
	executeSetTest("SET TESTING - ZERO VALUE", 0, 0);
	executeSetTest("SET TESTING - MIXED VALUE", 5, -10);
	executeSetTest("SET TESTING - MIXED VALUE", -5, 10);

	executeAssignmentTest("ASSIGNMENT TESTING - POSITIVE VALUE", 5, 10);
	executeAssignmentTest("ASSIGNMENT TESTING - NEGATIVE VALUE", -5, -10);
	executeAssignmentTest("ASSIGNMENT TESTING - ZERO VALUE", 0, 0);
	executeAssignmentTest("ASSIGNMENT TESTING - MIXED VALUE", -5, 10);
	executeAssignmentTest("ASSIGNMENT TESTING - MIXED VALUE", 5, -10);

	executeCopyConstructorTest("COPY CONSTRUCTOR TESTING - POSITIVE VALUE", 5, 10);
	executeCopyConstructorTest("COPY CONSTRUCTOR TESTING - NEGATIVE VALUE", -5, -10);
	executeCopyConstructorTest("COPY CONSTRUCTOR TESTING - ZERO VALUE", 0, 0);
	executeCopyConstructorTest("COPY CONSTRUCTOR TESTING - MIXED VALUE", -5, 10);
	executeCopyConstructorTest("COPY CONSTRUCTOR TESTING - MIXED VALUE", 5, -10);

	cout << "Press any key to exit..." << endl;
	char c;
	cin.get(c);

	return 0;
}