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

	void check_res(char zr)		// проверка намерения первого и второго процесса войти
	{
		getchar();
		printf("Намерение первого процесса = %c\n", check_symb("flagF1.txt"));
		printf("Намерение второго процесса = %c\n", check_symb("flagF2.txt"));
		if (check_symb("flagF1.txt") == '0' && check_symb("flagF2.txt") == '0')
			printf("Процессы 1 и 2 не имеют намерения войти в критический участок\n");
		else if (check_symb("flagF1.txt") == '1' || check_symb("flagF2.txt") == '1')
			printf("Процесс 1 или 2 имеют намерение войти в критический участок\n");
		while ((check_symb("flagF1.txt") == '1') || (check_symb("flagF2.txt") == '1'))
			getchar(); 
	}

int main()
{
	char zr, fi1, fi2;
	zr = check_symb("flagZR.txt"); 
	fi1 = check_symb("flagF1.txt"); 
	fi2 = check_symb("flagF2.txt");

	getchar();
	write_symb("flagF3.txt", "1");
	printf("Программа запущена, намерение процесса 3 войти в критический участок = 1\n");

	check_res(zr);
	check_zr(zr);
	printf("Устанавливается занятость ресурса ZR = 1\n");
	write_symb("flagZR.txt", "1");

	getchar();
	printf("Процесс 3 вошел в критический участок");	
	while (getchar() != '0')
		printf("*");
	
	getchar();
	printf("Процесс 3 вышел из критического участка\n");
	write_symb("flagF3.txt", "0");

	getchar();	
	printf("Устанавливается занятость ресурса ZR = 0\n");
	write_symb("flagZR.txt", "0");
}

