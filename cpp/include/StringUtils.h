#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>
#include <cmath>
namespace StringUtils
{
	//calculate the length of string without \0
	inline int getStringLength(const char* input)
	{
		int i = 0;
		while (input[i] != '\0')
		{
			i++;
		}
		return i;
	}
	
	inline int getStringLength(string input)
	{
		return getStringLength(input.data());
	}

	inline bool contain(string input,char c)
	{
		return contain(input.data(),c);
	}

	inline int first(string input,char c)
	{
		return first(input.data(),c);
	}
	
	inline bool contain(const char* input,char c)
	{
		int i = 0;
		char it;
		while ((it = input[i]) != '\0')
		{
			if (it == c)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	
	inline int first(const char* input,char c)
	{
		int i = 0;
		char it;
		int flag = -1;
		while ((it = input[i]) != '\0')
		{
			if (it == c)
			{
				flag = i;
				break;
			}
		}
		return flag;
	}
	
	inline double strToDouble(const char* input)
	{
		int length = getStringLength(input);
		double sum = 0.0d;
		
		for (int i = length - 1,k = 0; i >= 0; i--, k++)
		{
			int num = (input[i]) - 48;
			if (num == 0)
				continue;
			sum += (double)pow(10,k) * num;
		}
		if (input[0] == '-')
		{
			sum = -sum;
		}
		return sum;
	}
	
}
#endif