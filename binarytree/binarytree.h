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
int deleteNodeBtree(struct btnode *bt, void *data);
int deleteBtree(struct btnode *bt);
void dfsBtree(struct btnode *bt);
void bfsBtree(struct btnode *bt);

#endif
