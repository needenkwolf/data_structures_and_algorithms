#include <stdio.h>
#include <stdlib.h>
#include "../general/general.h"
#include "../linkedlist/list.h"
#include "queue.h"

int enqueue(struct queue *qu, void *value)
{
	if (qu->head == NULL) {
		qu->head = createLnode(value);
		qu->tail = qu->head;
		return 1;
	}
	qu->tail = insertAtLend(&qu->tail, value);
	if (qu->tail != NULL) return 1;

	return 0;
}

void *dequeue(struct queue *qu)
{
	void *data = qu->head->data;
	deleteAtLbegin(&qu->head);
	return data;
}

void *peekQueue(struct queue *qu)
{
	return qu->head->data;
}

int getSizeQueue(struct queue *qu)
{
	return getLsize(qu->head);
}
