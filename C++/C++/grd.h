#pragma once
#include <stdlib.h>
class innersp
{
public:
	void sp_init(int max = 2);
	void push(int e);

	int getf();

	int gete();

	void delf();

	void dele();

	int popf()
	{
		int f = getf();
		delf();
		return f;
	}
	int pope()
	{
		int e = gete();
		dele();
		return e;
	}

private:
	int *sp;
	int maxsize;
	int bottom;
	int upper;
};
class grd_node
{

public:
	grd_node() :inner() {};
	void grd_init(int num, int max);
	int nodenum, sort = 0, my = 0;
	float w[32];


private:
	int lim;
	innersp inner;
};

class grd_map
{
	grd_node *nodes;
public:
	grd_map(int inp = 1, int out = 1, int amout = 0, int max = 2);
	void reshape(int maxp);
	~grd_map()
	{
		if (nodes)
			delete[] nodes;
	}
	void grd_run();

private:

	int amt = 0;
	int maxp = 0;
};

