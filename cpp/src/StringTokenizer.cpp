#include <StringTokenizer>

StringTokenizer::StringTokenizer(char[] input)
{
	m_data = ;
	for (int i = 0; i < sizeof(input)/sizeof(char); i++)
	{
		
	}
}

StringTokenizer::StringTokenizer(string input)
{
	m_data = new char[input.size()];
	m_size = input.size();
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = input[i];
	}
}

StringTokenizer::~StringTokenizer(){}

char[] StringTokenizer::next()
{
	if (hasNext())
		return m_data[++m_header];
	else
		return "0";
}

bool StringTokenizer::hasNext()
{
	if (m_header < size - 1))
		return true;
	return false;
}

void StringTokenizer::reset()
{
	header = 0;
}