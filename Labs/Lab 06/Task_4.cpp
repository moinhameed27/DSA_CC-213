#include <iostream>
#include <vector>
using namespace std;

void copyValues(vector<int> &p, int val)
{
    vector<int> p2 = p;
    int a = 1;
    p[0] = val;
    for(int i = 0; i < p.size(); i++)
    {
        if(p2[i] != val)
            p[a++] = p2[i];
    }
}

void processQueries(int *q, int s, int m)
{
    vector<int> p(m);
    int ans[s];
    for(int i = 0; i < m; i++)
        p[i] = i + 1;
    for(int i = 0; i < s; i++)
    {
        int curr = q[i];
        for(int j = 0; j < m; j++)
        {
            if(p[j] == curr)
            {
                ans[i] = j;
                break;
            }
        }
        copyValues(p, curr);
    }
    for(int i = 0; i < s; i++)
        cout << ans[i] <<  " ";
}

int main()
{
    int q[] = {7, 5, 5, 8, 3};
    // int q[] = {2, 1, 4, 3};
    int size = 5;
    int m = 8;
    processQueries(q, size, m); 
    
return 0;
}