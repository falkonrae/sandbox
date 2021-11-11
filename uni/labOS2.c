#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <conio.h>
#include <locale.h>

int Procces1(int iz_p, int f1, int f2)
{
        FILE *F2 = fopen("flagFN.txt", "r+"); // проверяем намерение второго процесса
        if (F2 == NULL) //проверка на правильность открытия файла
        {
            printf("Wrong file");
            getchar();
            return 0;
        }
        f2 = fgetc(F2) -'0';  
        fclose(F2);
                printf("\ndata before 1 process     f1 = %d and f2 = %d\n", f1, f2);

    if (f2 == 0) // если у 2 процесса нет намерения войти в КО
    {
        printf("Process 1 get in critical section");
        getchar();
        printf("Process 1 get out of critical section\n");
        FILE *F1 = fopen("flagF1.txt", "w+");
        fprintf(F1, "0");
        fclose(F1);
    }
    else if (f2 == 1) // если намерение войти в КО у обоих процессов
    {
        if (iz_p == 1)
        {
            printf("Process 1 get in critical section (2)");
            getchar();
            printf("Process 1 get out of critical section (2)\n");
            FILE *F1 = fopen("flagF1.txt", "w+");
            fprintf(F1, "0");
            fclose(F1);
        }
    }
    else if (f2 != 0 && f2 !=1)
    {
        printf("Something went wrong\n");
        printf("f1 = %c=d and f2 = %d\n", f1, f2);
        getchar();
        return (0);        
    }
}

int Procces2(int iz_p, int f1, int f2)
{
        FILE *F1 = fopen("flagF1.txt", "r+");
        if (F1 == NULL) //проверка на правильность открытия файла
        {
            printf("Wrong file");
            getchar();
            return 0;
        }
        f1 = fgetc(F1) -'0';
        fclose(F1);
        printf("\ndata before 2 process   f1 = %d and f2 = %d\n", f1, f2);


    if (f1 == 0) // если у 1 процесса нет намерения войти в КО
    {
        printf("Process 2 get in critical section");
        getchar();
        printf("Process 2 get out of critical section\n");
            FILE *F2 = fopen("flagFN.txt", "w+");
            fprintf(F2, "0");
            fclose(F2);
    }
    else if (f1 == 1) // если намерение войти в КО у обоих процессов
    {
        if (iz_p == 2)
        {
            printf("Process 2 get in critical section (2)");
            getchar();
            printf("Process 2 get out of critical section (2)\n");
            FILE *F2 = fopen("flagFN.txt", "w+");
            fprintf(F2, "0");
            fclose(F2);
        }
    }
    else if (f1 != 0 && f1 != 1)
    {
        printf("f1 = %d and f2 = %d\n", f1, f2);

        printf("Something went wrong\n");
        getchar();
        return (0);        
    }
    FILE *bh = fopen("flagFN.txt", "r+"); // проверяем намерение второго процесса
    FILE *bh2 = fopen("flagF1.txt", "r+");
    if ((bh == NULL) || (bh2 == NULL)) //проверка на правильность открытия файла
        {
            printf("Wrong file");
            getchar();
            return 0;
        }
            printf("\ndata after 2 process    f1 = %d and f2 = %d\n", fgetc(bh) -'0', fgetc(bh2) -'0');
        fclose(bh);
        fclose(bh2);
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int f1, f2;
    int iz_p = 1; // избранный процесс
    int nam = 1; // возможность войти в крит.область
    while (nam = 1)
    {
        Procces1(iz_p, 1, f2);
        Procces2(iz_p, f1, 1);
        printf("Checking iz_p: which process if favorite - 1 or 2?");
        iz_p = getchar();
    }
}