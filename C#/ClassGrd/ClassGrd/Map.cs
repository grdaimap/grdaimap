using System;
using System.Collections.Generic;
using System.Text;

namespace ClassGrd
{
	/// <summary>
	/// 图
	/// </summary>
	public partial class Map
	{
		/// <summary>
		/// 名称
		/// </summary>
		public string name;

		/// <summary>
		/// 形状，先列数后行数
		/// </summary>
		public int[] shape;

		/// <summary>
		/// 数据，二维数组
		/// </summary>
		public double[,] data;

		/// <summary>
		/// 需要之前就算好的图的列表
		/// </summary>
		public List<Map> premaps;

		/// <summary>
		/// 记号列表，把构造和执行分开
		/// </summary>
		public List<int> sys;

		/// <summary>
		/// 是否接受网络训练
		/// </summary>
		public bool trainable = true;

		/// <summary>
		/// 运行
		/// </summary>
		public void Run()
		{
			if (trainable == false) return;
			int c = 0;
			Map new_map = premaps[0];
			foreach (int item in sys)
				switch (item)
				{
					case 0: break;
					case 1: new_map = new_map + premaps[c + 1]; break;
					case 2: new_map = new_map * premaps[c + 1]; break;
					case 3: break;
					case 4: break;
					case 5: break;
					case 6: break;
					case 7: break;
					case 8: break;
					case 9: break;
					case 10: break;
					case 11: break;
					case 12: break;
					case 13: break;
					case 14: break;
					case 15: break;
					case 16: break;
					case 17: break;
					case 18: break;
					case 19: break;
					case 20: break;
					case 21: break;
					case 22: break;
					case 23: break;
					default: c++; break;
				}
			data = new_map.data;
		}

		/// <summary>
		/// 改变形状
		/// </summary>
		/// <param name="columns">新矩阵行数</param>
		public void Reshape(int columns = 1)
		{

		}

		/// <summary>
		/// 摊平data数组
		/// </summary>
		public Map Plain()
		{
			Map c=new Map(shape[0] * shape[1], 1);
			double[,] new_data = new double[shape[0] * shape[1], 1];
			for (int cl = 0; cl < shape[0]; cl++)
				for (int r = 0; r < shape[1]; r++)
					new_data[cl * shape[1] + r, 0] = data[cl, r];
			c.data = new_data;
			return c;
		}

		/// <summary>
		/// 绑定数据来源
		/// </summary>
		/// <param name="arr">一个必须符合data大小的二维数组</param>
		public void Feed(double[,] arr)
		{
			data = arr;
			//int arcl = arr.GetLength(0);
			//int arro = arr.GetLength(1);
			trainable = false;
		}

		/// <summary>
		/// 图的构造函数
		/// </summary>
		/// <param name="columns">列数</param>
		/// <param name="rows">行数</param>
		/// <param name="cname">名字</param>
		public Map(int columns = 1, int rows = 1, string cname = "")
		{
			name = cname;
			if (columns > 0 && rows > 0) shape = new int[] { columns, rows };
			data = new double[columns, rows];
		}

		/// <summary>
		/// 重载*运算，矩阵乘法
		/// </summary>
		/// <param name="a">图类型</param>
		/// <param name="b">图类型</param>
		/// <returns>一个矩阵乘法的结果图</returns>
		public static Map operator *(Map a, Map b)
		{
			Map c;
			if (a.shape[1] != b.shape[0])
			{
				throw new Exception("检查矩阵形状");
			}
			else
			{
				c = new Map(a.shape[0], b.shape[1]);
				for (int cl = 0; cl < c.shape[0]; cl++)
					for (int r = 0; r < c.shape[1]; r++)
						for (int co = 0; co < a.shape[1]; co++)
							c.data[cl, r] += a.data[cl, co] * b.data[co, r];

				return c;
			}
		}

		/// <summary>
		/// 重载+运算，矩阵乘法
		/// </summary>
		/// <param name="a">图类型</param>
		/// <param name="b">图类型</param>
		/// <returns>一个矩阵加法的结果图</returns>
		public static Map operator +(Map a, Map b)
		{
			Map c;
			if (a.shape[0] == b.shape[0] && a.shape[1] == b.shape[1])
			{
				c = new Map(a.shape[0], b.shape[1]);
				for (int cl = 0; cl < c.shape[0]; cl++)
					for (int r = 0; r < c.shape[1]; r++)
						c.data[cl, r] = a.data[cl, r] + b.data[cl, r];

				return c;
			}
			else
			{
				throw new Exception("检查矩阵形状");
			}
		}
	}
}
