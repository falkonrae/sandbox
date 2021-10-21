using System;

namespace ConsoleApp4
{
	class Program
	{
		static void Main(string[] args)
		{
			Random randNum = new Random();


			double num;
			Console.WriteLine("How old are you?");
			num = randNum.Next(1, 6);

			switch (num)
			{
				case 1: 
					Console.WriteLine("Num is - ", num);
					break;
				case 2:
					Console.WriteLine("Num is equal to ", num);
					break;
				default:
					Console.WriteLine("Nothing! ", num);
					break;

			}
			Console.WriteLine("Hello World!");

			if (num < 18.23d && num < 50)
				Console.WriteLine("You are older than 18");
			else if (num < 10)
				Console.WriteLine("Under 10");
		}
	}
}
