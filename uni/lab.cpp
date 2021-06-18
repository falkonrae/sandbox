// В списке А = (а1, а2, ..., аn) удалить все подряд идущие 
// отрицательные элементы, идущие вслед за минимальным элементом списка

#include <iostream>
#include <string>
#include <clocale>
using namespace std;

void sort_insert (int A[], int n)
{
    int i = 1;
   while (i < n)
    {
        int buf=A[i]; 
        int k=0;
        int j=i - 1;// Действие 1: сохранить очередной элемент
        while (k<i) // Действие 2: поиск места вставки
        {
            if(A[k]>buf) 
                break;
            k++;    
        } // перед первым элементом, бóльшим buf}
        while (j>=k)
        { 
            A[j+1]=A[j];
            j--;
        } // Действие 3: сдвиг на 1 элемент вправо
        A[k]=buf; //Действие 4: вставка очередного элемента
         i++;
    } // на место первого, который больше его
} 
int main() 
{
    setlocale(LC_CTYPE, "rus");
    int n;
    cout << "Введите количество символов в массиве: \n";
    cin >> n;
    int *mas =  new int[n]; // Обязательно для выделения памяти на массив
    srand ( time(0) );
    for (int i = 0; i < n; i++) // Рандромайзер чисел в массиве
    {
        mas[i]=rand () % 5000-2000; 
        cout << "mas[" << i << "] = " << mas[i] << "\n";
    }

    int *mas1 = new int[n];
    mas1 = mas;
    cout << "Копия массива: [";
    for (int i = 0; i < n - 1; i++) 
        cout << mas[i] << ", ";
    cout << mas[n - 1] << "]" << "\n";
    // sort_insert (mas1, n);
	// sort_bubble(mas1, n);
    //     cout << "Копия массива после сортировки: [";
    // for (int i = 0; i < n - 1; i++) 
    //     cout << mas[i] << ", ";
    // cout << mas[n - 1] << "]" << "\n";

	int min, cmin = 1;
	min = mas1[0];
	while (mas1[cmin])
	{
		if ((min < mas1[cmin]) || (min = mas1[cmin]))
			cmin++;
		else if (min > mas1[cmin])
			min = mas1[cmin];
		cmin++;
	}
	cout << "Минимальное число в массиве: " << min << "\n";
    cmin = 0;
	while (mas1[cmin] != min)
		cmin++;
cout << "Индекс минимального числа: " << cmin << "\n";
	cout << "Массив без отрицательных элементов: [";
    for (int i = cmin; i < n - 1; i++) 
	{
			while ((mas1[i] < 0) && ((mas1[i+1] < 0) || (mas1[i-1] < 0)))
				i++;
        cout << mas1[i] << ", ";
	}
    cout << mas1[n - 1] << "]" << "\n";
    delete[] mas1; // Обязательно для очистки памяти массива
}
