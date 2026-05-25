#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

struct lnode *createIntegerList(int number)
{
	int *n = malloc(sizeof(int));
	*n = number;
	return createLnode((void*)n);
}

void insertInteger(struct lnode **l, int number)
{
	int *n = malloc(sizeof(int));
	*n = number;
	insertAtLend(l, (void*)n);
}

int main(int argc, char *argv[])
{
	struct lnode *head = createIntegerList(2);

	insertInteger(&head, 7);

	insertInteger(&head, 4);

	insertInteger(&head, 3);

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

	createLcycle(head);
	if (checkLcircular(head)) {
		printf("Yes, it is circular!\n");
	} else {
		printf("No, it is not circular!\n");
	}
	undoLcycle(head);
	if (checkLcircular(head)) {
		printf("Yes, it is circular!\n");
	} else {
		printf("No, it is not circular!\n");
	}

	struct lnode *middle = getLmiddleNode(head);
	printList(middle, 'd');

	freeList(&head);
	if (head == NULL) printf("list freed!\n");
	return 0;
}
