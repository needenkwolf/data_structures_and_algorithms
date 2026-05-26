#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct lnode *createLnode(void *data)
{
	struct lnode *l = (struct lnode*)malloc(sizeof(struct lnode));

	if (l == NULL) return NULL;

	l->data = (void*)data;
	l->next = NULL;

	return l;
}

struct dlnode *createDLnode(void *data)
{
	struct dlnode *dl = (struct dlnode*)malloc(sizeof(struct dlnode));

	if (dl == NULL) return NULL;

	dl->data = (void*)data;
	dl->next = NULL;
	dl->prev = NULL;

	return dl;
}
