#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void deleteAtLend(struct lnode **head)
{
	if (head == NULL) return;

	struct lnode *p = (*head);
	while (p->next->next != NULL) {
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
}

struct lnode *deleteAtLbegin(struct lnode **head)
{
	if (head == NULL) return NULL;

	struct lnode *next = (*head)->next;
	free((*head));
	*head = next;
	return next;
}

struct lnode *deleteAtLpos(struct lnode **head, int pos)
{
	if (head == NULL) return NULL;

	if (pos <= 0) return NULL;
	if (pos == 1) return deleteAtLbegin(head);

	struct lnode *temp = (*head);
	struct lnode *p = (*head);

	int i = 2;
	while (p->next->next != NULL && i < pos - 1) {
		p = p->next;
		i++;
	}
	if (p->next == NULL || p->next->next == NULL) return NULL;
	
	temp = p->next->next;

	free(p->next);
	p->next = NULL;
	
	if (temp != NULL) {
		p->next = temp;
	}
	
	return p;
}
