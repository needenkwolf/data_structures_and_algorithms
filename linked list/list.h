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
struct lnode *getLmiddleNode(struct lnode *head);
int searchLnode(struct lnode *head, int data);

void printLaddr(struct lnode *l, char data_type);
void printList(struct lnode *l, char data_type);

void freeList(struct lnode **l);

struct lnode *reverseList(struct lnode *l);

struct lnode *createLcycle(struct lnode *head);
struct lnode *undoLcycle(struct lnode *head);
int checkLcircular(struct lnode *l);
void freeListCircular(struct lnode **l);
void printListCircular(struct lnode *l, char data_type);
void printLaddrCircular(struct lnode *l, char data_type);

struct lnode *dlnodeTolnode(struct dlnode *dl);
struct dlnode *lnodeTodlnode(struct lnode *sl);

void printDList(struct dlnode *dl, char data_type);
void printDLaddr(struct dlnode *dl, char data_type);
void printDListCircular(struct dlnode *dl, char data_type);
void printDLaddrCircular(struct dlnode *dl, char data_type);
void freeDList(struct dlnode **dl);

struct dlnode *createDLnode(void *data);
struct dlnode *insertAtDLend(struct dlnode **head, void *data);
struct dlnode *insertAtDLbegin(struct dlnode **head, void *data);
struct dlnode *insertAtDLpos(struct dlnode **head, int pos, void *data);
void deleteAtDLend(struct dlnode **dl);
struct dlnode *deleteAtDLbegin(struct dlnode **head);
struct dlnode *deleteAtDLpos(struct dlnode **head, int pos);

struct dlnode *createDLcycle(struct dlnode *head);
struct dlnode *undoDLcycle(struct dlnode *head);
int checkDLcircular(struct dlnode *head);

void *createArrayFromList(struct lnode *head, int size, int sizePerItem);
struct lnode *createListFromArray(void *array, int size, int sizePerItem);

#endif
