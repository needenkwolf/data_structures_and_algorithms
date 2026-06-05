#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

struct btnode *createBtree()
{
	struct btnode *bt = malloc(sizeof(struct btnode));

	bt->data = NULL;
	bt->left = NULL;
	bt->right = NULL;

	return bt;
}

void deleteBtree(struct btnode **bt)
{
	struct btnode *p = (*bt)->left;
	struct btnode *next = (*bt)->left;
	while (p != NULL) {
		next = p->left;
		free(p);
		p = next;
	}
	p = (*bt)->right;
	next = (*bt)->right;
	while (p != NULL) {
		next = p->right;
		free(p);
		p = next;
	}
	free(*bt);
	*bt = NULL;
}
