#include <stdio.h>
#include "list.h"

int getLsize(struct lnode *head) 
{
	int i;
	for (i = 1; head->next != NULL; i++) {
		head = head->next;
	}
	return i;
}

struct lnode *getLnode(struct lnode *head, int index)
{
	int c = 1;
	while (head != NULL && c < index) {
		head = head->next;
		c++;
	}
	if (head == NULL && c < index) return NULL;

	return head;
}

int searchLnode(struct lnode *head, int data)
{
	for (int i = 1; head != NULL; i++) {
		if (*((int*)head->data) == data) {
			return i;
		}
		head = head->next;
	}
	return -1;
}
