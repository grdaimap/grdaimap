//这个程序的报错说明了构造函数创建的局部变量只属于构造函数，类成员不能访问
#include <iostream.h>
class A
{
  public:
    A(int i, int j, int k);
    ~A();

  private:
    int ai;
} A::A(int i, int j, int k)
{
    ai = i;
    int bi[2] = {j, k};
}
A::~A()
{
    cout << "j=" << bi[0] << "k=" << bi[1] << endl;
}
int main()
{
    A a(1, 2, 3);
    return 0;
}