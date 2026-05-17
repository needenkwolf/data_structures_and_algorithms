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
