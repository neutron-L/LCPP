#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "stack.hh"

using namespace std;

vector<string> split(const string &expression);

int evaluateExpression(const string &expression);

void processAnOperator(Stack<int> &operandStack, Stack<char> &operatorStack);

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    cout << expression << " = "
         << evaluateExpression(expression) << endl;

    return 0;
}

// split expression to operands and operators
vector<string> split(const string &expression)
{
    vector<string> tokens;
    string operand;

    for (const auto &c : expression)
    {
        if (isdigit(c))
            operand.append(1, c);
        else
        {
            if (operand.size())
            {
                tokens.push_back(operand);
                operand.clear();
            }
            if (!isspace(c))
            {
                string op;
                op.append(1, c);
                tokens.push_back(op);
            }
        }
    }

    if (operand.size())
        tokens.push_back(operand);
    return tokens;
}

int evaluateExpression(const string &expression)
{
    vector<string> tokens = std::move(split(expression));
    Stack<int> operandStack;
    Stack<char> operatorStack;

    for (auto &token : tokens)
    {
        if (token[0] == '+' || token[0] == '-')
        {
            while (!operatorStack.empty() &&
                   (operatorStack.peek() == '+' || operatorStack.peek() == '-' || operatorStack.peek() == '*' || operatorStack.peek() == '/'))
            {
                processAnOperator(operandStack, operatorStack);
            }
            operatorStack.push(token[0]);
        }
        else if (token[0] == '*' || token[0] == '/')
        {
            while (!operatorStack.empty() &&
                   (operatorStack.peek() == '*' || operatorStack.peek() == '/'))
            {
                processAnOperator(operandStack, operatorStack);
            }
            operatorStack.push(token[0]);
        }
        else if (token[0] == '(')
        {
            operatorStack.push(token[0]);
        }
        else if (token[0] == ')')
        {
            while (!operatorStack.empty() && operatorStack.peek() != '(')
                processAnOperator(operandStack, operatorStack);
            operatorStack.pop();
        }
        else // operand, push to operand stack
            operandStack.push(std::stoi(token));
    }

    while (!operatorStack.empty())
        processAnOperator(operandStack, operatorStack);
    return operandStack.peek();
}

void processAnOperator(Stack<int> &operandStack, Stack<char> &operatorStack)
{
    char op = operatorStack.pop();
    int b = operandStack.pop();
    int a = operandStack.pop();

    switch (op)
    {
    case '+':
        operandStack.push(a + b);
        break;
    case '-':
        operandStack.push(a - b);
        break;
    case '*':
        operandStack.push(a * b);
        break;
    case '/':
        operandStack.push(a / b);
        break;
    default:
        break;
    }
}