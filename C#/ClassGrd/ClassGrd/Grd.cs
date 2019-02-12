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
			c.premaps.Add(a);
			c.premaps.Add(b);

			c.sys = "*";

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
			c.premaps.Add(a);
			c.premaps.Add(b);

			c.sys = "+";
			return c;
		}
	}
}
