#include <iostream>
#include "Queue CDLL.h"
using namespace std;


int main()
{
    Queue q;
    q.pushFront(1);
    q.pushFront(2);
    q.pushFront(3);
    // q.pushFront(4);
    q.print();
    cout << endl;

    q.pushMiddle(-2);

    q.pushBack(-9);

    q.print();
    cout << endl;

    q.popFront();
    q.print();
    cout << endl;

    q.popMiddle();
    q.print();
    cout << endl;

    q.popBack();
    q.print();
    cout << endl;

    
return 0;
}