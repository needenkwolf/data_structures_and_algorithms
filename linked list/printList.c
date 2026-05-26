#include <stdio.h>
#include "list.h"

void printList(struct lnode *l, char data_type)
{
	printf("LIST: ");
	while (l != NULL) {
		switch (data_type) {
			case 'd':
				printf("%d -> ", *((int*)l->data));
				break;
			case 'f':
				printf("%f -> ", *((double*)l->data));
				break;
			case 'c':
				printf("%c -> ", *((char*)l->data));
				break;
			case 's':
				printf("%s -> ", *((char*)l->data));
				break;
		}
		l = l->next;
	}
	printf("NULL\n");
}

void printLaddr(struct lnode *l, char data_type)
{
	printf("LIST ADDRESSES\n");
	while (l != NULL) {
		switch (data_type) {
			case 'd':
				printf("%p: %d\n", l, *((int*)l->data));
				break;
			case 'f':
				printf("%p: %f\n", l, *((double*)l->data));
				break;
			case 'c':
				printf("%p: %c\n", l, *((char*)l->data));
				break;
			case 's':
				printf("%p: %s\n", l, *((char*)l->data));
				break;
		}
		l = l->next;
	}
}


void printListCircular(struct lnode *l, char data_type)
{
	printf("LIST: ");

	struct lnode *head = l;
	do {
		switch (data_type) {
			case 'd':
				printf("%d -> ", *((int*)l->data));
				break;
			case 'f':
				printf("%f -> ", *((double*)l->data));
				break;
			case 'c':
				printf("%c -> ", *((char*)l->data));
				break;
			case 's':
				printf("%s -> ", *((char*)l->data));
				break;
		}
		l = l->next;
	} while (l != head);

	printf("...\n");
}

void printLaddrCircular(struct lnode *l, char data_type)
{
	printf("LIST ADDRESSES\n");

	struct lnode *head = l;
	do {
		switch (data_type) {
			case 'd':
				printf("%p: %d\n", l, *((int*)l->data));
				break;
			case 'f':
				printf("%p: %f\n", l, *((double*)l->data));
				break;
			case 'c':
				printf("%p: %c\n", l, *((char*)l->data));
				break;
			case 's':
				printf("%p: %s\n", l, *((char*)l->data));
				break;
		}
		l = l->next;
	} while (l != head);
}

void printDList(struct dlnode *dl, char data_type)
{
	printList((struct lnode*)dl, data_type);
}

void printDLaddr(struct dlnode *dl, char data_type)
{
	printLaddr((struct lnode*)dl, data_type);
}

void printDListCircular(struct dlnode *dl, char data_type)
{
	printListCircular((struct lnode*)dl, data_type);
}

void printDLaddrCircular(struct dlnode *dl, char data_type)
{
	printLaddrCircular((struct lnode*)dl, data_type);
}
