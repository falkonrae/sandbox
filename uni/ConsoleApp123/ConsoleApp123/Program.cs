using System;
using System.Threading;

namespace AsyncProgramming
{
    internal class Program
    {
/*        private static void Main(string[] args)
        {
            Thread thread = new Thread(new ParameterizedThreadStart(WriteChar));

            Console.WriteLine("Для запуска нажмите любую клавишу");
            Console.ReadKey();

            thread.Start('*');

            for (int i = 0; i < 80; i++)
            {
                Console.Write('-');
                Thread.Sleep(70);
            }
        }
        private static void WriteChar(object arg)
        {
            char item = (char)arg;
            for (int i = 0; i < 80; i++)
            {
                Console.Write(item);
                Thread.Sleep(270);
            }
        }*/
        private static void Main()
        {
            Console.WriteLine($"Id потока метода Main - {Thread.CurrentThread.ManagedThreadId}");
            Console.WriteLine("Для запуска нажмите любую клавишу");
            Console.ReadKey();

            Report();
            ThreadPool.QueueUserWorkItem(new WaitCallback(Example1));
            Report();
            ThreadPool.QueueUserWorkItem(new WaitCallback(Example2));
            Report();

            Console.ReadKey();
            Report();
        }

        private static void Example1(object state)
        {
            Console.WriteLine($"Метод Example1 начал выполняться в потоке {Thread.CurrentThread.ManagedThreadId}");
            Thread.Sleep(2000);
            Console.WriteLine($"Метод Example1 закончил выполняться в потоке {Thread.CurrentThread.ManagedThreadId}");

        }

        private static void Example2(object state)
        {
            Console.WriteLine($"Метод Example2 начал выполняться в потоке {Thread.CurrentThread.ManagedThreadId}");
            Thread.Sleep(1000);
            Console.WriteLine($"Метод Example2 закончил выполняться в потоке {Thread.CurrentThread.ManagedThreadId}");

        }

        private static void Report()
        {
            ThreadPool.GetMaxThreads(out int maxWorkerThreads, out int maxPortThreads);
            ThreadPool.GetAvailableThreads(out int workerThreads, out int portThreads);

            Console.WriteLine($"Рабочие потоки {workerThreads} из {maxWorkerThreads}");
            Console.WriteLine($"IO потоки {portThreads} из {maxPortThreads}");
            Console.WriteLine(new string('-', 80));
        }
    }
}
