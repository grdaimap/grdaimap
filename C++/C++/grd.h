/*
���ߣ�grdaimap��
��ϵ��ʽ&Դ���ַ��https://github.com/grdaimap/grdaimap
*/
#pragma once
/*ÿ�� innersp�� ������
����ռ䣨���Σ�maxsize��

ͷβ��ָ�롱��bottom��upper;

���˺�����gete��getf��

ȥ�˺�����dele��delf��*/
class innersp
{
public:
	void sp_init(int max = 2);
	void push(int e);
	int getb();
	int getu();
	void delb();
	void delu();
	int popb()//��ȡ��ɾ���������
	{
		int f = getb();
		delb();
		return f;
	}
	int popu()//��ȡ��ɾ����������
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

/*ģ���񾭽��grd_node�ࣺ

��������������ͻ�����32���ޣ���һ������ֵ����ͻ����

�����������㺯���������ڽ������������зŴ���С������ӣ��ó����ֵ����ֵ�Ƚϡ�

���������������������4�ֽ���ģ�������0�޵�������

����Ҫ����ͻ��������LTP��LTD��������ǿ���ã������������ã�����ͻ�������ԡ��Լ��˷��͡������͡�

**������ʹ�������糣�õļ����***/
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
/*ģ��������grd_map�ࣺ
	һ��������飬grd_node *nodes;

	��ʼ��������grd_map(int inp = 1, int out = 1, int amout = 0, int max = 2);

	�ı��������������ʮ�㣬void reshape(int maxp);

	���к�����void grd_run();

	���������int amt = 0;

	��������int maxp = 0;*/
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

