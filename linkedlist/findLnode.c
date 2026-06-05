#include <stdio.h>
#include "list.h"

int getLsize(struct lnode *head) 
{
	if (head == NULL) return 0;

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

struct lnode *getLmiddleNode(struct lnode *l) {
	struct lnode *slow = l;
	struct lnode *fast = l;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
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
