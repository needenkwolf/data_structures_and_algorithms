#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "general.h"
#include "list.h"

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
