#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void freeList(struct lnode **l)
{
	struct lnode *p = NULL;
	while (*l != NULL) {
		p = (*l)->next;
		free(*l);
		*l = p;
	}
}

void freeListCircular(struct lnode **l)
{
	struct lnode *p = NULL;
	struct lnode *head = *l;
	while (*l != NULL) {
		p = (*l)->next;
		if (*l != head) {
			free(*l);
			*l = p;
		} else {
			*l = NULL;
		}
	}
}
