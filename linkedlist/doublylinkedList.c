#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct lnode *dlnodeTolnode(struct dlnode *dl)
{
	struct lnode *sl = NULL;

	while (dl != NULL) {
		if (sl == NULL) {
			sl = createLnode(dl->data);
		} else {
			insertAtLend(&sl, dl->data);
		}
		dl = dl->next;
	}
	sl->next = NULL;

	return sl;
}

struct dlnode *lnodeTodlnode(struct lnode *sl) {
	struct dlnode *dl = malloc(sizeof(struct dlnode));

	struct dlnode *curr = dl;
	struct dlnode *prev = NULL;

	while (sl != NULL) {
		curr->data = sl->data;
		curr->prev = prev;

		if (sl->next != NULL) {
			curr->next = malloc(sizeof(struct dlnode));
		} else {
			curr->next = NULL;
		}

		sl = sl->next;
		prev = curr;
		curr = curr->next;

	}

	return dl;
}
