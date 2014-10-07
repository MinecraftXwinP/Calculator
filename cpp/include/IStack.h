#ifndef ISTACK_H
#define ISTACKH

template <typename T>
class IStack<T>
{
	public:
		virtual void push(T);
		virtual T pop();
		virtual void clear();
		virtual bool isEmpty();
}


#endif