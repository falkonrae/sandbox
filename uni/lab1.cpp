#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;

// void    sort_insert2(int A[ ], int n)
// {
// for (int i=1; i<n; i++) // Пока не достигли «дна» или элемента меньше себя
// for (int k=i; k !=0 && A[k] < A[k - 1]; k--)
// {
//     int buf=A[k],
//     A[k]=A[k - 1];
//     A[k - 1]=buf;
// } 
int main() 
{
    setlocale(LC_CTYPE, "rus");
    int n, i;
    time_t t;
    int *mas;

    cout << "Введите количество символов в массиве: \n";
    cin >> n;
    srand((unsigned)time(&t));
    for(i=0; i<n; i++) // Рандромайзер чисел в массиве
    {
        mas[i]=rand(); 
        i++;
        cout << "mas[" << i << "] = " << mas[i];
    }
}

// Создание массива на N элементов (для строк) (заполнен нулями)
// int main() 
// {
//  int n;
//  char *str;
//  str[n] = '\n';
//  while (n >= 0)
//  {
//      str[n] = '0'; 
//      n--;
//  }

 // Создание копии предыдущего массива и его сортировка вставками погружением. Зафиксировать количество итераций и время сортировки.
 // Создание копии предыдущего массива и его сортировать "обменной сортировкой "пузырьком"". Зафиксировать количество итераций и время сортировки."
 // Создание копии предыдущего массива и кго сортировать через "быструю" сортировку.
 


