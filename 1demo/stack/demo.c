#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "stack.h"
#include "general.h"

int main()
{
	struct stack *st = createStack();
	int num = 2;
	int num2 = 3;
	printf("len: %d\n", getSizeStack(st));
	pushStack(st, &num);
	pushStack(st, &num2);
	printf("num: %d\n", *(int*)popStack(st));
	printf("num: %d\n", *(int*)popStack(st));
	printf("len: %d\n", getSizeStack(st));
	pushStack(st, &num2);
	pushStack(st, &num);
	printf("len: %d\n", getSizeStack(st));
	printStack(st);
	deleteStack(&st);

	return 0;
}
