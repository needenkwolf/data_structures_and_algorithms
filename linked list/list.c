#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{
	struct lnode *head = createLnode(3);

	insertAtLend(head, 7);
	insertAtLend(head, 8);
	head = insertAtLbegin(head, 1);
	insertAtLend(head, 9);

	printList(head);

	insertAtLpos(head, 3, 4);

	printList(head);

	head = deleteAtLbegin(head);
	deleteAtLend(head);

	printList(head);

	deleteAtLpos(head, 2);

	printList(head);
	printLaddr(head);

	freeList(&head);
	if (head == NULL) printf("list freed!\n");
	return 0;
}
