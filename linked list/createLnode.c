#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct lnode *createLnode(int data)
{
	struct lnode *l = (struct lnode*)malloc(sizeof(struct lnode));

	if (l == NULL) return NULL;

	l->data = data;
	l->next = NULL;

	return l;
}
