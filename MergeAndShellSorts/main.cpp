#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

#include "sorting.hpp"

void print(const std::vector<int>& arr)
{
    for (int x : arr)
        std::cout << x << " ";
    std::cout << "\n";
}

void measure(const std::string& method, std::vector<int> data)
{
    auto start = std::chrono::steady_clock::now();

    if (method == "Shell sort")
        shellSort(data);
    else if (method == "Merge sort")
        mergeSort(data, 0, static_cast<int>(data.size()) - 1);
    else
        std::sort(data.begin(), data.end());

    auto end = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(end - start).count();

    std::cout << "  " << method << ": " << ns / 1000000 << " ms, " << ns / data.size() << " ns per item\n";
}

void measureAll(const std::string& order, const std::vector<int>& data)
{
    std::cout << " " << order << "\n";
    measure("Shell sort", data);
    measure("Merge sort", data);
    measure("std::sort", data);
}

int main()
{
    std::vector<int> test = { 9, 2, 6, 5, 7, 1 };

    std::vector<int> a = test;
    shellSort(a);
    std::cout << "Shell sort: ";
    print(a);

    std::vector<int> b = test;
    mergeSort(b, 0, static_cast<int>(b.size()) - 1);
    std::cout << "Merge sort: ";
    print(b);

    std::vector<int> c = test;
    std::sort(c.begin(), c.end());
    std::cout << "std::sort:  ";
    print(c);

    std::vector<int> sizes = { 100, 10000, 1000000 };

    for (int n : sizes)
    {
        std::vector<int> ordered(n);
        std::vector<int> reversed(n);
        std::vector<int> random(n);

        for (int i = 0; i < n; i++)
        {
            ordered[i] = i;
            reversed[i] = n - i;
            random[i] = std::rand();
        }

        std::cout << "\nSize " << n << "\n";

        measureAll("Ordered", ordered);
        measureAll("Reversed", reversed);
        measureAll("Random", random);
    }

    return 0;
}