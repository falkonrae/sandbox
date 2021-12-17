#include <stdio.h>
#include <stdlib.h>

	char check_symb(char* f)
	{
		char c;
		FILE *F = fopen(f, "r+"); 
		c = fgetc(F); 
		fclose(F);
		return c;
	}

	char write_symb(char* f, char* c)
	{
		FILE *F = fopen(f, "w+"); 
		fprintf(F, c);
		fclose(F);
	}

int check_zr(char zr)		// проверка занятости ресурса
{
	int i;
	zr = check_symb("flagZR.txt"); 
		printf("Занятость ресурса ZR = %c\n", zr);
		if (zr == '1')
		{
				i = 1;
				printf("Ресурс занят\n");
				getchar();

				while (zr != '0')
				{
					zr = check_symb("flagZR.txt"); 
					if (zr == '0')
						break;
					getchar();

				}
		}
		if (zr == '0')
		{
			i = 0;
			printf("Ресурс свободен\n");
			getchar();
		}
	return i;
}


void check_res(char zr)	// проверка намерения первого процесса войти
{
	getchar();
	printf("Намерение первого процесса = %c\n", check_symb("flagF1.txt"));
	if (check_symb("flagF1.txt") == '0')
		printf("Процесс 1 не имеет намерения войти в критический участок\n");
	else if (check_symb("flagF1.txt") == '1')
		printf("Процесс 1 имеет намерение войти в критический участок\n");
	while (check_symb("flagF1.txt") != '0')
		getchar();
}

int main()
{
	char zr, fi1;
	zr = check_symb("flagZR.txt"); 
	fi1 = check_symb("flagF1.txt");

	getchar();
	write_symb("flagF2.txt", "1");
	printf("Программа запущена, намерение процесса 2 войти в критический участок = 1\n");

	check_res(zr);
	check_zr(zr);
	printf("Устанавливается занятость ресурса ZR = 1\n");
	write_symb("flagZR.txt", "1");

	getchar();
	printf("Процесс 2 вошел в критический участок");
	while (getchar() != '0')
		printf("-");

	getchar();
	printf("Процесс 2 вышел из критического участка\n");
	write_symb("flagF2.txt", "0");

	getchar();	
	printf("Устанавливается занятость ресурса ZR = 0\n");
	write_symb("flagZR.txt", "0");
}
