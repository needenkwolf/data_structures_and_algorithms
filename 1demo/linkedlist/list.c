#include <stdio.h>
#include <stdlib.h>
#include "../../linkedlist/list.h"

struct lnode *createIntegerList(int number)
{
	int *n = malloc(sizeof(int));
	*n = number;
	return createLnode((void*)n);
}

struct dlnode *createIntegerDList(int number)
{
	int *n = malloc(sizeof(int));
	*n = number;
	return createDLnode((void*)n);
}

struct lnode *insertInteger(struct lnode **l, int number)
{
	int *n = malloc(sizeof(int));
	*n = number;
	return insertAtLend(l, (void*)n);
}

struct dlnode *insertDLinteger(struct dlnode **dl, int number)
{
	int *n = malloc(sizeof(int));
	*n = number;
	return insertAtDLend(dl, (void*)n);
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
	struct dlnode *dltail = dl;
	dltail = insertDLinteger(&dltail, 16);
	dltail = insertDLinteger(&dltail, 32);
	printDList(dl, 'd');
	printDList(dltail, 'd');

	deleteAtDLbegin(&dl);

	printList(head, 'd');

	createDLcycle(dl);
	printDListCircular(dl, 'd');
	undoDLcycle(dl);


	printList(head, 'd');

	int *array = createArrayFromList(head, (getLsize(head) * sizeof(int)), sizeof(int));

	printf("array: ");
	for (int i = 0; i < getLsize(head); i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	int array2[3] = {78, 32, 18};

	struct lnode *lArr = createListFromArray(array2, 3 * sizeof(int), sizeof(int));

	printList(lArr, 'd');

	freeList(&head);
	freeList(&lArr);
	freeDList(&dl);
	if (head == NULL && dl == NULL) printf("freed!\n");
	return 0;
}
