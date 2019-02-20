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

/* indx starts with 1 */
void replace_element_queue(queue_t *q, int indx, data d) {
	q_element_t *replace_element = q->front;
	int i;

	if (indx > q->cnt) {
		printf("Invalid indx\n");
		return;
	}

	for (i = 1; i <=indx; i++ )
		replace_element = replace_element->next;

	replace_element->d = d;

}

data queue_front(const queue_t *q) {
	return (q->front->d);
}

int is_empty_queue(const queue_t *q) {
	return ((q->cnt == 0) ? 1 : 0);
}
