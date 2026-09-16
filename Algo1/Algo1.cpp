// Algo1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

	int array[100];

	for (int i = 0; i < 10000000; i++)
	{
		array[i] = i;
	}

	for (int i = 0; i < 10000000; i++)
	{
		std::cout << "array " << array[i] << std::endl;
	}
}

