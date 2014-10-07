#include "Stack.h"
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
    data = new T[m_interval];

}
template<class T>
void Stack<T>::setInterval(int i)
{
    m_interval = i;
}
template<class T>
void Stack<T>::arangeArray()
{
    T newly[] = new T[data.length + m_interval];
    for (int i = 0;i < data.length; i++)
    {
        newly[i] = data[i];
    }
    delete [] data;
    data = newly;
}
template<class T>
void Stack<T>::put(T element)
{
    while (true)
    {
        if (m_top >= data.length - 1)
        {
            arangeArray();
            continue;
        } else
        {
            data[m_top + 1] = element;
            m_top++;
            return;
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
