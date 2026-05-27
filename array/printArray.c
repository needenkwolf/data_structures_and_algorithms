#include <stdio.h>

void printArray(void *array, int size, char data_type)
{	
	printf("array: ");
	for (int i = 0; i < size; i++) {
		switch (data_type) {
			case 'd':
				printf("%d ", *((int *)array + i));
				break;
			case 'f':
				printf("%f ", *((double *)array + i));
				break;
			case 'c':
				printf("%c ", *((char *)array + i));
				break;
			case 's':
				printf("%s ", *((char **)array + i));
				break;
		}
	}
	printf("\n");
}
