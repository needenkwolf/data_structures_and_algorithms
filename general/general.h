#ifndef GENERAL_H
#define GENERAL_H

enum {
	TYPE_NONE,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_CHAR,
	TYPE_STRING,
	TYPE_CUSTOM
};

extern int hash_mod;

void setHashMod(int n);
int hash(char *tohash);

int compareNumeric(const void *a, const void *b);
int compareString(const void *a, const void *b);

#endif
