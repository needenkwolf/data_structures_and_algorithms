#include <stdio.h>
#include "list.h"

struct lnode *insertAtLend(struct lnode **head, int data)
{
	if (head == NULL) return NULL;

	struct lnode *p = (*head);

	while (p->next != NULL) {
		p = p->next;
	}

	p->next = createLnode(data);
	
	return p->next;
}

struct lnode *insertAtLbegin(struct lnode **head, int data)
{
	if (head == NULL) return NULL;
	
	struct lnode *new_node = createLnode(data);
	new_node->next = (*head);
	*head = new_node;
	return new_node;
}

struct lnode *insertAtLpos(struct lnode **head, int pos, int data)
{
	if (head == NULL) return NULL;
	
	if (pos <= 0) return NULL;
	if (pos == 1) return insertAtLbegin(head, data);

	struct lnode *temp = (*head);
	struct lnode *p = (*head);

	int i = 2;
	while (p != NULL && i < pos) {
		p = p->next;
		i++;
	}
	if (p == NULL) return NULL;

	temp = p->next;
	p->next = createLnode(data);
	p->next->next = temp;

	return p;
}
