using System;

namespace cs_lab1
{
    class Program
    {
        [STAThread] // атрибут, описательная инф-я, связанная с элементом кода, перед которым стоит атрибут
        static void Main(string[] args)
        {
/*			Console.WriteLine("Введите ваше имя:");
			string str = Console.ReadLine();
			Console.WriteLine("Привет, " + str + "!!!");
			Console.WriteLine("Введите один символ с клавиатуры:");
			int kod = Console.Read();
			char sym = (char)kod;
			Console.WriteLine("Код символа " + sym + " = " + kod);
			Console.WriteLine("Код символа {0} = {1}", sym, kod);
			Console.Read();*/

			/*Например, запись {1,3} означает, что для
        печати первого элемента списка отводится поле шириной в три символа.
        Причем, если значение ширины положительно, то производится
        выравнивание по правому краю поля, если отрицательно то по левому.*/

			/*int s1 = 255, s2 = 32;
            Console.WriteLine(" \n{0,5}\n+{1,4}\n-----\n{2,5}", s1, s2, s1 + s2);
            Console.WriteLine(" \n{1,5}\n+{0,4}\n-----\n{2,5}", s1, s2, s1 + s2);
            Console.Read();*/

            /*Существует 8 различных форматов вывода:
                С – формат национальной валюты,
                D – десятичный формат,
                E – научный (экспоненциальный) формат,
                F – формат с фиксированной точкой,
                G – общий формат,
                N – числовой формат,
                P – процентный формат,
                X – шестнадцатеричный формат*/

            double sum1 = 500.3467;
            double sum2 = 43.5;
            Console.WriteLine(" \n{0,10:N2}\n+{1, 9:N2}\n-----\n{2,10:N2}", sum1, sum2, sum1 + sum2);



        }
    }
}
