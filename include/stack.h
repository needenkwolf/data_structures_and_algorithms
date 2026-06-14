#ifndef STACK_H
#define STACK_H

struct stack {
	struct dlnode *head;
	struct dlnode *tail;
};

struct stack *createStack();
int pushStack(struct stack *st, void *item);
void *peekStack(struct stack *st);
void *popStack(struct stack *st);
int getSizeStack(struct stack *st);
void printStack(struct stack *st);
void deleteStack(struct stack **st);


#endif
