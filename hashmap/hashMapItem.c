#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "../array/array.h"
#include "../general/general.h"

int addHmapItem(struct hashmap *map, char *key, void *value, int itype)
{
	int asize = map->array->size;

	setHashMod(asize);

	int hashcode = hash(key);
	int start = hashcode;

	struct hmapitem *item = ((struct hmapitem**)(map->array->data))[hashcode];

	if (itype == TYPE_CUSTOM) {
		int (*f)(struct hashmap*, char*, void*) = map->array->func;
		return f(map, key, value);
	}

	int can_add = 0;
	do {
		item = ((struct hmapitem**)(map->array->data))[hashcode];
		if (item->key != NULL && strcmp(item->key, key) == 0) return 0;
		switch(itype) {
			case TYPE_INT:
				if ((item->key == NULL)
				|| (item->value == NULL)) {
					can_add = 1;
					if (item->value != NULL) free(item->value);
					item->value = malloc(sizeof(int));
					item->size = sizeof(int);
				}
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if ((item->key == NULL)
				|| (item->value == NULL)) {
					can_add = 1;
					if (item->value != NULL) free(item->value);
					item->value = malloc(sizeof(double));
					item->size = sizeof(double);
				}
				break;
			case TYPE_STRING:
				if ((item->key == NULL)
				|| (item->value == NULL)) {
					can_add = 1;
					if (item->value != NULL) free(item->value);
					int length = strlen(*(char**)value);
					item->value = malloc(sizeof(char) * length);
					item->size = sizeof(char) * length;
				}
				break;
			default:
				fprintf(stderr, "error: invalid type\n");
				return 0;
		}
		if (can_add) {
			item->key = key;
			item->type = itype;
			memcpy(item->value, value, item->size);
			return 1;
		} 		
		else { 
			hashcode = (hashcode + 1) % asize;
		}
	} while (hashcode != start);

	fprintf(stderr, "error: max size\n");
	return 0;
}

int removeHmapItem(struct hashmap *map, char *key)
{
	int asize = map->array->size;

	setHashMod(asize);

	int hashcode = hash(key);
	int start = hashcode;

	struct hmapitem *item = ((struct hmapitem**)(map->array->data))[hashcode];

	int itype = item->type;

	do {
		item = ((struct hmapitem**)(map->array->data))[hashcode];
		if (strcmp(item->key, key) == 0) {
			free(item->value);
			item->value = NULL;
			item->size = 0;
			item->key = "";
			item->type = TYPE_NONE;
			return 1;
		} else {
			hashcode = (hashcode + 1) % asize;
		}
	} while(hashcode != start);

	return 0;
}

void *getHmapItem(struct hashmap *map, char *key)
{	
	int asize = map->array->size;

	setHashMod(asize);

	int hashcode = hash(key);
	int start = hashcode;
	struct hmapitem *item = ((struct hmapitem**)(map->array->data))[hashcode];
	int itype = item->type;

	do {
		item = ((struct hmapitem**)(map->array->data))[hashcode];
		if (strcmp(item->key, key) == 0) {
			return item->value;
		} else {
			hashcode = (hashcode + 1) % asize;		
		}
	} while(hashcode != start);

	return NULL;
}
