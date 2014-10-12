#include <iostream>
#include <cstring>
#include "Stack.h"
using namespace std;

int getPriority(char op)
{
    if (op == '+' || op == '-' || op == '(')
    {
        return 0;
    } else if (op == '/' || op == '*')
    {
        return 1;
    }
}



int main(int argc,char** args)
{


    cout << "Output: " << output << endl;
}

string translateToPostfix(string input)
{
	Stack<char> stack;
    string output;
	bool flag;
    if(argc != 2)
    {
        cout << "Usage: translate <input> " << endl;
        return 0;
    }
	int i = 0;
    while (true)
    {
		intput[i];
		if (c == '\0')
			break;
        switch (c)
        {
            case '(':
                stack.put('(');
                break;
            case ')':
                char out;
                while((out = stack.pop()) != '(')
                {
                    output += out;
                }
                break;
            case '+':
			{
                //TODO compare
				char top = stack.peek();
				while(getPriority(top) > 0 && stack.getCapability() != -1)
				{
					output += stack.pop();
					top = stack.peek();
				}
				stack.put('+');
				break;
			}
            case '-':
			{
				char top = stack.peek();
				while(getPriority(top) > 0 && stack.getCapability() != -1)
				{
					output += stack.pop();
					top = stack.peek();
				}
				stack.put('-');
				break;
			}
            case '*':
				stack.put('*');
				break;
            case '/':
				stack.put('/');
				break;
			default:
				output += c;
        }
		i++;
    }
	while(stack.getCapability() != -1)
	{
		output += stack.pop();
	}
}

int calculate(string postfix)
{
	Stack<int> stack;
	for(int i = 0; i < postfix.size(); i++)
	{
		switch (postfix[i])
		{
			case '+':
				break;
			case '-':
				break;
			case '*':
				break;
			case '/':
				break;
			default:
				stack.put(
		}
	}
}
