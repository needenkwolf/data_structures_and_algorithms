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

void insertDLinteger(struct dlnode **dl, int number)
{
	int *n = malloc(sizeof(int));
	*n = number;
	insertAtDLend(dl, (void*)n);
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
	printListCircular(head, 'd');
	undoLcycle(head);
	if (checkLcircular(head)) {
		printf("Yes, it is circular!\n");
	} else {
		printf("No, it is not circular!\n");
	}

	struct lnode *middle = getLmiddleNode(head);
	printList(middle, 'd');

	struct dlnode *dl = lnodeTodlnode(head);
	printDList(dl, 'd');
	insertDLinteger(&dl, 16);
	insertDLinteger(&dl, 32);

	deleteAtDLbegin(&dl);

	printDList(dl, 'd');
	printList(head, 'd');

	createDLcycle(dl);
	printDListCircular(dl, 'd');
	undoDLcycle(dl);

	freeList(&head);
	freeDList(&dl);
	if (head == NULL && dl == NULL) printf("freed!\n");
	return 0;
}
