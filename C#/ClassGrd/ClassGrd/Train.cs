using System;
using System.Collections.Generic;
using System.Text;
namespace ClassGrd
{
	/// <summary>
	/// 训练类
	/// </summary>
	public class Train
	{
		/// <summary>
		/// 自动线性梯度机
		/// </summary>
		public class GradientLinearOptimizer
		{
			/// <summary>
			/// 损失
			/// </summary>
			private double loss;
			/// <summary>
			/// 学习步长
			/// </summary>
			private double rate;
			/// <summary>
			/// 目标数组
			/// </summary>
			private double[,] target;
			/// <summary>
			/// 当前结果数组
			/// </summary>
			private double[,] moment;
			/// <summary>
			/// 
			/// </summary>
			private int[] shape = { 0, 0 };
			/// <summary>
			/// 启动的图
			/// </summary>
			private Map endmap;
			/// <summary>
			/// 指定目标和当前结果数组
			/// </summary>
			/// <param name="ctarget">目标数组</param>
			/// <param name="cmoment">当前结果数组</param>
			public void Minimize(double[,] ctarget, double[,] cmoment)
			{
				if (ctarget.GetLength(0) == cmoment.GetLength(0) && ctarget.GetLength(1) == cmoment.GetLength(1))
				{
					shape[0] = ctarget.GetLength(0);
					shape[1] = ctarget.GetLength(1);
					target = ctarget;
					moment = cmoment;
				}
				else
				{
					throw new Exception("检查矩阵形状一致");
				}
			}
			/// <summary>
			/// 自动线性梯度机建立
			/// </summary>
			/// <param name="cendmap">最后的需要运行的图</param>
			/// <param name="crate">学习步长</param>
			public GradientLinearOptimizer(Map cendmap, double crate = 0.01f)
			{
				endmap = cendmap;
				rate = crate;
			}
			/// <summary>
			/// 启动梯度训练
			/// </summary>
			public void Run()
			{
				//loss = 0;
				//Map tmap;
				//endmap.Run();
				//for (int cl = 0; cl < shape[0]; cl++)
				//	for (int r = 0; r < shape[1]; r++)
				//		loss += Math.Abs(target[cl, r] - moment[cl, r]);
				//for (int i = endmap.tempmaps.Count; i >= 0; i--)
				//{
					
				//}
			}
		}
	}
}
