/*
 * array.c
 *
 *  Created on: 3. 1. 2019
 *      Author: tichy
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

array_string * create_array()
{
	array_string * array = (array_string*)malloc(sizeof(array_string));
	array->ch=0;
	array->frequency = 0;
	array->next = NULL;
	return array;
}

buff * create_buffer()
{
	buff * buffer = (buff*) malloc(sizeof(buff));
	buffer->size = 0;
	buffer->string = "";
	return buffer;
}

void kas_buffer_print(buff * buffer)
{
	int i;
	for(i = 0; i < buffer->size; i++)
	{
		printf("%c", buffer->string[i]);
	}
}

bool empty_array(array_string * array)
{
	return array->next == NULL;
}

void push_array(array_string * array, char ch, unsigned int frequency)
{
	if(array->ch == 0 && array->frequency==0)
	{
		array->ch = ch;
		array->frequency = frequency;
//		array->next = array->next;
	}
	else
	{
		if(array->next!=NULL)
		{
			push_array(array->next, ch, frequency);
		}
		else
		{
		array->next = malloc(sizeof(array_string));
		array->next->ch = ch;
		array->next->frequency = frequency;
		array->next->next = NULL;
		}
	}

}

void print_array(array_string * array)
{
	int size = sizeof(array);
	int i=0;
	for(i; i<=size; i++)
	{
		printf("\n%c se objevilo tolikrat(%d)\n", array->ch, array->frequency);
		array = array->next;
	}
}












