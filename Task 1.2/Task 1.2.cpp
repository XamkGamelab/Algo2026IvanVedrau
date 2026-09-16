// Task 1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

int main()
{
    //1. Dynaamisesti varattu taulukko, 10 alkiota, alustettu nollilla
    int* array = new int[10]();

    
    for (int i = 0; i < 10; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";

    // 2. sis. muutos ja tulostus

    for (int i = 0; i < 10; ++i)
    {
        array[i] = (i + 1); 
    }
        
    
    for (int i = 0; i < 10; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";

    // 3. koon muutos 20 alkioon niin, et 10 eka säilyy

    int* newArr = new int[20]();

    for (int i = 0; i < 10; ++i)
        newArr[i] = array[i];

    delete[] array;
    array = newArr;

    for (int i = 0; i < 20; ++i) 
    {
        std::cout << newArr[i] << " ";
    }
    std::cout << "\n\n";

    delete[] array;
    array = nullptr;

    return 0;

}


