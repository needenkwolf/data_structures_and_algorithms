#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{
	struct lnode *head = createLnode(3);
	insertAtLend(head, 7);
	insertAtLend(head, 8);
	head = insertAtLbegin(head, 1);
	insertAtLend(head, 8);
	printList(head);
	insertAtLpos(head, 2, 3);
	printLaddr(head);
	freeList(&head);
	if (head == NULL) printf("list freed!\n");
	return 0;
}
