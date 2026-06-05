#include <stdio.h>
#include <stdlib.h>
#include "../general/general.h"
#include "../linkedlist/list.h"
#include "stack.h"

struct stack *createStack()
{
	struct stack *st = malloc(sizeof(struct stack));

	st->head = NULL;
	st->tail = NULL;

	return st;
}

void deleteStack(struct stack **st)
{
	struct dlnode *curr = (*st)->head;

	struct dlnode *next = curr;
	while (curr != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	free((*st));
	*st = NULL;
}
