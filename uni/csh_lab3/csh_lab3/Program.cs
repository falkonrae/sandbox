using System;
using System.Collections.Generic;



namespace csh_lab3
{
public class класс
	{
	public readonly int номер;
		public класс(int num)
		{
			номер = num;
		}
	}

class CA //конструктор с аргументами
	{
		public int x, y, z;

		int a1 = -1000;
		int a2 = 1000;
		public CA(int a)
		{
			if (a < a1 || a > a2)
			{
				if (a < 0)
				{
					Console.WriteLine("Число вышло за пределы диапазона, число приравнено к минимуму: -1000");
				}
				if (a > 0)
					Console.WriteLine("Число вышло за пределы диапазона, число приравнено к максимуму: 1000");
			}

			x = 3;
			y = 2;
			z = x + y;
		}
		public CA(int a, int b)
		{
			if (a < a1 || a > a2)
			{
				if (a < 0)
				{
					Console.WriteLine("Число a вышло за пределы диапазона, число приравнено к минимуму: -1000");
					a = a1;
				}
				if (a > 0)
				{
					Console.WriteLine("Число a вышло за пределы диапазона, число приравнено к максимуму: 1000");
					a = a2;
				}

			}
			if (b < a1 || b > a2)
			{
				if (b < 0)
				{
					Console.WriteLine("Число b вышло за пределы диапазона, число приравнено к минимуму: -1000");
					b = a1;
				}
				if (b > 0)
				{
					Console.WriteLine("Число b вышло за пределы диапазона, число приравнено к максимуму: 1000");
					b = a2;
				}
			}

			x = a;
			y = b;
			z = x + y;
		}
		public CA(int a, int b, int c)
		{
			x = a;
			y = b;
			z = c;
		}
	}
	class Program
	{

		static void Main(string[] args)
		{
			for (int i = 1; i <= 10; i++)
			{
				класс новыйКласс = new класс(i);
				Console.WriteLine(новыйКласс.номер.ToString());
			}
			CA obj = new CA(4000);
			Console.WriteLine("x={0,2} y={1,2} z={2,2}", obj.x, obj.y, obj.z);
			CA obj1 = new CA(5000, -7000);
			Console.WriteLine("x={0,2} y={1,2} z={2,2}", obj1.x, obj1.y, obj1.z);
			/*CA obj2 = new CA(5, 7, 25);
			Console.WriteLine("x={0,2} y={1,2} z={2,2}", obj2.x, obj2.y, obj2.z);*/
		}
	}
}
