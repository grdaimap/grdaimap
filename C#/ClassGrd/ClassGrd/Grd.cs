using System;
using System.Collections.Generic;
using System.Text;

namespace ClassGrd
{
	/// <summary>
	/// 
	/// </summary>
	public partial class Grd
	{

		/// <summary>
		/// 训练类
		/// </summary>
		public class Train
		{

			/// <summary>
			/// 自动梯度机
			/// </summary>
			public class GradientDescentOptimizer
			{
				private double targetmap;
				public void Minimize(double entropy)
				{
					targetmap = entropy;
				}
				public GradientDescentOptimizer(double rate = 0.01f)
				{

				}
			}
		}

		/// <summary>
		/// 启动训练
		/// </summary>
		/// <param name="train">训练器</param>
		public void Run(Train train)
		{

		}

		/// <summary>
		/// 启动顺序运算
		/// </summary>
		/// <param name="map">最后的图</param>
		public void Run(Map map)
		{
			map.Run();
		}

		/// <summary>
		/// 矩阵乘法构造新图
		/// </summary>
		/// <param name="a">图</param>
		/// <param name="b">图</param>
		/// <returns>新图</returns>
		public static Map Matmul(Map a, Map b)
		{
			Map c = a * b;
			if (a.premaps != null) c.premaps.AddRange(a.premaps);
			else c.premaps.Add(a);
			if (b.premaps != null) c.premaps.AddRange(b.premaps);
			else c.premaps.Add(b);

			return c;
		}

		/// <summary>
		/// 矩阵加法构造新图
		/// </summary>
		/// <param name="a">图</param>
		/// <param name="b">图</param>
		/// <returns>新图</returns>
		public static Map Plus(Map a, Map b)
		{
			Map c = a + b;
			if (a.premaps != null) c.premaps.AddRange(a.premaps);
			else c.premaps.Add(a);
			if (b.premaps != null) c.premaps.AddRange(b.premaps);
			else c.premaps.Add(b);

			return c;
		}
	}
}
