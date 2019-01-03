/*
 * array.h
 *
 *  Created on: 3. 1. 2019
 *      Author: tichy
 */

#ifndef LIB_ARRAY_H_
#define LIB_ARRAY_H_

#define BUFF_SIZE 8192

struct buff{
	char * string;
	unsigned int size;
};
typedef struct buff buff;

struct array_string{
	char ch;
	unsigned int frequency;
	struct array_string *next;
};
typedef struct array_string array_string;

array_string * create_array();
buff * create_buffer();
void kas_buffer_print(buff * buffer);
void push_array(array_string * array, char ch, unsigned int frequency);
void print_array(array_string * array);

#endif /* LIB_ARRAY_H_ */
