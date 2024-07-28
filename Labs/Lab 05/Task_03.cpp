#include <iostream>
#include <vector>
using namespace std;

int clumsyFactorial(int n)
{
    if (n == 1 || n == 2)
        return n;
    int curr = 0, ans = 1;
    vector<int> arr, arr2;

    while (n > 0)
    {
        if (curr % 4 == 0)
            cout << "1" << endl, ans = n * (n - 1);
        else if (curr % 4 == 1)
            cout << "2" << endl, ans /= (n - 1);
        else if (curr % 4 == 2)
            cout << "3" << endl, arr2.push_back(n - 1);
        else
        {
            cout << "ans : " << ans << endl;
            cout << "n : " << n << endl;
            arr.push_back(ans);
            if (n == 2)
                arr.push_back(1);
            ans = 0;
        }
        curr++;
        n--;
        if (n - 1 == 0)
            break;
    }

    if (ans != 0)
        arr.push_back(ans);

    ans = arr[0];
    for (int i = 1; i < arr.size(); i++)
        ans -= arr[i];
    
    for(int i = 0; i < arr2.size(); i++)
        ans += arr2[i];

    return ans;
}

int main()
{
    cout << clumsyFactorial(5) << endl;

    return 0;
}