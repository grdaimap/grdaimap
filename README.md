# grdaimap的grdaimap计划
预计大概到2018.9做完C++雏形，但真正能有用要修改很久，(￣▽￣)／或者根本没有用。

# 写在前面ヽ(･ω･´ﾒ)
现在的难都是往日欠下的债。今天流的泪是昨天脑子进的水。不认真搞懂每一个知识点。考试便会漏洞百出，啥也不会。只有打好基础才能稳步提升。

这个项目是因为没有好好学习数据结构和C++而提出的。因为我是电子专业EE，往后再也不能接触到算法类的知识了（这和计科CS很不相同）。另一方面，用网络模拟生物神经系统又是当前的热门。但作为小白，甚至连TensorFlow等成型库的文档都很难读下去，水平明显不足，需要自己尝试，实践才行。

___

# **C++部分：**
认领开发者：grdaimap

# 目标实现功能：

1.
## **存放数据0,1,2,3的栈和队列，使用C++的类实现。**

### 每个**栈类**包括：

一个顺序栈空间，

一个容量控制函数，

一个状态函数（不参与网络活动，只用于获得每个结点的内部状态，获得数据数和当前有效长度），

一个Push函数，

一个Pop函数，

一个get函数，

一个消去栈底Destark函数，

一个构造函数，

一个析构函数。


### 每个**队列类**包括：

一个循环队列空间，

一个容量控制函数，

一个状态函数（不参与网络活动，只用于获得每个结点的内部状态，获得数据数和当前有效长度），

一个Enque函数，

一个Deque函数，

两个getHead，

getEnd函数，

一个清空函数（可能没用），

一个构造函数，

一个析构函数。

2.
## **模拟神经网络类（结点的友元类）：**

包括一个状态函数（占用总空间等），

一个三维结点指针空间（1000个位置以上）用于存放结点地址，

一个三维缓存空间（4字节），用于存放结点返回值（初始值随机），

网络运算函数（分层运算，以主方向为准）run，时时返回进度，

pause暂停运算，

*可视化函数graph。


## **模拟神经结点类（栈和队列类的友元类）：**

多个输入参数（树突），一个返回值（轴突）。

构造函数为单参数，有值（0,1,2）对应原子类型，栈类型，队列类型。结点只能有一个类型。
存放input结点位置的二维数组。和转化位置——编号函数。

结点自身的运算函数：接受参数（大于10的特殊外界信号则多次运算拆成小数据），进行放大（缩小）、相加，得出结果值f，和阈值比较，改变阈值和参数，存储、或缓存（缓存0,1,2,3）以及是否输出，true、false。

结点自身的输出函数，若栈，队列，返回0,1,2,3（0无电流，1有电流，2较强电流，3强电流）。这里要考虑突触可塑性LTP，LTD。长期增强作用，长期抑制作用，短期突触可塑性。

# 目标

最高希望结果：图像可以分割出主体，识别身份；旋律可以识别出人声，或者音乐。

# 重大更新日志
>（详细更新进入分文件夹查看）

2018.6.30在GitHub创建项目

2018.7.1创建项目总说明

______
