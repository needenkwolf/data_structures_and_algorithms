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
