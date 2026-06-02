#include <stdio.h>
#include "../../hashset/hashset.h"
#include "../../general/general.h"

int main()
{
	struct hashset *set = createHashSet(10);
	addHashSetItem(set, "hi");

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

	return 0;
}
