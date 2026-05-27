#include <stdio.h>
#include "list.h"

struct lnode *reverseList(struct lnode *l)
{
	struct lnode *curr = l;

	struct lnode *prev = NULL;
	struct lnode *next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}

	return prev;
}
