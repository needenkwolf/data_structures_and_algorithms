#include <stdio.h>
#include "binarytree.h"

void printBtree(struct btnode *bt)
{
	if (bt == NULL) return;

	printBtree(bt->left);
	printf("%p ", bt->data);
	printBtree(bt->right);
	printf("\n");
}
