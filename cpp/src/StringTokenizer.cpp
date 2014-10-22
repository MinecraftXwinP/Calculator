#include "StringTokenizer.h"
#include "StringUtils.h"
#include <iostream>

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
	using namespace std;
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
			cout << "sub string: \"" << temp << "\"" << endl;
			m_size++;
			j = i + 1;
		}
	}
	cout << "tokenizer done!" << endl;
	this->reset();
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
		cout << "hasNext" << endl;
		return true;
	}
	cout << "O" << endl;
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