#include <iostream>
#include <string>
using namespace std;

string getLargestNumber(string str, int k)
{
    string ans = "";
    int n = str.size();
    if (n == 0)
        return ans;
    if (k == 0)
        return str;
    if (k >= n)
        return "0";
    int i = 0;
    while (k > 0)
    {
        if (i == n - 1)
        {
            str.pop_back();
            k--;
            i = 0;
        }
        else if (str[i] < str[i + 1])
        {
            str.erase(i, 1);
            k--;
            i = 0;
        }
        else
            i++;
    }
    return str;
}

int main()
{
    string str = "2061303";
    string str2 = "412890054";
    string str3 = "100007890";
    cout << getLargestNumber(str, 2) << endl;
    cout << getLargestNumber(str2, 5) << endl;
    cout << getLargestNumber(str3, 5) << endl;

    return 0;
}