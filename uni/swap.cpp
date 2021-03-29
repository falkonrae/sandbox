#include<stdlib.h>
#include<stdio.h>
#include "function.h"




int AddElement(int NewKey)
{
	int *n; //Промежуточная переменная
	if(massiv.mass==NULL) //Ввод первого элемента
	{
		massiv.mass=(int *)malloc(sizeof(int));
		if(massiv.mass==NULL)
			return –1;
		massiv.maxElement=1;
		massiv.nElement=0;
	}
	else //Ввод последующих элементов
	{
	massiv.maxElement++;
	n=(int *)realloc(massiv.mass, (massiv.maxElement)*sizeof(int));
	if (n==NULL)
	return –1;
	massiv.mass=n;
	}
	massiv.mass[massiv.nElement]=NewKey;
	return massiv.nElement++;
	} 

void swap(int index)
{
	int temp = massiv.mass[index];
	int counter = index;
	while (counter != 0_
	{
		massiv.mass[counter] = massiv.mass[counter-1];
		counter--;
	}
	massiv.mass[0] = temp;
	})
}


void main()
{
 int i;
 for (i=0; i<10; i++)
 AddElement(i*2);
 for (i=0; i<massiv.nElem.ent; i++)
 {
	 if ((massiv.mass[i] >= 0 ) && (i % 2 == 0))
	 {

	 	swap(i);
		 
 }
 printf("%d", massiv.mass[i]);

} 