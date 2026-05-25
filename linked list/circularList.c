#include <stdio.h>
#include "list.h"

struct lnode *createLcycle(struct lnode *head)
{
	struct lnode *p = head;
	while (p->next != NULL) {	
		p = p->next;
	}
	p->next = head;

	return head;
}

struct lnode *undoLcycle(struct lnode *head){
	struct lnode *p = head;
	while (p->next != head) {
		p = p->next;
	}
	p->next = NULL;

	return head;
}

int checkLcircular(struct lnode *l)
{
	struct lnode *slow = l;
	struct lnode *fast = l;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		
		if (slow == fast) {
			return 1;
		}
	}

	return 0;
}
