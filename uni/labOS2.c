#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <conio.h>
#include <locale.h>

const int COUNT = 10;


void Procces1(int ZR)
{
    for (int i = 0; i < COUNT; i++)
    {
        if (ZR == '1')
        {
            printf("Вход в критический участок %d", i);
        }
    }
    // while (FN == 1)
    // {

    // }
    // while (ZR == 1)
    // {

    // }

}



int main()
{
    setlocale(LC_CTYPE, "rus");
    FILE *ZR = fopen("flagZR.txt", "r+");
    FILE *F1 = fopen("flagF1.txt", "r+") ;
    FILE *FN = fopen("flagFN.txt", "r+");
    int c;
    if ((ZR == NULL) || (F1 == NULL) || (FN  == NULL)) //проверка на открытие файла
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    if (c = fgetc(ZR))
        printf("ZR = %c", c);
    fclose(ZR); //закрытие файла
    Procces1(c);
    return (0);
}
 //закрывать 
    // FILE * F1 = fopen("flagF1.txt","r+");
    // FILE * FN = fopen("flagFN.txt","r+");

    // printf(ZR);





// //установка флага Fi = 1, i = 1...n добавить в текстовый файл 
// bool f = true, n;

// //проверка F(j), i = 1, ... (i-1). если есть f(j) == 1, то снова повтор пункта
// while (Fj == 1)
// {

// }

//проверка ZR если ZR ==1, то снова повторяется 

//установка ZR = 1

//вход к крит.участку i

//выход из крит.участка i

//сброс ZR = 1

//сброс Fi = 1
