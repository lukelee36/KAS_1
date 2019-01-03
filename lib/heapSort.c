/*
 * heapSort.c
 *
 *  Created on: 19. 12. 2018
 *      Author: lukelee36
 */

#include <stdio.h>

static void swap(int *a, int *b)
{
	int t;

	t = *b;
	*b = *a;
	*a = t;
}

void heap(int array[], int number, int max)
{
	int largeNumber = max;
	int left = 2*max + 1;
	int right = 2*max + 2;

//	levy potomek je vetsi nez root
	if ((left < number) && (array[left] > array[largeNumber]))
	{
		largeNumber = left;
	}

//	pravy potomek je vetsi nez root
	if ((right < number) && (array[right] > array[largeNumber]))
	{
		largeNumber = right;
	}

//	Kdyz nejvyssi cislo neni root stromu
	if (largeNumber != max)
	{
		swap(&array[max], &array[largeNumber]);

//	Rekurzivni volani funkce
		heap(array, number, largeNumber);
	}
}

// Hlavni funkce na serazeni
void heapSort(int array[], int n)
{
//	vytvoreni heapu
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heap(array, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heap(array, i, 0);
	}
}

void printArray(int array[], int number)
{
	for (int i = 0; i < number; i++)
	{
		printf("%d \t", array[i]);
	}
	printf("\n");
}


