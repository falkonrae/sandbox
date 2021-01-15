#include <stdio.h>

int f1(int i)
{
    i = 110;
    return (i);
}

void f2(int *i)
//Здесь именно указатель на нужную нам коробку, а не массив
{
    *i = *i * 2;
    // Указатель компилятору:
    //"Поди по тому адресу и возьми то, что там лежит"
}
int main(void)
{
    int i;

    i = 5;
    i = f1(i);
    f2(&i); // Амперсанд указывает, что там адрес на коробку
    printf("%d\n", i);
}
// Будет значение 220, поскольку мы положили новое  
// значение, получившееся в результате функции f1 в i,
// а потом умножили значение через функцию f2.