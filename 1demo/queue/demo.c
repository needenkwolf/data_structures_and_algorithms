#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../linkedlist/list.h"
#include "../../queue/queue.h"
#include "../../general/general.h"

int main()
{
	struct queue *qu = createQueue();
	int num = 2;
	int num2 = 3;
	printf("len: %d\n", getSizeQueue(qu));
	enqueue(qu, &num);
	enqueue(qu, &num2);
	printf("num: %d\n", *(int*)dequeue(qu));
	printf("num: %d\n", *(int*)dequeue(qu));
	printf("len: %d\n", getSizeQueue(qu));
	enqueue(qu, &num2);
	enqueue(qu, &num);
	printf("len: %d\n", getSizeQueue(qu));
	printQueue(qu);
	deleteQueue(&qu);

	return 0;
}
