#include <stdio.h>
#include "list.h"

struct lnode *insertAtLend(struct lnode *head, int data)
{
	if (head == NULL) return NULL;

	while (head->next != NULL) {
		head = head->next;
	}

	head->next = createLnode(data);
	return head->next;
}

struct lnode *insertAtLbegin(struct lnode *head, int data)
{
	if (head == NULL) return NULL;
	
	struct lnode *new_node = createLnode(data);

	new_node->next = head;

	return new_node;
}

struct lnode *insertAtLpos(struct lnode *head, int pos, int data)
{
	struct lnode *new_node = createLnode(data);

	return new_node;
}
