#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void *createArrayFromList(struct lnode *head, int size, int sizePerItem)
{
	void *array = (void *)malloc(size);

	for (int i = 0; head != NULL; i += sizePerItem) {
		memcpy((unsigned char*)array + i, head->data, sizePerItem);
		head = head->next;
	}

	return array;
}

struct lnode *createListFromArray(void *array, int size, int sizePerItem)
{
	struct lnode *head = createLnode(array);

	struct lnode *p = head;
	for (int i = sizePerItem; i < size; i += sizePerItem) {
		insertAtLend(&head, array + i);
		p = p->next;
	}
	p->next = NULL;

	return head;
}
