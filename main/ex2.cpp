// ConsoleApplication24.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "pch.h"
#include <iostream>


void swaps(int& a, int& b)
{

	int c = a;
	a = b;
	b = c;

}

void print_values(int a, int b)
{
	
	std::cout << "The value a is: " << a << " and is contained in address: " << &a << "\n";
	std::cout << "The value b is: " << b << " and is contained in address: " << &b << "\n";
}

int main(const char argv, int argc)
{
	int a = 4;
	int b = 3;

	print_values(a, b);

	swaps(a, b);

	print_values(a, b);


	system("pause");
	return 0;
}
