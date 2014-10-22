#include <iostream>
#include <cstring>
#include "Stack.h"
#include "StringTokenizer.h"
#include "StringUtils.h"

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
string translateToPostfix(string);
int calculate(string);
int main(int argc,char** args)
{
	using namespace std;
	cout << "Input:" << endl;
	char* in = new char[256];
	cin.getline(in,256);
	string postfix(translateToPostfix(in));
	cout << "Postfix:" << postfix << endl;
    cout << "Output: " << calculate(postfix) << endl;
	
}

string translateToPostfix(string input)
{
	Stack<char> stack;
    string output;
	StringTokenizer tokenizer(input);
	while (tokenizer.hasNext())
	{
		char* token = tokenizer.next();
		cout << "parse " << token << endl;
		if (StringUtils::contain(token,'('))
		{
			stack.put('(');
		}
		else if (StringUtils::contain(token,')'))
		{
			char out;
            while((out = stack.pop()) != '(')
            {
                output += out;
				output += " ";
            }
		}
		else if (StringUtils::contain(token,'+'))
		{
			char top = stack.peek();
				while(getPriority(top) > 0 && stack.getCapability() != -1)
				{
					output += stack.pop();
					output += " ";
					top = stack.peek();
				}
				stack.put('+');
		}
		else if (StringUtils::contain(token,'-'))
		{
			char top = stack.peek();
				while(getPriority(top) > 0 && stack.getCapability() != -1)
				{
					output += stack.pop();
					output += " ";
					top = stack.peek();
				}
				stack.put('-');
		}
		else if (StringUtils::contain(token,'*'))
		{
			stack.put('*');
		}
		else if (StringUtils::contain(token,'/'))
		{
			stack.put('/');
		}
		else
		{
			output += token;
			output += " ";
		}
	}
	while(stack.getCapability() != -1)
	{
		output += stack.pop();
	}
	cout << "return :" << output << endl;
	return output;
}

int calculate(string postfix)
{
	StringTokenizer tokenizer(postfix);
	Stack<int> stack;
	while (tokenizer.hasNext())
	{
		char* token = tokenizer.next();
		if (StringUtils::contain(token, '+'))
		{
			stack.put(stack.pop() + stack.pop());
		}
		else if (StringUtils::contain(token, '-'))
		{
			stack.put(stack.pop() - stack.pop());
		}
		else if (StringUtils::contain(token, '*'))
		{
			stack.put(stack.pop() * stack.pop());
		}
		else if (StringUtils::contain(token, '/'))
		{
			int rv = stack.pop();
			int lv = stack.pop();
			stack.put(lv/rv);
		}
		else
		{
			stack.put(StringUtils::strToInt(token));
		}
	}
	return stack.pop();
}
