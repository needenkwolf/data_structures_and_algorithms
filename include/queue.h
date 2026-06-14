#ifndef QUEUE_H
#define QUEUE_H

struct queue {
	struct lnode *head;
	struct lnode *tail;
};

struct queue *createQueue();
int enqueue(struct queue *qu, void *value);
void *dequeue(struct queue *qu);
void *peekQueue(struct queue *qu);
int getSizeQueue(struct queue *qu);
void printQueue(struct queue *qu);
void deleteQueue(struct queue **qu);

#endif
