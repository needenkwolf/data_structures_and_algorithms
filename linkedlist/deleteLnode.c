#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void deleteAtLend(struct lnode **head)
{
	if (head == NULL || *head == NULL) 
		return;

	if ((*head)->next) {
		free(*head);
		*head = NULL;
		return;
	}

	struct lnode *p = (*head);

	while (p->next->next != NULL) {
		p = p->next;
	}

	free(p->next);
	p->next = NULL;
}

struct lnode *deleteAtLbegin(struct lnode **head)
{
	if (head == NULL || *head == NULL) 
		return NULL;

	struct lnode *next = (*head)->next;
	free((*head));
	*head = next;
	return next;
}

struct lnode *deleteAtLpos(struct lnode **head, int pos)
{
	if (head == NULL || *head == NULL) 
		return NULL;

	if (pos <= 0) return NULL;
	if (pos == 1) return deleteAtLbegin(head);

	struct lnode *temp = (*head);
	struct lnode *p = (*head);

	int i = 2;
	while (p->next->next != NULL && i < pos) {
		p = p->next;
		i++;
	}

	if (p == NULL) return NULL;
	if (p->next == NULL) return NULL;
	
	temp = p->next->next;

	free(p->next);
	p->next = NULL;
	
	if (temp != NULL) {
		p->next = temp;
	}
	
	return p->next;
}

void deleteAtDLend(struct dlnode **dl)
{
	if (dl == NULL || *dl == NULL) 
		return;

	if ((*dl)->next == NULL) {
		struct dlnode *prev = (*dl)->prev;
		free(*dl);
		*dl = prev;
		return;
	}

	struct dlnode *p = *dl;

	while (p->next->next != NULL) {
		p = p->next;
	}

	free(p->next);
	p->next = NULL;
}

struct dlnode *deleteAtDLbegin(struct dlnode **head)
{
	struct dlnode *ret = (struct dlnode*)deleteAtLbegin((struct lnode**)head);
	(*head)->prev = NULL;
	return ret;
}

struct dlnode *deleteAtDLpos(struct dlnode **head, int pos)
{
	return (struct dlnode*)deleteAtLpos((struct lnode**)head, pos);
}
