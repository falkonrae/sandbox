using System;
using System.Collections.Generic; //библиотека, которая подключает списки
/*using System.Linq;
using System.Text;
using System.Threading.Tasks;*/

namespace ConsoleApp1
{
    class Program
    {
        public static void Main(string[] args)
        {

			List<int> nums = new List<int>
			{
				73,
				49// добавление элемента в список
			}; // создание массива интов с выделением памяти
			for (int i = 0; i < nums.Count; i++)
			{
                Console.Write(nums[i] + ", ");
			}
            Console.WriteLine();








/*            Console.WriteLine("Привет");
            int num;
            // float num_2 = 34.4f; bool isHappy = false; char c = 'f';  string f = "Hello, everyone!";
            double a;
            num = Convert.ToInt32(Console.ReadLine()); //позволяет присваивать переменной число, одновременно конвертирует в числовой тип данных
            Console.WriteLine("Your number is:" + num); //переменные добавляются через плюс
            Console.WriteLine("Введите вещественное число");
            a = Convert.ToDouble(Console.ReadLine()); //позволяет присваивать переменной число, одновременно конвертирует в числовой тип данных
            Console.ReadLine();        //для того, чтобы консоль не закрывалась сразу же, также считывает любое значение, которое вводится в консоли
            if (a > 10f) // проверка на флоат, необходимо при работе с double
                Console.Write("A is bigger than 10");
            else if (a < 5f)
                Console.Write("A is less than 5");*/


        }
    }
}
