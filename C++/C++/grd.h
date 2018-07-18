/*
作者：grdaimap，
联系方式&源码地址：https://github.com/grdaimap/grdaimap
*/
#pragma once
/*每个 innersp类 包括：
储存空间（环形）maxsize；

头尾“指针”，bottom和upper;

读端函数，gete和getf；

去端函数，dele和delf。*/
class innersp
{
public:
	void sp_init(int max = 2);
	void push(int e);
	int getb();
	int getu();
	void delb();
	void delu();
	int popb()//读取并删除最旧数据
	{
		int f = getb();
		delb();
		return f;
	}
	int popu()//读取并删除最新数据
	{
		int e = getu();
		delu();
		return e;
	}

private:
	int *sp;
	int maxsize;
	int bottom;
	int upper;
};

/*模拟神经结点grd_node类：

多个输入参数（树突，多达32上限），一个返回值（轴突）。

结点自身的运算函数：接受邻近结点参数，进行放大（缩小）、相加，得出结果值和阈值比较。

结点自身的输出函数，返回4字节内模拟电流（0无电流）。

这里要考虑突触可塑性LTP，LTD。长期增强作用，长期抑制作用，短期突触可塑性。以及兴奋型、抑制型。

**！！不使用神经网络常用的激活函数***/
class grd_node
{

public:
	grd_node() :inner() {};
	void grd_init(int num, int max);
	int nodenum, sort = 0, my = 0;
	float w[32];


private:
	int lim = 0;
	innersp inner;
};
/*模拟神经网络grd_map类：
	一个结点数组，grd_node *nodes;

	初始化函数，grd_map(int inp = 1, int out = 1, int amout = 0, int max = 2);

	改变层数，建议少于十层，void reshape(int maxp);

	运行函数，void grd_run();

	结点总数，int amt = 0;

	最大层数，int maxp = 0;*/
class grd_map
{

public:
	grd_map(int inp = 1, int sig = 1, int amout = 0, int max = 2);
	void reshape(int maxp);
	~grd_map()
	{
		if (nodes)
			delete[] nodes;
	}
	void grd_run();

private:
	grd_node * nodes;
	int amt = 0;
	int maxp = 1;
};

