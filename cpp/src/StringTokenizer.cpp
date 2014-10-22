#include "StringTokenizer.h"
#include "StringUtils.h"

StringTokenizer::StringTokenizer(char input[])
{
	tokenize(input);
}

StringTokenizer::StringTokenizer(string input)
{
	tokenize(input.c_str());
}

void StringTokenizer::tokenize(const char* input)
{
	int size = StringUtils::getStringLength(input);
	for(int i = 0,j = 0; i <= size; i++)
	{
		if (input[i] == ' ' || i == size)
		{
			char* temp = new char[i - j + 1];
			temp[i - j] = '\0';
			for (int k = 0; k < i - j; k++)
			{
				temp[k] = input[j + k];
			}
			m_data.push_back(temp);
			m_size++;
			j = i + 1;
		}
	}
	this->reset();
}

StringTokenizer::~StringTokenizer()
{
}

void StringTokenizer::init()
{
}

char* StringTokenizer::next()
{
	if (&m_header == NULL)
	{
		m_header = m_data.begin();
	}
	return *m_header++;
}

bool StringTokenizer::hasNext()
{

	if (m_header != m_data.end())
	{	
		return true;
	}
	return false;
}

void StringTokenizer::reset()
{
	m_header = m_data.begin();
}

const char* StringTokenizer::dumpPrint()
{
	string output;
	while (this->hasNext())
	{
		output += this->next();
		output += " ";
	}
	
	return output.data();
	
}