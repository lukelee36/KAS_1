/*
 * main.c
 *
 *  Created on: 3. 1. 2019
 *      Author: tichy
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/array.h"

char kas_mode_selected()
{
	return getchar();
}

buff * kas_read_file(char * file_name)
{
	FILE *fr;
	buff *buffer = create_buffer();
	char c[BUFF_SIZE];

	fr = fopen(file_name,"r");
	if(!fr)
	{
		fprintf(stderr, "Unable to open file %s", file_name);
		exit(1);
	}

	fscanf(fr,"%[^\n]", c);

	buffer->string = c;
	buffer->size = strlen(c);
	printf("\n buffer size: %d\n", buffer->size);
	//printf("Data from the file:\n%s", c);
	//printf("Data from the file:\n%s", buffer->string);

	fclose(fr);
	return buffer;
}

//	funkce na spocitani cetnosti pismen
array_string * frequency_print(char * string, int size)
{
	//char str[size] = string;
	array_string * array = create_array();

	for(char ch='A'; ch<='Z'; ch++)
	{
		int c = 0;
		for(int i = 0; i<size; i++)
		{
			if(ch==string[i])
			{
				c++;
			}
		}

		if(c>0)
		{
			push_array(array, ch, c);
			//printf("\n%c se objevilo tolikrat(%d)\n", array->ch, array->frequency);
		}
	}
	return array;
}

int main()
{
//	char mode;
//	char *file_name;
//	unsigned char buffer[BUFF_SIZE];   //65536 bit
	buff * buffer;
	array_string * array;

	setbuf(stdout, NULL);
	printf("Welcome in Huffmann coding app. \nPlease, select app mode (k - coding, d - decoding):");

	//mode = kas_mode_selected();
//	switch(mode)
//	{
//		case 'k':
//			printf("Code mode activaced! \nYour choose is: %c\n", mode);
//			break;
//		case 'd':
//			printf("Decode mode activaced! \nYour choose is: %c\n", mode);
//			break;
//	}

	setbuf(stdout, NULL);
	printf("\nPlease write name of file: ");
	//scanf("%s", file_name);
	// nacteni souboru
	buffer = kas_read_file("data.txt");
	kas_buffer_print(buffer);
	array = frequency_print(buffer->string, buffer->size);
	//TODO	omezeni znaku
	print_array(array);
	//free(buffer);
	return 0;
}
