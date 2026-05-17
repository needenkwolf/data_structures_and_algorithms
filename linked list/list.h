#ifndef LIST_H
#define LIST_H

struct lnode {
	int data;
	struct lnode *next;
};

struct lnode *createLnode(int data);

struct lnode *insertAtLend(struct lnode *head, int data);
struct lnode *insertAtLbegin(struct lnode *head, int data);
struct lnode *insertAtLpos(struct lnode *head, int pos, int data);

struct lnode *deleteAtLend(struct lnode *head, int data);
struct lnode *deleteAtLbegin(struct lnode *head, int data);
struct lnode *deleteAtLpos(struct lnode *head, int pos, int data);

void printLaddr(struct lnode *l);
void printList(struct lnode *l);

void freeList(struct lnode **l);

#endif
