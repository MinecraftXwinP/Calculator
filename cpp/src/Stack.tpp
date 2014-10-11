#include <iostream>
using namespace std;
template<class T>
Stack<T>::Stack()
{
    init(_DEFAULT_INIT_SIZE_,_DEFAULT_INTERVAL_);
}
template<class T>
Stack<T>::Stack(int initSize,int interval)
{
    init(initSize,interval);
}
template<class T>
Stack<T>::~Stack()
{
    delete [] data;
}
template<class T>
void Stack<T>::init(int initSize,int interval)
{
    m_elementSize = sizeof(T);
    m_interval = interval;
    m_top = -1;
	m_arraySize = initSize;
    data = new T[initSize];

}
template<class T>
void Stack<T>::setInterval(int i)
{
    m_interval = i;
}
template<class T>
void Stack<T>::arangeArray()
{
	cout << "arranging" << endl;
    T* newly = new T[m_arraySize + m_interval];
    for (int i = 0;i < m_arraySize; i++)
    {
        newly[i] = data[i];
    }
	m_arraySize += m_interval;
    delete [] data;
    data = newly;
}
template<class T>
void Stack<T>::put(T element)
{
    while (true)
    {
        if (m_top >= m_arraySize)
        {
			cout << m_top << endl;
			cout << sizeof(*data) << endl;
			cout << m_elementSize << endl;
            arangeArray();
            continue;
        } else
        {
			m_top++;
            data[m_top] = element;
            break;
        }

    }
}
template<class T>
T Stack<T>::pop()
{
    T t = data[m_top];
    m_top--;
    return t;
}
template<class T>
void Stack<T>::clear()
{
    m_top = -1;
}
template<class T>
bool Stack<T>::hasNext()
{
    if (m_top < 0)
    {
        return false;
    } else
    {
        return true;
    }
}
template<class T>
const T Stack<T>::peek()
{
	return data[m_top];
}
template<class T>
int Stack<T>::getCapability()
{
	return m_top;
}
