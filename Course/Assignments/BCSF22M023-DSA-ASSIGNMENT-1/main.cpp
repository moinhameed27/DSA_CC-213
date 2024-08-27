#include <iostream>
#include "Stack.h"
#include <string>
#include <fstream>
using namespace std;

template <typename T>
T numberValidation(T &);

const char DELIMITER = ' ';

// Class variableNode to store Variable Name and its Value
class VariableNode
{
public:
    string variableName;
    double value;
    VariableNode *next;

    VariableNode(string name, double val) : variableName(name), value(val), next(nullptr) {}
};

// Function to determine precedence of operator
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }

// Function to check if an operator has higher precedence than the other
bool isHigherPrecedence(char op1, char op2)
{
    int p1 = precedence(op1);
    int p2 = precedence(op2);
    return p1 >= p2;
}

// Function to convert infix to postfix
string infixToPostfix(string &infix)
{
    Stack<char> operatorStack;
    string postfix = "", variable = "";
    bool lastWasOperator = true;

    for (int i = 0; i < infix.size(); i++)
    {
        char currentChar = infix[i];
        // Ignore Spaces
        if (currentChar == ' ' || currentChar == '\t')
            continue;
        // Ignore Invalid Characters
        else if (!isalnum(currentChar) && currentChar != '.' && !isOperator(currentChar) && currentChar != '(' && currentChar != ')')
            continue;

        // Store the characters until there's any operator is seen
        else if (isalnum(currentChar) || currentChar == '.')
        {
            variable += currentChar;
            lastWasOperator = false;
        }
        else
        {
            // Negative Number
            if (currentChar == '-' && lastWasOperator)
            {
                variable += currentChar;
                lastWasOperator = false;
                continue;
            }

            // Store the number/variable in the postfix array if there's any
            if (!variable.empty())
            {
                postfix += variable + DELIMITER;
                variable.clear();
            }

            switch (currentChar)
            {
            case '(':
                operatorStack.push(currentChar);
                lastWasOperator = true;
                break;
            case ')':
                while (!operatorStack.empty() && operatorStack.top() != '(')
                {
                    postfix += operatorStack.top();
                    postfix += DELIMITER;
                    operatorStack.pop();
                }
                operatorStack.pop();
                lastWasOperator = false;
                break;
            case '*':
            case '/':
            case '+':
            case '-':
                while (!operatorStack.empty() && isHigherPrecedence(operatorStack.top(), currentChar))
                {
                    postfix += operatorStack.top();
                    postfix += DELIMITER;
                    operatorStack.pop();
                }
                operatorStack.push(currentChar);
                lastWasOperator = true;
                break;
            default:
                break;
            }
        }
    }
    // If there's any number left in the string
    if (!variable.empty())
        postfix += variable + DELIMITER;

    // If there's any operator left in the stack
    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        postfix += DELIMITER;
        operatorStack.pop();
    }
    return postfix;
}

// Function to get the value of a variable from the linked list
double getVariableValue(VariableNode *head, string &variableName)
{
    VariableNode *mover = head;
    while (mover)
    {
        if (mover->variableName == variableName)
            return mover->value;
        mover = mover->next;
    }
    return -923;
}

// Function to evaluate postfix expression
double evaluatePostfix(string &postfix, VariableNode *variableList)
{
    Stack<double> numberStack;
    string variable;
    bool negativeVariable = false;

    for (int i = 0; i < postfix.size(); i++)
    {
        char currentCharacter = postfix[i];

        if (isalnum(currentCharacter) || currentCharacter == '.')
            variable += currentCharacter;
        // Negative Number
        else if (currentCharacter == '-' && (isalnum(postfix[i + 1])))
        {
            negativeVariable = true;
            continue;
        }
        else if (currentCharacter == DELIMITER)
        {
            if (!variable.empty())
            {
                double value;
                // If the variable is a number
                if (isdigit(variable[0]) || (variable[0] == '-' && isdigit(variable[1])))
                {
                    value = stod(variable);
                    if (negativeVariable)
                        value *= -1;
                    numberStack.push(value);
                }
                // If the variable is an alphabet
                else if (isalpha(variable[0]))
                {
                    value = getVariableValue(variableList, variable);
                    if (negativeVariable)
                        value *= -1;
                    numberStack.push(value);
                }
                variable.clear();
            }
        }
        else if (isOperator(currentCharacter))
        {
            double a = numberStack.top();
            numberStack.pop();

            double b = numberStack.top();
            numberStack.pop();

            switch (currentCharacter)
            {
            case '+':
                numberStack.push(b + a);
                break;
            case '-':
                numberStack.push(b - a);
                break;
            case '*':
                numberStack.push(b * a);
                break;
            case '/':
                numberStack.push(b / a);
                break;
            default:
                break;
            }
        }
    }
    return numberStack.top();
}

// Function to extract variables from postfix expression
VariableNode *extractVariables(string &postfix)
{
    VariableNode *head = nullptr;
    VariableNode *tail = nullptr;
    string variable = "";
    bool negativeVariable = false;

    for (int i = 0; i < postfix.size(); i++)
    {
        char currentCharacter = postfix[i];
        if (currentCharacter == '-' && isalpha(postfix[i + 1]))
        {
            negativeVariable = true;
            continue;
        }
        // e.g celsius, m1, m2
        else if (isalpha(currentCharacter) || (isdigit(currentCharacter) && !variable.empty()))
            variable += currentCharacter;
        else if (currentCharacter == DELIMITER)
        {
            if (!variable.empty())
            {
                double value;
                value = getVariableValue(head, variable);
                // If the variable is not found in the linked list, ask the user to enter the value
                if (value == -923)
                {
                    cout << "Enter value for " << variable << ": ";
                    numberValidation(value);
                    cin.ignore();
                }
                if (negativeVariable)
                    value *= -1;

                VariableNode *newNode = new VariableNode(variable, value);
                // If the linked list is empty
                if (!head)
                {
                    head = newNode;
                    tail = head;
                }
                else
                {
                    tail->next = newNode;
                    tail = tail->next;
                }
                negativeVariable = false;
                variable.clear();
            }
        }
    }

    return head;
}

int main()
{
    string infix;
    string postfix;
    double answer;
    int choice;
    while (1)
    {
        system("cls");
        cout << endl;
        cout << "----------> Infix to Postfix <----------" << endl;
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
        {

            cout << "Enter the Infix Expression : ";
            infix.clear();
            getline(cin, infix);
            postfix = infixToPostfix(infix);
            VariableNode *node = extractVariables(postfix);
            answer = evaluatePostfix(postfix, node);
            cout << "Expression Entered" << endl;
            break;
        }
        case 2:
            cout << "Original Expression : " << infix << endl;
            cout << "Postfix Expression : " << postfix << endl;
            break;
        case 3:
            cout << "Original Expression : " << infix << endl;
            cout << "Evaluation : " << answer << endl;
            break;
        case 4:
            cout << "Exiting..." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice. Enter Again" << endl;
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
