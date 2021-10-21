using System;

namespace ConsoleApp3
{


	enum Models
	{
		AUDI, VOLVO, NISSAN, VOLSKWAGEN, PORSHE, FORD //для облегчения перечисления
	}
	class Cars
	{
		public int wheels = 4;
		private float speed; //видно исключительно в этом классе
		protected bool isWorking = true; //можем только в этом классе и в классах-наследниках работать

		public Models model;

		public static int test = 0;
		public static void Test()
		{
			Console.WriteLine("Hi!");
		}


		public void setValues(float speed, bool isWorking)
		{
			this.speed = speed; //this.* - обращение к переменной в классе
			this.isWorking = isWorking;
		}

		public virtual void getValues()
		{
			Console.WriteLine("Car's speed is: " + this.speed + ", car is working: " + this.isWorking);
		}

		public Cars(int wheels, float speed, bool isWorking)
		{
			this.speed = speed; //this.* - обращение к переменной в классе
			this.isWorking = isWorking;
			this.wheels = wheels;
		}
		public Cars() { } //конструктор по умолчанию
	}


	class Trucks : Cars//наследование дает доступ ко всем переменным public and protected
	{
		public int passengers;

			public Trucks(int wheels, float speed, bool isWorking, int passengers) : base (wheels, speed, isWorking)
		{
			this.passengers = passengers;
		}
		public override void getValues()
		{
			base.getValues();
			Console.WriteLine("Passengers: " + passengers);
		}
	}







	class Program
	{
		public static void Main(string[] args)
		{
			Print("Hello World!");


			Trucks man = new Trucks(8, 130.5f, true, 3);
			man.getValues();
			//Console.WriteLine(man.passengers);




			Cars.test = 23;
			Console.WriteLine(Cars.test);
			Cars.Test();
			//int num = summ(4, 10);
			//Print(num);
			Cars audi = new Cars(); //конструктор не дает 
			Console.WriteLine(audi.wheels); //доступ есть только к wheels, т.к. public

			audi.setValues(230.5f, true);
			audi.getValues();
			audi.model = Models.AUDI;

			Cars volvo = new Cars();
			volvo.wheels = 6;
			Console.WriteLine(volvo.wheels);
			volvo.setValues(159.6f, false);
			volvo.getValues();
			volvo.model = Models.VOLVO;
			Cars toyota = new Cars(4, 230.5f, true);
			toyota.getValues();
			
		}












		public static void Print(string str)
		{
			Console.WriteLine(str);
		}

		public static void Print(int num) //можно ввести ту же функцию просто с другими входными данными, программа сама понимает, к какой функции ей обращаться
		{
			Console.WriteLine(num);
		}

		public static int summ(int a, int b)
		{
			return (a + b);
		}
	}
}
