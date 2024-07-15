#include <iostream>
#include "DLL1.h"
using namespace std;


int main()
{
    DLL1 obj;
    obj.insertLastNode(1);
    obj.insertLastNode(2);
    obj.insertLastNode(3);
    obj.insertLastNode(4);
    obj.insertLastNode(5);
    obj.print();
    obj.deleteNthNodeFromLast(4);
    obj.print();
return 0;
}