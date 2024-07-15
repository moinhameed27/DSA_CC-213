#include <iostream>
using namespace std;
#include "SLL1.h"

int main()
{
    cout << "Task 1" << endl;
    SLL1 obj;
    obj.insertLastNode(1);
    obj.insertLastNode(2);
    obj.insertLastNode(3);
    obj.insertLastNode(4);
    obj.insertLastNode(5);
    obj.print();
    obj.reverseSinglyLinkedList();
    obj.print();
    obj.reverseSinglyLinkedList();
    obj.zigzagPattern();
    obj.print();

    cout << "Task 2" << endl;
    SLL1 obj2;
    obj2.insertLastNode(11);
    obj2.insertLastNode(15);
    obj2.insertLastNode(20);
    obj2.insertLastNode(5);
    obj2.insertLastNode(10);
    obj2.print();
    obj2.reverseSinglyLinkedList();
    obj2.print();
    obj2.reverseSinglyLinkedList();
    obj2.zigzagPattern();
    obj2.print();

    cout << "----" << endl;
    SLL1 obj3;
    obj3.insertLastNode(20);
    obj3.insertLastNode(15);
    obj3.insertLastNode(10);
    obj3.insertLastNode(8);
    obj3.insertLastNode(5);
    obj3.insertLastNode(2);
    obj3.print();
    obj3.reverseSinglyLinkedList();
    obj3.print();
    obj3.reverseSinglyLinkedList();
    obj3.zigzagPattern();
    obj3.print();

    

    return 0;
}