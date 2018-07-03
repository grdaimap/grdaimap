#ifndef _GRDAIMAP_H
#define _GRDAIMAP_H
/*grd_stack类：

一个顺序栈空间，stack[]

一个容量控制函数，由构造函数等共同承担

一个状态函数（获得数据数），int cond()

一个push函数，数据入栈

一个pop函数，数据出栈

一个get函数，获取栈顶

一个消去栈底Destark函数，

一个构造函数，grd_stack()

一个析构函数。~grd_stack()
*/
template <class T>
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
/*
grd_queue类

一个循环队列空间，queue[]

一个容量控制函数，一起控制

一个状态函数（获得数据数），cond()

一个enque函数，入列

一个deque函数，出列

两个getfront，获取队头

getrear函数，获取队尾

一个清空函数（可能没用），

一个构造函数，grd_queue()

一个析构函数。~grd_queue()
*/
template <class T>
class grd_queue
{
  public:
	friend class grd_node;

  private:
	grd_queue(int size = 16, long numnode = 0);
	~grd_queue()
	{
		delete[] queue;
	}
	void enque(T e);
	T deque();
	T getrear();
	T getfront();
	int cond() { return (front - rear - 1 + length) % length; }
	int length, front, rear;
	long const numnode;
	T *queue;
};
/*
grd_node()类

多个输入参数（树突），一个返回值（轴突）。

构造函数为单参数，有值（0,1,2）对应原子类型，栈类型，队列类型。结点只能有一个类型。

存放input结点位置的二维数组。和转化位置——编号函数。

结点自身的运算函数：接受参数（大于10的特殊外界信号则多次运算拆成小数据），进行放大（缩小）、相加，得出结果值f，和阈值比较，改变阈值和参数，存储、或缓存（缓存0,1,2,3）以及是否输出，true、false。

结点自身的输出函数，若栈，队列，返回4字节内模拟电流（0无电流）。这里要考虑突触可塑性LTP，LTD。长期增强作用，长期抑制作用，短期突触可塑性。以及兴奋型、抑制型。
*/
template <class T>
class grd_node
{
  public:
	friend class grd_map;

  private:
	grd_node(long num, int type = 0, int size = 32);
	~grd_node();
	int *fromfront();
	{
		return inputrix;
	}
	int inputrix[32][3];
	int x[32];
	float w[32];
	long runtorear();
	// int torear();
	int lim;
	int nodetype;
	long numnode
		T ner;
};
class grd_map
{
};
#endif
