#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initialize_queue(queue_t *q) {
	q->cnt = 0;
	q->front = NULL;
	q->rear = NULL;
}

void enqueue(data d, queue_t *q) {
	q_element_t *new_element = malloc(sizeof(q_element_t));

	new_element->d = d;
	new_element->next = NULL;

	if (!(is_empty_queue(q))) {
		q->rear->next = new_element;
		q->rear = new_element;
	} else {
		q->front = new_element;
		q->rear = new_element;
	}

	q->cnt++;
}

data dequeue(queue_t *q) {
	data d;
	q_element_t *return_element;

	if (is_empty_queue(q))
		return (-1);

	d = q->front->d;
	return_element = q->front;

	q->front = q->front->next;
	q->cnt--;

	free(return_element);

	return d;
}

/*data dequeue_rear(queue_t *q) {
	int i;
	data d;
	q_element_t *return_element;
	q_element_t *previous_element;

	if (is_empty_queue(q))
		return (-1);

	d = q->rear->d;

	return_element = q->rear;
	previous_element = q->front;

	for (i = 0; i < q->cnt-1; i++)
		previous_element = previous_element->next;

	q->rear = previous_element;
	if (q->cnt > 1)
		free(return_element);

	return(d);
}*/

data front(const queue_t *q) {
	return (q->front->d);
}

int is_empty_queue(const queue_t *q) {
	return ((q->cnt == 0) ? 1 : 0);
}
