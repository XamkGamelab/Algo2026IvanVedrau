#include <iostream>
#include <vector>

//iterative without array
int fibNoArray(int n) {
    if (n <= 1)
        return n;

    int curr{ 2 };
    int prev{ 1 };
    int prev2{ 0 };

    for (int i = 2; i <= n; i++)
    {
        curr = prev + prev2;

        prev2 = prev;
        prev = curr;

    }

    return curr;
}

//iterative with array
 int fibWithArray(int n) {
        if (n <= 1)
            return n;

        std::vector<int> f(n + 1);
        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }

        return f[n];
    }


int main()
{
   std::cout << fibWithArray(7) << '\n';
   std::cout << fibNoArray(7) << '\n';
}
