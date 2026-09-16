// Task 1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

int main()
{

	int array[10];
	
	// 1. Taulukko ja tulostus heti
	for (int i = 0; i < 10; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";

	// 2. Alustus nolilla

	for (int i = 0; i < 10; i++)
	{
		array[i] = 0;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";

	// 3. Luen taulukon ohi

	for (int i = 10; i < 15; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";

	// 4. Kirjoitan taulukon ohi

	for (int i = 10; i < 15; i++)
	{
		array[i] = -1;
	}
	//tulee virheilmoitus sen jälkeen
}

