#include "StringTokenizer.h"

StringTokenizer::StringTokenizer(char input[])
{
	init();
	tokenize(input);
}

StringTokenizer::StringTokenizer(string input)
{
	init();
	tokenize(input.data());
}

void StringTokenizer::tokenize(char* input)
{
	int i = 0;
	int j = 0;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
		{
			char* temp = char[i - j];
			for (int k = j,t = 0; k <= i; k++,t++)
			{
				temp[t] = input[k];
			}
			m_data.push_back(temp);
			j = i;
		}
	}
	
}

StringTokenizer::~StringTokenizer()
{
	delete &m_data;
}

void StringTokenizer::init()
{
}

char* StringTokenizer::next()
{
	if (m_header == 0)
	{
		m_header = m_data.begin();
	}
	return *m_header++;
}

bool StringTokenizer::hasNext()
{
	if (m_header != m_data.end())
		return true;
	return false;
}

void StringTokenizer::reset()
{
	m_header = m_data.begin();
}