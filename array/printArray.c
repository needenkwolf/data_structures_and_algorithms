#include <stdio.h>
#include "array.h"

void printArray(void *array, int n, char data_type)
{	
	switch (data_type) {
		case 'd':
			PRINT_ARRAY(array, n, "%d ", *((int*)array + i));
			break;
		case 'f':
			PRINT_ARRAY(array, n, "%f ", *((double*)array + i));
			break;
		case 'c':
			PRINT_ARRAY(array, n, "%c ", *((char*)array + i));
			break;
		case 's':
			PRINT_ARRAY(array, n, "%s ", *((char**)array + i));
			break;
	}
}
