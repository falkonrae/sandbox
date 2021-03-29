#include <iostream>
#include <string>
#include <clocale>
#include <conio.h>
using namespace std;

struct country
{
	string region;
	char name[15];
	int year;
	int citizen;
	float size;
};

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество городов: " << endl;
	cin >> n;
	country *city = new country[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите информацию о " << i + 1 << " городе:" << endl;
		cout << "Регион города: "; cin >> city[i].region;
		cout << "Имя города: "; cin >> city[i].name;
		cout << "Год основания города: "; cin >> city[i].year;
		cout << "Население города: "; cin >> city[i].citizen;
		cout << "Площадь города: "; cin >> city[i].size;
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Вывод информацию о " << i + 1 << " городе:" << endl;
		cout << "Регион города: " << city[i].region << endl;
		cout << "Имя города: " << city[i].name << endl;
		cout << "Год основания города: " << city[i].year << endl;
		cout << "Население города: " << city[i].citizen << endl;
		cout << "Площадь города: " << city[i].size << endl;
	}

	_getch();
	return (0);
}
