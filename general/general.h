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

int compareNumeric(const void *a, const void *b);
int compareString(const void *a, const void *b);

#endif
