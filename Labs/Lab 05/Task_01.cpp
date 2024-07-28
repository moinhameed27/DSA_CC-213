#include <iostream>
#include <queue>
using namespace std;

int furthestBuilding(int *heights, int bricks, int ladders, int size)
{
    priority_queue<int> pq;
    int i;
    for (i = 0; i < size - 1; i++)
    {
        int diff = heights[i + 1] - heights[i];
        if (diff <= 0)
            continue;
        bricks -= diff;
        pq.push(diff);
        if (bricks < 0)
        {
            if (ladders > 0)
            {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            else
                break;
        }
    }
    return i;
}

int main()
{
    int size = 7;
    int arr[] = {4, 2, 15, 6, 10, 14, 12};
    int b = 13, l = 1;
    cout << furthestBuilding(arr, b, l, size) << endl;

    return 0;
}