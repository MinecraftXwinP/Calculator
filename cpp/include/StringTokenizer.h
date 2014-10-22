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
		const char* dumpPrint();
		void reset();
		bool hasNext();
	protected:
	private:
		list<char*> m_data;
		list<char*>::iterator m_header;
		int m_size;
		void init();
		void tokenize(const char*);
		
};
#endif