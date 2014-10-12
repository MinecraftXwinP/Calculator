#ifndef
#define STRINGTOKENIZER_H

#include <string>
class StringTokenizer
{
	public:
		StringTokenizer(char[]);
		StringTokenizer(string);
		~StringTokenizer();
		char[] next();
		
	protected:
	private:
		char** m_data;
		int m_header;
		int m_size;
}
#endif