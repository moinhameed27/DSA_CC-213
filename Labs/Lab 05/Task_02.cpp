#include <iostream>
// #include <math.h>
using namespace std;

int minOperations(int *nums, int n)
{
    int operations = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] <= nums[i + 1])
            continue;
        int parts = nums[i] / nums[i + 1];
        if (nums[i] % nums[i + 1] != 0)
            parts++;
        operations += parts - 1;
        nums[i] = nums[i] / parts;
    }
    return operations;
}

int main()
{
    int n1 = 3, n2 = 3;
    int arr[] = {6, 18, 6};
    int arr2[] = {2, 4, 8};

    cout << minOperations(arr, n1) << endl;
    cout << minOperations(arr2, n2) << endl;
    return 0;
}