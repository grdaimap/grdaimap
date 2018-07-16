#include "grd.h"
#include <iostream>
#include <random> //C++11以上才可使用
using namespace std;
grd_map::grd_map(int inp, int out, int amout, int max)
{
	amt = amout;
	if (inp > 0 && amout >= 0 && out > 0)
	{
		nodes = new grd_node[amout];
		int temp;
		for (temp = 0; temp < amout; temp++)
		{
			nodes[temp].grd_init(temp, max);
		}
	}
}
void grd_map::grd_run()
{
	int pin = 0, anc = 0, lef = 0, rig = amt, i, r = 0;
	while (nodes[anc].sort == pin)
	{
		if (nodes[anc].nodenum - 16 > 0)
			lef = nodes[anc].nodenum - 16;
		if (nodes[anc].nodenum + 16 < amt - 1)
			rig = nodes[anc].nodenum + 16;
		for (i = lef; i < rig; i++)
			r += nodes[anc].w[i] * nodes[i].my;
		anc++;
		if (anc >= amt)
		{
			pin++;
			anc = 0;
		}
		if (pin > maxp)
			break;
	}
}
void grd_map::reshape(int p)
{
	maxp = p;
	int ii = amt / maxp, i;
	for (i = 0; i < amt; i++)
	{
		nodes[i].sort = i / ii;
	}
}
void grd_node::grd_init(int num, int max)
{
	if (max < 2)
		max = 2;
	nodenum = num;
	default_random_engine e;
	uniform_real_distribution<float> uf(-1, 1);
	uniform_int_distribution<int> uli(-32000, 32000);
	lim = uli(e);
	int i;
	for (i = 0; i < 32; i++)
	{
		w[i] = uf(e);
	}
	inner.sp_init(max);
	cout << nodenum << "" << endl;
	;
}

void innersp::sp_init(int max)
{
	maxsize = max;
	sp = new int[max];
	if (!sp)
		exit(1);
	bottom = 0;
	upper = 1;
}






void innersp::push(int e)
{
	if (!sp)
		exit(1);
	sp[upper] = e;
	upper = (upper + 1 + maxsize) % maxsize;
}
int innersp::getf()
{
	if (!sp)
		exit(1);
	if ((upper - bottom + maxsize) % maxsize != 0)
		return sp[upper - 1];
	else
		return 0;
}
int innersp::gete()
{
	if (!sp)
		exit(1);
	if ((upper - bottom + maxsize) % maxsize != 0)
		return sp[bottom + 1];
	else
		return 0;
}
void innersp::delf()
{
	if (!sp)
		exit(1);
	if ((upper - bottom + maxsize) % maxsize != 0)
		upper = (upper - 1 + maxsize) % maxsize;
}
void innersp::dele()
{
	if (!sp)
		exit(1);
	if ((upper - bottom + maxsize) % maxsize != 0)
		bottom = (bottom + 1 + maxsize) % maxsize;
};