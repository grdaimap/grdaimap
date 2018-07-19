/*
作者：grdaimap，
联系方式&源码地址：https://github.com/grdaimap/grdaimap
*/
#include "grd.h"
#include <iostream>
#include <stdlib.h>
#include <random> //C++11以上才可使用
#include <cmath>
#include <glfw3.h>
#define PI2 3.14159265358*2

using namespace std;
grd_map::grd_map(int inp, int sig, int amout, int max)//(int inp，输入结点的个数, int sig，标记结点个数（检验神经网络能力）, int amout，结点总数大于2, int max，结点内部空间大于2；默认不分层)
{

	if (inp <= 0 || amout < 2 || sig <= 0 || max < 2)
	{
		inp = 1; sig = 1; amout = 2; max = 2;
	}
	amt = amout;
	cout << "map:" << "  init start" << endl;
	nodes = new grd_node[amout+1];
	int temp;
	for (temp = 0; temp <= amout; temp++)
	{
		nodes[temp].grd_init(temp, max);
	}
	cout << "map:" << "  init finish" << endl;
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
void grd_map::show3D()//绘图函数，初步打算使用opendl
{

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit()) {
		cout << "glfw fall, please check" << endl;
		return;
	}

	//	//版本限定，只用内核
	//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(900, 800, "Hello Map", NULL, NULL);

	if (!window)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return;
	}
	else cout << "success" << endl;

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		
		/*your draw*/
		drawNode(amt);
		//3D;
		//glm::mat4 trans;
		//trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
		//trans = glm::rotate(trans, glm::radians((GLfloat)glfwGetTime()*50.0f), glm::vec3(0.0f, 0.0f, 1.0f));

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	cout << "GLFW window close..." << endl;
	glfwTerminate();
	return;
}
void grd_map::mapchoose(short i)
{
	
	if (i == 1)show3D();
	else if (i == 2)grd_run();
	else return;
}
void grd_map::reshape(int p)//分层函数，把环形网络平均分成多组，施工中。
{
	if (p > 0)maxp = p;
	int ii = amt / maxp, i;
	for (i = 0; i <= amt / 2; i++)
	{
		nodes[i].sort = maxp - 1 - 2 * i / ii;
	}
	for (i = amt / 2 + 1; i <= amt; i++)
	{
		nodes[i].sort = 2 * i / ii - 1 - maxp;
	}
}
void grd_node::grd_init(int num, int max)//结点初始化函数。
{
	if (max < 2)
		max = 2;
	nodenum = num;
	//default_random_engine e;
	//uniform_real_distribution<float> uf(-10, 10);
	//uniform_int_distribution<int> uli(-32000, 32000);
	//lim = uli(e);
	//弃用
	int i;
	//for (i = 0; i < 32; i++)
	//{
	//	w[i] = uf(e);
	//}
	for (i = 0; i < 32; i++)
	{
		w[i] = 1.0;
	}
	inner.sp_init(max);
	cout << "node:" << nodenum << "  init finish" << endl;
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

void grd_map::drawNode(int amt)
{
	/* 画点 */
	int i, j, k = 17, zheshu = log2(amt) / log2(1.1); float r = 0.7;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10.0);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);// Red
	for (i = 0; i < amt; i++)
	{
		//褶皱型
		nodes[i].x = r * (1 + 0.4*sin(PI2 / amt * zheshu*i))*cos(PI2 / amt * i);
		nodes[i].y = r * (1 + 0.4*sin(PI2 / amt * zheshu*i))*sin(PI2 / amt * i);
		nodes[i].z = sin(PI2 / amt * zheshu*i);
		////圆形
		//nodes[i].x = r * cos(PI / amt * i);
		//nodes[i].y = r * sin(PI / amt * i);
		glVertex3f(nodes[i].x, nodes[i].y, nodes[i].z);
	}

	glEnd();

	nodes[amt].x = nodes[0].x;
	nodes[amt].y = nodes[0].y;

	glLineWidth(1.0);//设置线段宽度
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);// 绿的
	if (amt < 17)k = amt;
	for (i = 1; i < k; i++)
		for (j = 0; j < amt; j += i)
		{
			glVertex2f(nodes[j].x, nodes[j].y); //定点坐标范围
			if (j + i > amt) j -= amt;
			glVertex3f(nodes[j + i].x, nodes[j + i].y, nodes[i].z);
		}
	glEnd();
}
