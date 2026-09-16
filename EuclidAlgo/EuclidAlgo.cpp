// EuclidAlgo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int gcd(int a, int b) {
    int r = a % b;

    while (r > 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main()
{
    int a = 42; int b = 35;
    std::cout << gcd(a, b);
    return EXIT_SUCCESS;
}


