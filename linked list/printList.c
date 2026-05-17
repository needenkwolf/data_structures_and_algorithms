#include <stdio.h>
#include "list.h"

void printList(struct lnode *l)
{
	printf("LIST: ");
	while (l != NULL) {
		printf("%d -> ", l->data);
		l = l->next;
	}
	printf("NULL\n");
}

void printLaddr(struct lnode *l)
{
	printf("LIST ADDRESSES\n");
	while (l != NULL) {
		printf("%p: %d\n", l, l->data);
		l = l->next;
	}
}
