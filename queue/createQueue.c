#include <stdio.h>
#include <stdlib.h>
#include "../general/general.h"
#include "../linkedlist/list.h"
#include "queue.h"

struct queue *createQueue()
{
	struct queue *qu = malloc(sizeof(struct queue));
	qu->head = NULL;

	return qu;
}

void deleteQueue(struct queue **qu)
{
	freeList(&((*qu)->head));
	free((*qu));
	*qu = NULL;
}

