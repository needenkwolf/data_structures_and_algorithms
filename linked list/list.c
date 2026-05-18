#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{
	int h = 2;
	struct lnode *head = createLnode((void*)&h);

	int n = 7;
	insertAtLend(&head, (void*)&n);

	int m = 5;
	insertAtLbegin(&head, (void*)&m);

	printList(head, 'd');

	int listsize = getLsize(head);
	int valuetofind = 2;
	int foundindex = searchLnode(head, valuetofind);

	printf("searching for value %d on list of size %d\n", valuetofind, listsize);
	if (foundindex != -1) {
		struct lnode *foundnode = getLnode(head, foundindex);
		printf("%p: %d\n", foundnode, *((int*)foundnode->data));
	} else {
		printf("value not found\n");
	}

	freeList(&head);
	if (head == NULL) printf("list freed!\n");
	return 0;
}
