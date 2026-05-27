#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "../general/general.h"

void qsortArray(void *array, int size, int sizePerItem, char data_type)
{
	switch (data_type) {
		case 'd':
		case 'f':
			qsort(array, size / sizePerItem, sizePerItem, compareNumeric);
			break;
		case 's':
			qsort(array, size / sizePerItem, sizePerItem, compareString);
			break;
	}
}
