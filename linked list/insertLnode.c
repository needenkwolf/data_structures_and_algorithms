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
	if (head == NULL) return NULL;
	if (pos == 1) return insertAtLbegin(head, data);

	struct lnode *temp = head;
	int i = 2;
	while (head != NULL && i < pos) {
		head = head->next;
		i++;
	}
	temp = head->next;
	head->next = createLnode(data);
	head->next->next = temp;

	return head;
}
