#include "array.h"
#include <general.h>
#include <stdio.h>
#include <string.h>

int getItemArrayInt(struct arr *array, int n)
{
	return GET_ITEM_ARRAY(array, n, int);
}

double getItemArrayDouble(struct arr *array, int n)
{
	return GET_ITEM_ARRAY(array, n, double);
}

char getItemArrayChar(struct arr *array, int n)
{
	return GET_ITEM_ARRAY(array, n, char);
}

char *getItemArrayString(struct arr *array, int n)
{
	return GET_ITEM_ARRAY(array, n, char*);
}

void setItemArray(struct arr *array, int n, void *value)
{
	void *item = NULL;

	int sizePerItem = array->sizePerItem;
	
	memcpy(array->data + n * sizePerItem, value, sizePerItem);
}
