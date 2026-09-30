#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

void simpleSort(float* a, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[j] < a[i])
                std::swap(a[j], a[i]);
}

int main() {
    int sizes[] = { 100000, 1000000, 10000000 };
    int runs = 1;

    for (int n : sizes) {
        std::vector<float> a(n);
        double total = 0;

        for (int r = 0; r < runs; ++r) {
            for (int k = 0; k < n; ++k)
                a[k] = (float)rand() / RAND_MAX;

            auto start = std::chrono::steady_clock::now();
            simpleSort(a.data(), n);
            auto end = std::chrono::steady_clock::now();

            total += std::chrono::duration<double>(end - start).count();
        }

        std::cout << "n = " << n << ": " << total / runs << " s\n";
    }
}

// Single-run times :
//   n = 100 000     ~11.4 s    (measured)
//   n = 1 000 000   ~9 min    (estimated: 100 000 time x 100)
//   n = 10 000 000  ~15 h     (estimated: 1 000 000 time x 100, not run)
// Time grows ~100x when n grows 10x

// Testing done in Release mode, debugger will produce the results in 5 - 10 times longer