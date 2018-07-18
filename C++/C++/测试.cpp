#include"grd.h"
#include<iostream>
#include <cmath>
#include<glfw3.h>

#define PI 3.14159265358*2
using namespace std;

//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {};
//void drawnodes(int amt = 2)
//{
//	int i; float x = 0.0, y = 0.0, r = log10(amt+2);
//
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glPointSize(10.0f);
//	glBegin(GL_POINTS);
//	//开始画图
//	glColor3f(0.0, 0.0, 1.0);
//	//for (i = 0; i < amt; i++)
//	//{
//	//	x = r * cos(PI*i / amt);
//	//	y = r * cos(PI*i / amt);
//	//	glVertex2f(x, y);
//	//}
//	glVertex2f(0.0f, 0.0f);
//	glVertex2f(0.5f, 0.8f);
//	//结束画图
//	glEnd();
//
//}
//int main()
//{
//	//初始化map
//	grd_map mymap(1, 1, 2, 2);
//
//	//初始化OpenGL，异常处理
//	if (!glfwInit())
//	{
//		cout << "glfw fall, please check" << endl;
//	}
//
//	//版本限定，只用内核
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	//定义窗口
//	GLFWwindow*mywindow = glfwCreateWindow(800, 600, "mywindow", NULL, NULL);
//
//	//窗口异常处理
//	if (mywindow == nullptr)
//	{
//		cout << "Failed to create GLFW window" << endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	cout << "\nshow...............\n" << endl;
//
//	//指定上下文
//	glfwMakeContextCurrent(mywindow);
//
//
//	//告诉程序有多少像素可以渲染
//	int width, height;
//	glfwGetFramebufferSize(mywindow, &width, &height);
//	glViewport(0, 0, width, height);
//
//	//顶点浮点坐标
//	GLfloat vertices[] = {
//		-0.5f, -0.5f, 0.0f,
//		0.5f, -0.5f, 0.0f,
//		0.0f,  0.5f, 0.0f
//	};
//
//	//三联
//
//
//
//
//
//	//“游戏”主循环
//	while (!glfwWindowShouldClose(mywindow))
//	{
//		// 在这里执行各种渲染操作
//		/*glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);*/
//		drawnodes(0);
//
//		//交换缓冲区，把新图像和旧图像交换
//		glfwSwapBuffers(mywindow);
//		
//		// 检查事件
//		glfwPollEvents();
//	}
//	cout << "GLFW window close..." << endl;
//	glfwDestroyWindow(mywindow);
//	glfwTerminate();
//	return 0;
//}






grd_node nodes[200];


void drawPoint(int amt = 2)
{
	/* Draw a point */
	int i, j, k = 17, t = 0, zheshu = log2(amt); float r = 0.08*log2(amt);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	for (i = 0; i < amt; i++)
	{	
		////褶皱型
		//nodes[i].x = r * (1 + 0.4*sin(PI / amt * zheshu*i))*cos(PI / amt * i);
		//nodes[i].y = r * (1 + 0.4*sin(PI / amt * zheshu*i))*sin(PI / amt * i);
		////圆形
		nodes[i].x = r * cos(PI / amt * i);
		nodes[i].y = r * sin(PI / amt * i);
		glVertex2f(nodes[i].x, nodes[i].y);
	}
	// Red
	glEnd();
	nodes[amt].x = nodes[0].x;
	nodes[amt].y = nodes[0].y;
	glLineWidth(1.0);//设置线段宽度
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	if (amt < 17)k = amt;
	for (i = 1; i < k; i++)
		for (j = 0; j < amt; j += i, t++)
		{
			glVertex2f(nodes[j].x, nodes[j].y); //定点坐标范围
			if (j + i > amt) j -= amt;
			glVertex2f(nodes[j + i].x, nodes[j + i].y);
		}
	glEnd();
	cout << "round" << t << endl;
}
void drawTriangle()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 0.0, 0.0);    // Red
	glVertex3f(0.0, 1.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);    // Green
	glVertex3f(-1.0, -1.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);    // Blue
	glVertex3f(1.0, -1.0, 0.0);
	glEnd();
}
int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(900, 600, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		/*your draw*/
		drawPoint(40);
		//drawTriangle();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}