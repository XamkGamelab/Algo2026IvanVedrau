#include <iostream>
#include <vector>
#include <random>

#include <chrono>

int linearSearch(const std::vector<int>& nums, int target)
{

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target) 
            return i;
    }

    return -1;
}

int binarySearch(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else
            right = mid;
    }
    return -1;
}

int main()
{   
    long long resultBinary {0};
    long long resultLinear {0};
    //std::vector<int> nums{ 1, 4, 6, 11, 13, 16, 19, 20, 25, 27, 29, 30, 32, 36, 39, 42, 45, 48, 49, 53 };
    
    std::vector<int> sizes{ 100000, 1000000, 10000000 };

    std::random_device rd;
    std::mt19937 generation(rd());

    for (int size : sizes) {
        std::vector<int> nums2(size);
        
        std::uniform_int_distribution<int> dist(0, static_cast<int>(nums2.size() - 1));

        int index = dist(generation);


        for (int i = 0; i < nums2.size(); i++)
        {
            nums2[i] = i;
        }
        int target = nums2[index];

        auto startBinary = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            resultBinary += binarySearch(nums2, target);
        }

        auto endBinary = std::chrono::steady_clock::now();

        auto elapsedBinary = std::chrono::duration_cast<std::chrono::nanoseconds>(endBinary - startBinary).count();

        std::cout << "average for Binary: " << elapsedBinary / 10000 << " ns\n";
        std::cout << "result for Binary: " << resultBinary << '\n';

        resultBinary = 0;

        auto startLinear = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            resultLinear += linearSearch(nums2, target);
        }

        auto endLinear = std::chrono::steady_clock::now();

        auto elapsedLinear = std::chrono::duration_cast<std::chrono::nanoseconds>(endLinear - startLinear).count();

        std::cout << "average for Linear: " << elapsedLinear / 10000 << " ns\n";
        std::cout << "result for Linear: " << resultLinear << '\n';

        resultLinear = 0;
    }
    
    /*
    int binaryResult = binarySearch(nums, target);
    int linearResult = linearSearch(nums, target);
    if (linearResult == -1) {
        std::cout << "No such number in given array" << '\n';
    }
    else
        std::cout << "Number at index " << linearResult << '\n';
    
    std::cout << binaryResult << '\n';
*/
    return 0;
}


