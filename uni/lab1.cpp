#include <iostream>
#include <ctime>
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

// void sort_insert (int *mas, int n)
// {
//     int buf, buf1, i = 0, j, k;
//             k = 0;
//         j = 0;
//     while (i <= n)
//     {

//         buf = mas[i]; //6
//         buf1 = mas[k];
//         cout << "buf = " << buf << "\n";
//         cout << "buf1 = " << buf1 << "\n";
//         while (buf1 < buf) //6 < 6 ?n
//         {
//             if (buf1 < buf)
//                 k++;
//             buf1 = mas[k];
//         }
//         cout << "k = " << k << "\n";
//                 // j = i - 1;
//         while (j < k) //j = k ?n
//         {
//             cout << "k = " << k << "\n";
//             cout << "j = " << j << "\n";
//             cout << "mas[j - 1] = " << mas[j - 1] << "\n";
//             cout << "mas[j] = " << mas[j - 1] << "\n";
//             if (j < k)
//                 mas[j - 1] = mas[j];
//             cout << "new mas[j] = " << mas[j - 1] << "\n";
//             j++;
//         }
//         mas[i] = mas[k]; //mas[1] = 6
//         i++;
//     }
// } 

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
        mas[i]=rand () % 10; 
        cout << "mas[" << i << "] = " << mas[i] << "\n";
    }

    int *mas1 = new int[n];
    mas1 = mas;
    cout << "Копия массива: [";
    for (int i = 0; i < n - 1; i++) 
        cout << mas[i] << ", ";
    cout << mas[n - 1] << "]" << "\n";
    sort_insert (mas1, n);
        cout << "Копия массива после сортировки: [";
    for (int i = 0; i < n - 1; i++) 
        cout << mas[i] << ", ";
    cout << mas[n - 1] << "]" << "\n";
    delete[] mas;
    delete[] mas1; // Обязательно для очистки памяти массива
}

// int main()
// {
//     int *mas =  new int[4];
//     mas[0] = 2;
//     mas[1] = 5;
//     mas[2] = 4;
//     mas[3] = 3;
//     cout << "Копия массива: [";
//     for (int i = 0; i < 4 - 1; i++) 
//         cout << mas[i] << ", ";
//     cout << mas[4 - 1] << "]" << "\n";
//     sort_insert (mas, 4);
//         cout << "Копия массива после сортировки: [";
//     for (int i = 0; i < 4 - 1; i++) 
//         cout << mas[i] << ", ";
//     cout << mas[4 - 1] << "]" << "\n";
// }

 // Создание копии предыдущего массива и его сортировка вставками погружением. Зафиксировать количество итераций и время сортировки.
 // Создание копии предыдущего массива и его сортировать "обменной сортировкой "пузырьком"". Зафиксировать количество итераций и время сортировки."
 // Создание копии предыдущего массива и кго сортировать через "быструю" сортировку.
 


