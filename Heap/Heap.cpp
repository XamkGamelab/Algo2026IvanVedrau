#include <chrono>
#include <iostream>
#include <random>
#include <stdexcept>
#include <utility>
#include <vector>

class Heap {
public:
    void reserve(std::size_t n) { data.reserve(n); }
    bool empty() const { return data.empty(); }
    std::size_t size() const { return data.size(); }

    void insert(int value) 
    {
        data.push_back(value);
        siftUp(data.size() - 1);
    }

    int delMin() 
    {
        if (data.empty()) 
            throw std::out_of_range("delMin on empty heap");
        int min = data[0];
        data[0] = data.back();
        data.pop_back();

        if (!data.empty()) 
            siftDown(0);

        return min;
    }

    void print() const 
    {
        for (int v : data) 
            std::cout << v << ' ';

        std::cout << '\n';
    }

private:
    std::vector<int> data;

    void siftUp(std::size_t i) 
    {
        while (i > 0) {
            std::size_t parent = (i - 1) / 2;

            if (data[parent] <= data[i]) 
                break;

            std::swap(data[parent], data[i]);

            i = parent;
        }
    }

    void siftDown(std::size_t i) 
    {
        const std::size_t n = data.size();
        while (true) {
            std::size_t left = 2 * i + 1;
            std::size_t right = left + 1;
            std::size_t smallest = i;

            if (left < n && data[left] < data[smallest]) 
                smallest = left;

            if (right < n && data[right] < data[smallest]) 
                smallest = right;

            if (smallest == i) 
                break;

            std::swap(data[i], data[smallest]);
            i = smallest;
        }
    }
};

std::vector<int> heapSort(const std::vector<int>& input) {
    Heap heap;

    heap.reserve(input.size());
    for (int v : input) 
        heap.insert(v);

    std::vector<int> result;
    result.reserve(input.size());

    while (!heap.empty()) 
        result.push_back(heap.delMin());

    return result;
}

bool isSorted(const std::vector<int>& v) 
{
    for (std::size_t i = 1; i < v.size(); ++i)
        if (v[i - 1] > v[i]) 
            return false;
    return true;
}

void task81() 
{
    std::cout << "Task 8.1\n";
    const std::vector<int> input = { 17, 11, 6, 14, 22, 8, 1, 16, 10, 19, 12, 3, 5, 15, 13 };

    Heap heap;
    for (int v : input) 
        heap.insert(v);
    std::cout << "Heap array: ";
    heap.print();

    std::vector<int> result;
    while (!heap.empty()) 
        result.push_back(heap.delMin());

    std::cout << "Sorted:     ";
    for (int v : result) 
        std::cout << v << ' ';
    std::cout << "\n\n";
}

void task82() 
{
    std::cout << "Task 8.2\n";
    std::mt19937 rng(12345);
    std::uniform_int_distribution<int> dist(0, 1'000'000'000);

    for (std::size_t n : {100'000u, 1'000'000u, 10'000'000u}) {
        std::vector<int> input(n);
        for (int& v : input) 
            v = dist(rng);

        auto start = std::chrono::steady_clock::now();
        std::vector<int> result = heapSort(input);
        auto end = std::chrono::steady_clock::now();
        double ms = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << "n = " << n << "  time = " << ms << " ms  sorted = "
            << (isSorted(result) ? "yes" : "NO") << '\n';
    }
}

int main() 
{
    task81();
    task82();
    return 0;
}