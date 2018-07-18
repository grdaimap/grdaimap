/*
作者：grdaimap，
联系方式&源码地址：https://github.com/grdaimap/grdaimap
*/
#include "grd.h"
#include <iostream>
#include <stdlib.h>
#include <random> //C++11以上才可使用
using namespace std;
grd_map::grd_map(int inp, int sig, int amout, int max)//(int inp，输入结点的个数, int sig，标记结点个数（检验神经网络能力）, int amout，结点总数大于2, int max，结点内部空间大于2；默认不分层)
{

	if (inp <= 0 || amout < 2 || sig <= 0 || max < 2)
	{
		inp = 1; sig = 1; amout = 2; max = 2;
	}
	amt = amout;
	nodes = new grd_node[amout];
	int temp;
	for (temp = 0; temp < amout; temp++)
	{
		nodes[temp].grd_init(temp, max);
	}

}
void grd_map::grd_run()//二维环形神经网络，运行
{
	int pin = 0, anc = 0, lef = 0, rig = amt, i, r = 0;
	while (nodes[anc].sort == pin)
	{
		if (amt <= 33)//不足则全连接
			for (i = lef; i < rig; i++)
				if (i != anc && nodes[i].sort <= nodes[anc].sort)
					r += nodes[anc].w[i] * nodes[i].my;
		if (amt > 33)
		{
			lef = (anc - 16 + amt) % amt; rig = (anc + 16) % amt;
		}
		for (i = lef; i != anc; i = (++i) % amt)//！！存在单比特隐患
			if (nodes[i].sort <= nodes[anc].sort)
				r += nodes[anc].w[i] * nodes[i].my;
		for (i = anc + 1; i != rig; i = (++i) % amt)//！！存在单比特隐患
			if (nodes[i].sort <= nodes[anc].sort)
				r += nodes[anc].w[i] * nodes[i].my;
		anc++;
		if (anc >= amt)
		{
			pin++;
			anc = 0;
		}
		if (pin > maxp - 1)
			break;
	}
}
void grd_map::reshape(int p)//分层函数，把环形网络平均分成多组，施工中。
{
	if (p > 0)maxp = p;
	int ii = amt / maxp, i;
	for (i = 0; i <= amt / 2; i++)
	{
		nodes[i].sort = maxp - 1 - 2 * i / ii;
	}
	for (i = amt / 2 + 1; i < amt; i++)
	{
		nodes[i].sort = 2 * i / ii - 1 - maxp;
	}
}
void grd_node::grd_init(int num, int max)//结点初始化函数。
{
	if (max < 2)
		max = 2;
	nodenum = num;
	default_random_engine e;
	uniform_real_distribution<float> uf(-1, 1);
	//uniform_int_distribution<int> uli(-32000, 32000);
	//lim = uli(e);
	//弃用
	int i;
	for (i = 0; i < 32; i++)
	{
		w[i] = uf(e);
	}
	inner.sp_init(max);
	cout << nodenum << "init finish" << endl;
	;
}

void innersp::sp_init(int max)//内部储存初始化函数。
{
	maxsize = max;
	sp = new int[max];
	if (!sp)
		exit(1);
	bottom = 0;
	upper = 1;
}


void innersp::push(int e)//数据进入
{
	if (!sp)
		exit(1);
	sp[upper] = e;
	upper = (upper + 1 + maxsize) % maxsize;
}
int innersp::getb()//读取最旧数据
{
	if (!sp)
		exit(1);
	if ((upper - bottom + maxsize) % maxsize != 0)
		return sp[upper - 1];
	else
		return 0;
}
int innersp::getu()//读取最新数据
{
	if (!sp)
		exit(1);
	if ((upper - bottom + maxsize) % maxsize != 0)
		return sp[bottom + 1];
	else
		return 0;
}
void innersp::delb()//删除最旧数据
{
	if (!sp)
		exit(1);
	if ((upper - bottom + maxsize) % maxsize != 0)
		upper = (upper - 1 + maxsize) % maxsize;
}
void innersp::delu()//删除最新数据
{
	if (!sp)
		exit(1);
	if ((upper - bottom + maxsize) % maxsize != 0)
		bottom = (bottom + 1 + maxsize) % maxsize;
};