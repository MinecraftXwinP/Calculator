#ifndef STACK_H
#define STACK_H
#define _DEFAULT_INTERVAL_ 5
#define _DEFAULT_INIT_SIZE_ 5

template <typename T>
class Stack
{
    public:
        Stack();
        Stack(int,int);
        virtual ~Stack();
        void put(T);
        T pop();
		const T peek();
        void clear();
        void setInterval(int);
        bool hasNext();
		int getCapability();
    protected:
    private:

        int m_elementSize;
		int m_arraySize;
        int m_interval;
        int m_top;

        T* data;

        void init(int,int);
        void arangeArray();
};
#endif // STACK_H
#include <Stack.tpp>
