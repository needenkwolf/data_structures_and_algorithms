#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "list.h"
#include "stack.h"

int pushStack(struct stack *st, void *item)
{
	if (st->head == NULL || st->tail == NULL) {
		struct dlnode *node = createDLnode(item);
		st->head = node;
		st->tail = node;
		return 1;
	}
	
	if (st->tail != NULL && st->tail->next == NULL) {
		struct dlnode *temp = st->tail;
		st->tail->next = createDLnode(item);
		st->tail->next->prev = temp;
		st->tail = st->tail->next;
		if (st->head->next == NULL) {
			st->head->next = st->tail;
		}
	}

	if (st->tail != NULL) return 1;

	return 0;
}

void *peekStack(struct stack *st)
{
	return st->tail->data;
}

void *popStack(struct stack *st)
{
	if (st == NULL 
	|| st->tail == NULL
	|| st->head == NULL) 
		return NULL;

	void *item = st->tail->data;

	if (st->tail != NULL) {
		struct dlnode *prev = st->tail->prev;
		free(st->tail);
		st->tail = prev;
		if (st->tail != NULL) {
			st->tail->next = NULL;
		}
	}

	return item;
}

int getSizeStack(struct stack *st)
{
	if (st == NULL 
	|| st->head == NULL
	|| st->tail == NULL) 
		return 0;

	int i = 0;

	struct dlnode *dl = st->head;
	while (dl != NULL) {
		i++;
		dl = dl->next;
	}

	return i;
}

