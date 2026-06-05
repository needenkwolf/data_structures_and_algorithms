#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../linkedlist/list.h"
#include "../general/general.h"

void printStack(struct stack *st)
{
	struct dlnode *dl = st->head;
	printf("STACK: ");
	while (dl != NULL) {
		printf("%p -> ", dl);
		dl = dl->next;
	}
	printf("NULL\n");
}
