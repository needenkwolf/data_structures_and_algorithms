#ifndef LIST_H
#define LIST_H

struct lnode {
	void *data;
	struct lnode *next;
};

struct dlnode {
	void *data;
	struct dlnode *next;
	struct dlnode *prev;
};

struct llist {
	struct lnode *head;
	struct lnode *tail;
};

struct dllist {
	struct dlnode *head;
	struct dlnode *tail;
};

struct lnode *createLnode(void *data);

struct lnode *insertAtLend(struct lnode **head, void *data);
struct lnode *insertAtLbegin(struct lnode **head, void *data);
struct lnode *insertAtLpos(struct lnode **head, int pos, void *data);

void deleteAtLend(struct lnode **head);
struct lnode *deleteAtLbegin(struct lnode **head);
struct lnode *deleteAtLpos(struct lnode **head, int pos);

int getLsize(struct lnode *head);
struct lnode *getLnode(struct lnode *head, int index);
int searchLnode(struct lnode *head, int data);

void printLaddr(struct lnode *l, char data_type);
void printList(struct lnode *l, char data_type);

void freeList(struct lnode **l);

struct lnode *dlnodeTolnode(struct dlnode *dl);

#endif
