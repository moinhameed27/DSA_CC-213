#include <iostream>
#include <vector>
using namespace std;

int n;
int add(vector<int> &arr, int idx, int &tiltSum)
{
    if (idx >= n || arr[idx] == -1)
        return 0;
    int leftSum = add(arr, idx * 2, tiltSum);
    int rightSum = add(arr, (idx * 2) + 1, tiltSum);
    tiltSum += abs(leftSum - rightSum);
    return arr[idx] + leftSum + rightSum;
}

int findTilt(vector<int> &arr, int n)
{
    int tiltSum = 0;
    add(arr, 1, tiltSum);
    return tiltSum;
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, -1, -1, 5};
    n = arr.size();
    int ans = findTilt(arr, n);
    cout << ans << endl;
    return 0;
}