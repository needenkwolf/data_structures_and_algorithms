#ifndef BTREE_H
#define BTREE_H

struct btnode {
	void *data;
	struct btnode *left;
	struct btnode *right;
};

struct btnode *createBtree();
struct btnode *insertNodeBtree(struct btnode *bt, void *data);
struct btnode *searchNodeBtree(struct btnode *bt, void *data);
struct btnode *deleteNodeBtree(struct btnode *bt, void *data);
void deleteBtree(struct btnode **bt);
void printBtree(struct btnode *bt);

#endif
