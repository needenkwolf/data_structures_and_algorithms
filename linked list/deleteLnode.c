#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void deleteAtLend(struct lnode *head)
{
	if (head == NULL) return;

	while (head->next->next != NULL) {
		head = head->next;
	}
	free(head->next);
	head->next = NULL;
}

struct lnode *deleteAtLbegin(struct lnode *head)
{
	if (head == NULL) return NULL;

	struct lnode *next = head->next;
	free(head);
	return next;
}

struct lnode *deleteAtLpos(struct lnode *head, int pos)
{
	if (head == NULL) return NULL;
	if (pos == 1) return deleteAtLbegin(head);

	struct lnode *temp = head;

	int i = 2;
	while (head->next->next != NULL && i < pos - 1) {
		head = head->next;
		i++;
	}
	
	temp = head->next->next;

	free(head->next);
	head->next = NULL;
	
	if (temp != NULL) {
		head->next = temp;
	}
	
	return head;
}
