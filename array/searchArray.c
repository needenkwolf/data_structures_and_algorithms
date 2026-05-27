#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "../general/general.h"

void *lsearchArray(void *array, void *searching, int size, char data_type)
{
	for (int i = 0; i < size; i++) {
		switch (data_type) {
			case 'd':
				if (*((int*)array + i) == *(int*)searching)	 		return (int*)array + i;
				break;
			case 'f':
				if (*((double*)array + i) == *(double*)searching) 		return (double*)array + i;
				break;
			case 'c':
				if (*((char*)array + i) == *(char*)searching) 			return (char*)array + i;
				break;
			case 's':
				if (strcmp(*((char**)array + i), *(char**)searching) == 0) 	return (char**)array + i;
				break;
		}
	}

	return NULL;
}

void *bsearchArray(void *array, void *searching, int size, int sizePerItem, char data_type)
{
	void *found_item = NULL;

	switch (data_type) {
		case 'd':
		case 'f':
			found_item = bsearch(searching, array, size / sizePerItem, sizePerItem, compareNumeric);
			break;
		case 'c':
		case 's':
			found_item = bsearch(searching, array, size / sizePerItem, sizePerItem, compareString);
			break;
	}

	return found_item;
}
