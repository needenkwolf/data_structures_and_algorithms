#include <string.h>
#include "general.h"

int compareNumeric(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int compareString(const void *a, const void *b)
{
	return strcmp(*(char**)a, *(char**)b);
}
