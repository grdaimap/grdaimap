#include "grdaimap.h"
#include <iostream>
using namespace std;
template <class T>
grd_stack<T>::grd_stack(int size , long numnode )
{
    stack = new T[size];
    if (!stack)
    {
        cout << numnode << "空间不足" << endl;
        exit(1);
    }
    length = size;
    tos = 0;
}
template <class T>
void grd_stack<T>::push(T e)
{
    if (tos == length)
    {
        cout << numnode << "栈满!清除栈底!" << endl;
        Destack();
    }
    stack[tos++] = e;
}
template <class T>
T grd_stack<T>::pop()
{
    if (tos == 0)
    {
        cout << numnode << "栈空!" << endl;
        return 0;
    }
    T e;
    e = stack[--tos];
	return e;
}
template <class T>
void grd_stack<T>::Destack()
{
    int i;
    for (i = 0; i < tos - 1; i++)
    {
        stack[i] = stack[i + 1];
    }
    tos--;
}
template <class T>
T grd_stack<T>::get()
{
    if (tos > 0)
    {
        return stack[tos - 1];
    }
    else
        return 0;
}
template <class T>
grd_queue<T>::grd_queue(int size , long numnode )
{
    queue = new T[size];
    if (!queue)
    {
        cout << numnode << "空间不足!" << endl;
        exit(1);
    }
    length = size;
    front = 0;
    rear = 1;
}
template <class T>
void grd_queue<T>::enque(T e)
{
    if (rear - front == length - 1)
    {
        cout << numnode << "队列满!清除队头!" << endl;
        front = (front + length - 1) % length;
    }
    queue[rear] = e;
    rear = (rear + length + 1) % length;
}
template <class T>
T grd_queue<T>::deque()
{
    if (cond() == 0)
    {
        cout << numnode << "队列空!" << endl;
        return 0;
    }
    front = (front + length + 1) % length;
    return queue[front];
}
template <class T>
T grd_queue<T>::getfront()
{
    if (cond() == 0)
    {
        cout << numnode << "队列空!" << endl;
        return 0;
    }
    int n = (front + length + 1) % length;
    return queue[n];
}
template <class T>
T grd_queue<T>::getrear()
{
    if (cond() == 0)
    {
        cout << numnode << "队列空!" << endl;
        return 0;
    }
    int n = (rear + length - 1) % length;
    return queue[n];
}