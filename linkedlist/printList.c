#include <stdio.h>
#include "list.h"
#include "general.h"

int list_opts = 0;

void printList(struct lnode *l, int type, void (*print)(void*))
{
	if (list_opts & ~PRINT_NO_LIST) printf("LIST: ");
	while (l != NULL) {
		switch (type) {
			case TYPE_INT:
				printf("%d -> ", *((int*)l->data));
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				printf("%f -> ", *((double*)l->data));
				break;
			case TYPE_CHAR:
				printf("%c -> ", *((char*)l->data));
				break;
			case TYPE_STRING:
				printf("%s -> ", *((char**)l->data));
				break;
			case TYPE_CUSTOM:
				print(l->data);
				break;
			default:
				fprintf(stderr, "error printing list: invalid type\n");
				break;
		}
		l = l->next;
	}
	printf("NULL\n");
}

void printLaddr(struct lnode *l, int type, void (*print)(void*))
{
	printf("LIST ADDRESSES\n");
	while (l != NULL) {
		switch (type) {
			case TYPE_INT:
				printf("%p: %d\n", l, *((int*)l->data));
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				printf("%p: %f\n", l, *((double*)l->data));
				break;
			case TYPE_CHAR:
				printf("%p: %c\n", l, *((char*)l->data));
				break;
			case TYPE_STRING:
				printf("%p: %s\n", l, *((char**)l->data));
				break;
			case TYPE_CUSTOM:
				print(l->data);
				break;
			default:
				fprintf(stderr, "error printing list: invalid type\n");
				break;
		}
		l = l->next;
	}
}


void printListCircular(struct lnode *l, int type, void (*print)(void*))
{
	printf("LIST: ");

	struct lnode *head = l;
	do {
		switch (type) {
			case TYPE_INT:
				printf("%d -> ", *((int*)l->data));
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				printf("%f -> ", *((double*)l->data));
				break;
			case TYPE_CHAR:
				printf("%c -> ", *((char*)l->data));
				break;
			case TYPE_STRING:
				printf("%s -> ", *((char**)l->data));
				break;
			case TYPE_CUSTOM:
				print(l->data);
				break;
			default:
				fprintf(stderr, "error printing list: invalid type\n");
				break;
		}
		l = l->next;
	} while (l != head);

	printf("...\n");
}

void printLaddrCircular(struct lnode *l, int type, void (*print)(void*))
{
	printf("LIST ADDRESSES\n");

	struct lnode *head = l;
	do {
		switch (type) {
			case TYPE_INT:
				printf("%p: %d\n", l, *((int*)l->data));
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				printf("%p: %f\n", l, *((double*)l->data));
				break;
			case TYPE_CHAR:
				printf("%p: %c\n", l, *((char*)l->data));
				break;
			case TYPE_STRING:
				printf("%p: %s\n", l, *((char**)l->data));
				break;
			case TYPE_CUSTOM:
				print(l->data);
				break;
			default:
				fprintf(stderr, "error printing list: invalid type\n");
				break;
		}
		l = l->next;
	} while (l != head);
}

static void printDListReverse(struct dlnode *dl, int type, void (*print)(void*))
{
	printf("LIST: ");
	while (dl != NULL) {
		switch (type) {
			case TYPE_INT:
				printf("%d -> ", *((int*)dl->data));
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				printf("%f -> ", *((double*)dl->data));
				break;
			case TYPE_CHAR:
				printf("%c -> ", *((char*)dl->data));
				break;
			case TYPE_STRING:
				printf("%s -> ", *((char**)dl->data));
				break;
			case TYPE_CUSTOM:
				print(dl->data);
				break;
			default:
				fprintf(stderr, "error printing list: invalid type\n");
				break;
		}
		dl = dl->prev;
	}
	printf("NULL\n");
}

static void printDListCircularReverse(struct dlnode *dl, int type, void (*print)(void*))
{
	printf("LIST: ");

	struct dlnode *tail = dl;
	do {
		switch (type) {
			case TYPE_INT:
				printf("%d -> ", *((int*)dl->data));
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				printf("%f -> ", *((double*)dl->data));
				break;
			case TYPE_CHAR:
				printf("%c -> ", *((char*)dl->data));
				break;
			case TYPE_STRING:
				printf("%s -> ", *((char**)dl->data));
				break;
			case TYPE_CUSTOM:
				print(dl->data);
				break;
			default:
				fprintf(stderr, "error printing list: invalid type\n");
				break;
		}
		dl = dl->prev;
	} while (dl != tail);

	printf("...\n");
}

void printDList(struct dlnode *dl, int type, void (*print)(void*))
{
	if (dl->next != NULL) {
		printList((struct lnode*)dl, type, print);
	} else {
		printDListReverse(dl, type, print);
	}
}

void printDLaddr(struct dlnode *dl, int type, void (*print)(void*))
{
	printLaddr((struct lnode*)dl, type, print);
}

void printDListCircular(struct dlnode *dl, int type, void (*print)(void*))
{	
	if (dl->next != NULL) {
		printListCircular((struct lnode*)dl, type, print);
	} else {
		printDListCircularReverse(dl, type, print);
	}
}

void printDLaddrCircular(struct dlnode *dl, int type, void (*print)(void*))
{
	printLaddrCircular((struct lnode*)dl, type, print);
}
