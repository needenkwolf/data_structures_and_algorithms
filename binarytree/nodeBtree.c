#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

struct btnode *insertNodeBtree(struct btnode *bt, void *data)
{
	if (bt == NULL) return NULL;

	if(bt->data == NULL) {
		bt->data = data;
		return bt;
	}

	if (bt->left == NULL) {
		bt->left = createBtree();
		bt->left = insertNodeBtree(bt->left, data);
	} else {
		bt->right = createBtree();
		bt->right = insertNodeBtree(bt->right, data);
	}
	
	return NULL;
}

struct btnode *deleteNodeBtree(struct btnode *bt, void *data)
{
	if (bt == NULL) return NULL;

	bt->left = deleteNodeBtree(bt->left, data);
	bt->right = deleteNodeBtree(bt->right, data);
	if (bt->data == data) {
		bt->data = NULL;
		free(bt);
		bt = NULL;
	}

	return bt;
}

struct btnode *searchNodeBtree(struct btnode *bt, void *data)
{
	if (bt == NULL) return NULL;

	if (bt->data == data) {
		return bt;
	}

	struct btnode *node = NULL;

	node = searchNodeBtree(bt->left, data);
	if (node != NULL) return node;
	node = searchNodeBtree(bt->right, data);
	if (node != NULL) return node;

	return node;
}
