#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>
#include <cmath>
namespace StringUtils
{
	using namespace std;
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
	
	inline int strToInt(const char* input)
	{
		int length = getStringLength(input);
		int sum = 0;
		for (int i = 0; i <= length; i++)
		{
			sum += pow(10,length) * (((int)(input[i])) - 57);
		}
		if (input[0] == '-')
		{
			sum = -sum;
		}
		return sum;
	}
	
}
#endif