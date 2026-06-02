#include <stdio.h>
#include "general.h"

int hash_mod = 83;

void setHashMod(int n)
{
	hash_mod = n;
}

int hash(char *tohash)
{
	int value = 0;

	char *s = tohash;
	while (*s != '\0') {
		value += *s - '0';
		s++;
	}

	return value % hash_mod;
}
