#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "hashmap.h"
#include "general.h"

struct product {
	char *name;
	double price;
};

int addHmapProduct(struct hashmap *map, char *key, void *value, int hashcode)
{
	struct hmapitem *item = ((struct hmapitem**)(map->array->data))[hashcode];

	if ((item->key == NULL)
	|| (item->value == NULL)) {
		if (item->value != NULL) free(item->value);
		item->value = malloc(sizeof(struct product));
		item->size = sizeof(struct product);
		return 1;
	}

	return 0;
}

int main()
{
	struct hashmap *map = createHashMap(10);

	char *s = "hello world";
	addHmapItem(map, "greetings", &s, TYPE_STRING);

	int two = 2;
	addHmapItem(map, "number two", &two, TYPE_INT);

	printf("item: %d\n", *(int*)getHmapItem(map, "number two"));

	int three = 3;
	/* allows different values but not the same key*/
	addHmapItem(map, "numbertwo", &two, TYPE_INT);
	addHmapItem(map, "numberthree", &three, TYPE_INT);
	addHmapItem(map, "numbertwo", &two, TYPE_INT);
	addHmapItem(map, "number three", &three, TYPE_INT);
	addHmapItem(map, "number three", &two, TYPE_INT);
	addHmapItem(map, "number two", &three, TYPE_INT);
	addHmapItem(map, "number two", &two, TYPE_INT);

	struct product *apple = malloc(sizeof(struct product));	
	apple->name = malloc(sizeof(char) * 5);
	strcpy(apple->name, "apple");
	apple->price = 0.99;
	printf("name %s price %f\n", apple->name, apple->price);
	map->array->func = addHmapProduct;
	addHmapItem(map, "product 1", &apple, TYPE_CUSTOM);

	printHashMap(map);
	struct product *product1 = *(struct product**)getHmapItem(map, "product 1");
	printf("name %s price %f\n", product1->name, product1->price);


	removeHmapItem(map, "product 1");
	removeHmapItem(map, "greetings");

	printHashMap(map);

	deleteHashMap(&map);
	return 0;
}
