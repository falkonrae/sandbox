using System;
using System.Collections.Generic;

namespace ConsoleApp2
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Hello World!");
			List<int> nums = new List<int>
			{
				73,
				49// добавление элемента в список
			}; // создание массива интов с выделением памяти
			nums.Add(88);
			nums.Remove(73); // удаляет первое вхождение данного значения
			nums.RemoveAt(1); // удаляет конкретный индекс
			//стоит отслеживать, каким на очереди стоят команды, потому что при удалении элемента листа смещается индекс остальных элементов листа
			for (int i = 0; i < nums.Count; i++)
			{
				Console.Write(nums[i] + ", ");
			}
			Console.WriteLine("\n\n\n\n\n");



			int[,] array = new int[4, 2]
			{
				{2,8},{23,5},{87,21}, {8,9} //количество должно быть строго фиксированное по выделенной памяти, первое число - количество массивов, второе число - количество символов в каждом массиве, ни больше, ни меньше
			};// двумерный массив, [,] показатель того, что массив двумерный, также память выделяется двумя числами.
			Console.Write(array[3, 1]);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					Console.Write(array[i, j] + "     ");
				}
				Console.WriteLine();

			}

			Console.WriteLine("\n\n\n\n\n");




/*			float[] nums1 = { 1.23f, 5.32f, 7.56f };
			foreach (float el in nums1) //позволяет просматривать все массивы в нужной форме.
			{
				Console.WriteLine("Element is: " + el);*/


			}
		}
	}
}
