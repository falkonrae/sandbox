using System;

namespace csh_lab2
{
	class Мобильник
	{
		public string Бренд;
		public bool havingAUX;
		public float диагональЭкрана;
		public int камера;
		public int количествоЯдер;
		public int ценаТелефона;

		public Мобильник(string Бренд, bool havingAUX, float диагональЭкрана, int камера, int количествоЯдер, int ценаТелефона)
		{
			this.Бренд = Бренд;
			this.havingAUX = havingAUX;
			this.диагональЭкрана = диагональЭкрана;
			this.камера = камера;
			this.количествоЯдер = количествоЯдер;
			this.ценаТелефона = ценаТелефона;

		}
		public void Print()
		{
			Console.WriteLine("Бренд: " + Бренд);
			Console.WriteLine("Количество ядер: " + количествоЯдер);
			Console.WriteLine("ценаТелефона: " + ценаТелефона);
			Console.WriteLine("диагональЭкрана: " + диагональЭкрана);
			Console.WriteLine("камера: " + камера);
			Console.WriteLine("havingAUX: " + havingAUX);
		}
	}

	class Память
	{
		public string тип, производитель;
		public int емкость;
		public int ценаКарты;

	}
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Добро пожаловать!\n");
			Мобильник iPhone = new Мобильник("iPhone", false, 5, 5f, 48,6,16000);
			Мобильник Samsung = new Мобильник("Samsung", true, 2.4f, 48, 6, 16000);
			Мобильник Xiaomi = new Мобильник("Xiaomi", false, 2.4f, 48,6,16000);
			Мобильник GooglePhone = new Мобильник("GooglePhone", true, 5,1f, 48,6,16000);
			Мобильник Honor = new Мобильник("Honor", true, 2.4f, 48,6,16000);
			Мобильник Blackberry = new Мобильник("Blackberry", false, 2.4f, 48,6,16000);
//iPhone.Print();
//Samsung.Print();
int choice;
Память microSD1 = new Память();
Память microSD2 = new Память();
Память microSD3 = new Память();
Память microSD4 = new Память();
Память microSD5 = new Память();
Память microSD6 = new Память();
Console.WriteLine("Выберите характеристику для поиска:\n1.Бренд    2. Наличие AUX    3.Диагональ экрана    4.Камера    5.Кол-во ядер");
choice = Convert.ToInt32(Console.ReadLine());

Console.ReadLine();





}
}
}
