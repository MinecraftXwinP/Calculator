#include <iostream>
#include <cstring>
#include "Stack.h"
using namespace std;

int priorityTest(char op)
{
    if (op == '+' || op == '-')
    {
        return 0;
    } else if (op == '/' || op == '*')
    {
        return 1;
    }
}

int main(int argc,char** args)
{
    Stack<char> stack;
    string output;
    string input(args[1]);
    if(argc != 2)
    {
        cout << "Usage: translate <input> " << endl;
        return 0;
    }

    for (unsigned i = 0; i < input.length() ; i++)
    {
        char c = args[1][i];
        switch (c)
        {
            case '(':
                stack.put('(');
                break;
            case ')':
                char out;
                while((out = stack.pop()) != '(')
                {
                    output + out;
                }
                break;
            case '+':
                //TODO compare
                break;
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
        }

    }

    cout << output << endl;
}
