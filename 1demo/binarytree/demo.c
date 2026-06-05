#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../binarytree/binarytree.h"
#include "../../general/general.h"

int main()
{
	int two = 2;
	int four = 4;

	struct btnode *bt = createBtree();
	insertNodeBtree(bt, &two);
	insertNodeBtree(bt, &four);
	printBtree(bt);
	struct btnode *fourNode = searchNodeBtree(bt, &four);
	printf("%d\n", *((int*)fourNode->data));
	deleteNodeBtree(bt, &four);
	printBtree(bt);
	deleteBtree(&bt);
	printBtree(bt);
	return 0;
}
