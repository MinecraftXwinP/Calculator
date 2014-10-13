#ifndef	STRINGTOKENIZER_H
#define STRINGTOKENIZER_H

#include <string>
#include <list>
using namespace std;
class StringTokenizer
{
	public:
		StringTokenizer(char[]);
		StringTokenizer(string);
		
		~StringTokenizer();
		char* next();
		
		void reset();
		bool hasNext();
	protected:
	private:
		list<char*> m_data;
		auto m_header;
		int m_size;
		void init();
		void tokenize(char*);
		
};
#endif