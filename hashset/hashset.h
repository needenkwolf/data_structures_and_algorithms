#ifndef HASHSET_H
#define HASHSET_H

struct hashset {
	struct arr *array;
};

struct hashset *createHashSet(int size);
int addHashSetItem(struct hashset *set, char *item);
int removeHashSetItem(struct hashset *set, char *item);
int containsHashSetItem(struct hashset *set, char *item);
void printHashSet(struct hashset *set);
void deleteHashSet(struct hashset **set);

#endif
