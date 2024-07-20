#include <iostream>
#include <string>
#include <math.h>
#include "Stack.h"
using namespace std;

template <typename T>
T numberValidation(T &);

class Calculator
{
    string infix;
    string postfix;
    char delimiter;

    // Helper Functions
    int precedence(char);
    bool isOperator(char);
    bool isHigherPrecedence(char, char);

public:
    // Constructors
    Calculator() : infix(""), postfix(""), delimiter(' ') {}
    Calculator(string infix, char delimiter) : infix(infix), postfix(""), delimiter(delimiter) {}

    // Getters and Setters
    void setInfix(string infix) { this->infix = infix; }
    string getPostfix() { return postfix; }

    // Main Functions
    string infixToPostfix();
    double evaluation();
};

int Calculator::precedence(char symbol)
{
    switch (symbol)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

bool Calculator::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool Calculator::isHigherPrecedence(char op1, char op2)
{
    int p1 = precedence(op1);
    int p2 = precedence(op2);
    return p1 >= p2;
}

string Calculator::infixToPostfix()
{
    postfix.clear();
    string number;
    Stack<char> st;
    bool lastWasOperator = true;

    for (int i = 0; i < infix.size(); i++)
    {
        char symbol = infix[i];
        // Ignore Spaces
        if (symbol == ' ' || symbol == '\t')
            continue;
        // Ignore Invalid Characters
        if (!isdigit(symbol) && symbol != '.' && !isOperator(symbol) && symbol != '(' && symbol != ')')
            continue;

        // Store the Digits until there's any other character is seen
        if (isdigit(symbol) || symbol == '.')
        {
            number += symbol;
            lastWasOperator = false;
        }
        else
        {
            // Handle negative numbers
            if (symbol == '-' && lastWasOperator)
            {
                number += symbol;
                continue;
            }

            // Store the number in the postfix array if there's any
            if (!number.empty())
            {
                postfix += number + delimiter;
                number.clear();
            }

            switch (symbol)
            {
            case '(':
                st.push(symbol);
                lastWasOperator = true;
                break;
            case ')':
                while (!st.empty() && st.top() != '(')
                {
                    postfix += st.top();
                    postfix += delimiter;
                    st.pop();
                }
                st.pop();
                lastWasOperator = false;
                break;
            case '*':
            case '/':
            case '+':
            case '-':
                while (!st.empty() && isHigherPrecedence(st.top(), symbol))
                {
                    postfix += st.top();
                    postfix += delimiter;
                    st.pop();
                }
                st.push(symbol);
                lastWasOperator = true;
                break;
            default:
                break;
            }
        }
    }
    // If there's any number left in the string
    if (!number.empty())
        postfix += number + delimiter;

    // If there's any operator left in the stack
    while (!st.empty())
    {
        postfix += st.top();
        postfix += delimiter;
        st.pop();
    }
    return postfix;
}

double Calculator::evaluation()
{
    Stack<double> st;
    string str;
    for (int i = 0; i < postfix.size(); i++)
    {
        char symbol = postfix[i];

        if (isdigit(symbol) || symbol == '.' || isOperator(symbol) || symbol == '-')
            str += symbol;
        else if (symbol == delimiter)
        {
            if (!str.empty())
            {
                // Condition Examples : 23, .23, -23
                if (isdigit(str[0]) || (str[0] == '.' && str.size() > 1) || (str[0] == '-' && str.size() > 1))
                    st.push(stod(str));
                else if (isOperator(str[0]) && str.size() == 1)
                {
                    double a = st.top();
                    st.pop();
                    double b = st.top();
                    st.pop();
                    switch (str[0])
                    {
                    case '+':
                        st.push(b + a);
                        break;
                    case '-':
                        st.push(b - a);
                        break;
                    case '*':
                        st.push(b * a);
                        break;
                    case '/':
                        st.push(b / a);
                        break;
                    default:
                        break;
                    }
                }
                str.clear();
            }
        }
    }
    return st.top();
}

int main()
{
    Calculator C;
    string infix, postfix;
    double answer;
    int choice;
    while (1)
    {
        system("cls");
        cout << endl;
        cout << "Calculator Operations" << endl;
        cout << "1. Enter Infix Expression" << endl;
        cout << "2. Infix to Postfix" << endl;
        cout << "3. Evaluation" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        numberValidation(choice);
        cin.ignore();
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter the Infix Expression : ";
            infix.clear();
            getline(cin, infix);
            C.setInfix(infix);
            postfix = C.infixToPostfix();
            answer = C.evaluation();
            cout << "Expression Entered" << endl;
            break;
        case 2:
            cout << "Original Expression : " << infix << endl;
            cout << "Postfix Expression : " << postfix << endl;
            break;
        case 3:
            cout << "Original Expression : " << infix << endl;
            cout << "Evaluation : " << answer << endl;
            break;
        case 4:
            cout << "Exit..." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid Character. Enter Again" << endl;
            break;
        }
        cout << endl;
        system("pause");
    }
    return 0;
}

template <typename T>
T numberValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number <= 0)
                cout << "Enter positive number: " << endl;
            else
                validInput = true;
        }
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return number;
}
