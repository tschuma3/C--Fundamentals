#include <iostream>
#include <string>

using namespace std;

// Prototypes
void Choice();
int DrawSquare(int);
int DrawRightTriangle(int);
int DrawIsoscelesTriangle(int);
int DrawHourglass(int);
int DrawDiamond(int);
int ExitsTheProgram();

int main()
{
	// Variables
	int selection;
	int size;

	// Welcome message, menu, and selection
	cout << "Welcome to the shape renderer!" << endl;
	cout << "You can draw a few different shapes at a variety of sizes!" << endl;
	cout << "********************************************************************************" << endl;
	cout << "* Please select a menu option(1 - 6) :" << endl;
	cout << "* 1 - Square" << endl;
	cout << "* 2 - Right Triangle" << endl;
	cout << "* 3 - Isosceles Triangle" << endl;
	cout << "* 4 - Hourglass" << endl;
	cout << "* 5 - Diamond" << endl;
	cout << "* 6 - Quit(exit the application)" << endl;
	cout << "********************************************************************************" << endl;
	

	// Loops till the users choice is between 1 and 6
	do
	{
		cout << "Please select a menu option(1-6)" << endl;
		cin >> selection;

		switch (selection)
		{
			case 1:
				cout << "You have selected a square!  What size should your square be (1-20)?" << endl;
				cin >> size;

				while (size < 1 || size > 20)
				{
					cout << "You have not selected an appropriate size, please try again." << endl;
					cout << "You have selected a square!  What size should your square be (1-20)?" << endl;
					cin >> size;
				}

				DrawSquare(size);
				break;
			case 2:
				cout << "You have selected a right triangle!  What size should your square be (1-20)?" << endl;
				cin >> size;

				while (size < 1 || size > 20)
				{
					cout << "You have not selected an appropriate size, please try again." << endl;
					cout << "You have selected a right triangle!  What size should your square be (1-20)?" << endl;
					cin >> size;
				}

				DrawRightTriangle(size);
				break;
			case 3:
				cout << "You have selected a isosceles!  What size should your square be (1-20)?" << endl;
				cin >> size;

				while (size < 1 || size > 20)
				{
					cout << "You have not selected an appropriate size, please try again." << endl;
					cout << "You have selected a isosceles!  What size should your square be (1-20)?" << endl;
					cin >> size;
				}

				DrawIsoscelesTriangle(size);
				break;
			case 4:
				cout << "You have selected a hourglass!  What size should your square be (1-20)?" << endl;
				cin >> size;

				while (size < 1 || size > 20)
				{
					cout << "You have not selected an appropriate size, please try again." << endl;
					cout << "You have selected a hourglass!  What size should your square be (1-20)?" << endl;
					cin >> size;
				}

				DrawHourglass(size);
				break;
			case 5:
				cout << "You have selected a diamond!  What size should your square be (1-20)?" << endl;
				cin >> size;

				while (size < 1 || size > 20)
				{
					cout << "You have not selected an appropriate size, please try again." << endl;
					cout << "You have selected a diamond!  What size should your square be (1-20)?" << endl;
					cin >> size;
				}

				DrawDiamond(size);
				break;

			case 6:
				break;

			default:
				Choice();
		}
	} while (selection != 6);

	ExitsTheProgram();

	return 0;
}

// Function is called when the choice is < 1 or > 6
void Choice()
{
	cout << "You have not selected a valid menu option, please try again." << endl;
	cout << "Please select a menu option(1-6)" << endl;

}

// Creates the square at specific dimensions
int DrawSquare(int size)
{
	for (int i = 0; i <= size; i++)
	{
		cout << endl;
		for (int j = 0; j <= size; j++)
		{
			cout << "*";
		}
	}
	cout << endl;
	return 0;
}

// Creates the right triangle at specific dimensions
int DrawRightTriangle(int size)
{
	for (int i = 0; i <= size; i++)
	{
		cout << endl;
		for (int j = 0; j <= i; j++)
		{
			cout << "*" << " ";
		}
	}
	cout << endl;
	return 0;
}

// Creates the isosceles triangle at specific dimensions
int DrawIsoscelesTriangle(int size)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";
			
		}
		for (int g = 0; g < (i * 2) + 1; g++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}

// Creates the hourglass at specific dimensions
int DrawHourglass(int size)
{
	for (int i = 4; i > 0; i--)
	{
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";
			
		}
		for (int g = 0; g < (i * 2) + 1; g++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";				
		}
		for (int g = 0; g < (i * 2) + 1; g++)
		{
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}

// Creates the diamond at specific dimensions
int DrawDiamond(int size)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";				
		}
		for (int g = 0; g < (i * 2) + 1; g++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";
			
		}
		for (int g = 0; g < (i * 2) - 1; g++)
		{
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}

// Exits the program
int ExitsTheProgram()
{
	cout << "Thank you for using our application!  Good-bye!" << endl;

	return 0;
}
