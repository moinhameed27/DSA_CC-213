#include <iostream>
#include "Stack.h"
using namespace std;

string eliminateConsecutiveDuplicates(const string &input)
{
    Stack<char> stack;
    string answer = "";
    for (char ch : input)
    {
        if (stack.empty() || (stack.top() != ch && abs(stack.top() - ch) != 32))
        {
            stack.push(ch);
            answer += ch;
        }
    }
    return answer;
}

int main()
{
    system("cls");
    cout << "----------> Eliminate Consecutive Duplicates <----------" << endl;
    cout << "Enter the String: ";
    string input;
    cin >> input;
    string answer = eliminateConsecutiveDuplicates(input);
    cout << answer << endl;
    cout << endl;
    system("pause");

    return 0;
}