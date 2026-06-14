#include <stdio.h>
#include "hashset.h"
#include "general.h"

int main()
{
	struct hashset *set = createHashSet(10);

	addHashSetItem(set, "hi");
	addHashSetItem(set, "greetings");
	addHashSetItem(set, "hi");
	addHashSetItem(set, "gj");

	if (containsHashSetItem(set, "hi")) {
		printf("yes!\n");
	} else {
		printf("no!\n");
	}

	if (containsHashSetItem(set, "hello")) {
		printf("yes!\n");
	} else {
		printf("no!\n");
	}

	if (containsHashSetItem(set, "hi")) {
		printf("yes!\n");
	} else {
		printf("no!\n");
	}

	removeHashSetItem(set, "hi");

	printHashSet(set);

	if (containsHashSetItem(set, "hi")) {
		printf("yes!\n");
	} else {
		printf("no!\n");
	}

	deleteHashSet(&set);

	return 0;
}
