//这个程序的报错说明了构造函数创建的局部变量只属于构造函数，类成员不能访问
#include <iostream.h>
template <typename T>
class grd_stack
{
  public:
    friend class grd_node;

  private:
    grd_stack(int size = 16, long numnode = 0);
    ~grd_stack()
    {
        delete[] stack;
    }
    void push(T e);
    T pop();
    T get();
    void Destack();
    int cond() { return tos; }
    int length, tos;
    long const numnode;
    T *stack;
};
class grd_node
{
  public:
    grd_node()
    {
        grd_stack<int> *grdstk;
        grdstk = new grd_stack<int>(16, 2);
    }
    ~grd_node(){delete grdstk;}
};
 int main()
{
    grd_node mynode;
    return 0;
}