#include "grdaimap.h"
#include <iostream>
#include <random> //C++11以上才可使用
using namespace std;
template <class T>
grd_stack<T>::grd_stack(int size, long numnode)
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
grd_queue<T>::grd_queue(int size, long numnode)
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
template <class T>
grd_node<T>::grd_node(long num, int type, int size)
{
    numnode = num;
    nodetype = type;
    if (type = 0)
    {
        ner = int(0);
    }
    if (type = 1)
    {
        ner = grd_stack<T>(size, numnode);
    }
    if (type = 2)
    {
        ner = grd_queue<T>(size, numnode);
    }
    else
    {
        ner = int(0);
    }
    int i;
    default_random_engine e;
    uniform_int_distribution<float> uf<-1, 1>;
    uniform_int_distribution<int> uli<-32000, 32000>;
    lim = uli(e);
    for (i = 0; i < 32; i++)
    {
        w[i] = uf(e);
    }
    cout << numnode << "初始化完成" << endl;
}
template <class T>
int *grd_node<T>::runtorear()
{
    int i;
    long r = 0;
    for (i = 0; i < 32; i++)
    {
        r += w[i] * x[i];
    }
    if (r > 2147483647)
        return 2147483647;
    else
        return int(r);
}
// template <class T>
// int *grd_node<T>::torear()
// {
//     return inputrix;
// }