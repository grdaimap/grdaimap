using grd;
using System;
namespace testapp
{
	class Program
	{
		static void Main(string[] args)
		{
			syms x, w, y;
			x = new syms(1, 1, "x");
			w = new syms(1, 1, "w");
			sess.start();
			y = w * x;
			sess.end();
			sess.run();
		}
	}
}
