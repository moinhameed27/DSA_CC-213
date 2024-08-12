#include <iostream>
using namespace std;

int IDMapping(int i, int j, int rStart, int cStart, int n)
{
    i -= rStart;
    j -= cStart;
    int idx = (i * n) + j;
    return idx;
}

int main()
{
    int ans = IDMapping(-2, -4, -4, -4, 4);
    cout << ans << endl;
    return 0;
}