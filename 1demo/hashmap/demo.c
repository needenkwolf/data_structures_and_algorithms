#include <stdio.h>
#include "../../hashmap/hashmap.h"
#include "../../general/general.h"

int main()
{
	struct hashmap *map = createHashMap(3);

	char *s = "hello world";
	addHmapItem(map, "greetings", &s, TYPE_STRING);

	int two = 2;
	addHmapItem(map, "number two", &two, TYPE_INT);

	printf("item: %d\n", *(int*)getHmapItem(map, "number two"));

	addHmapItem(map, "number two", &two, TYPE_INT);
	addHmapItem(map, "number two", &two, TYPE_INT);
	addHmapItem(map, "number two", &two, TYPE_INT);
	addHmapItem(map, "number two", &two, TYPE_INT);
	addHmapItem(map, "number two", &two, TYPE_INT);
	addHmapItem(map, "number two", &two, TYPE_INT);
	addHmapItem(map, "number two", &two, TYPE_INT);

	printHashMap(map);

	removeHmapItem(map, "greetings");

	printHashMap(map);

	deleteHashMap(&map);
	return 0;
}
