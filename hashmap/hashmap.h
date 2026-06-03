#ifndef HASHMAP_H
#define HASHMAP_H

struct hmapitem {
	char *key;
	void *value;
	int size;
	int type;
};

struct hashmap {
	struct arr *array;
};

struct hashmap *createHashMap(int size);
int addHmapItem(struct hashmap *map, char *key, void *value, int itype);
int removeHmapItem(struct hashmap *map, char *key);
void *getHmapItem(struct hashmap *map, char *key);
void printHashMap(struct hashmap *map);
void deleteHashMap(struct hashmap **map);

#endif
