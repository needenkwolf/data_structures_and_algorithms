#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "../general/general.h"

void qsortArray(void *array, int n, int sizePerItem, char data_type)
{
	switch (data_type) {
		case 'd':
		case 'f':
			qsort(array, n, sizePerItem, compareNumeric);
			break;
		case 's':
			qsort(array, n, sizePerItem, compareString);
			break;
	}
}
