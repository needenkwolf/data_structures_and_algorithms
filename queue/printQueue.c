#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "list.h"
#include "queue.h"

void _printQueue(void *ldata)
{
	printf("%p -> ", ldata);
}

void printQueue(struct queue *qu)
{
	list_opts |= PRINT_NO_LIST;
	printf("QUEUE: ");
	printList(qu->head, TYPE_CUSTOM, _printQueue);
	list_opts &= ~PRINT_NO_LIST;
}
