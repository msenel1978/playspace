#ifndef queue_h
#define queue_h

typedef int data;

struct q_element {
	data d;
	struct q_element *next;
};

typedef struct q_element q_element_t;

typedef struct queue {
	int cnt;
	q_element_t *front;
	q_element_t *rear;
} queue_t;

void initialize_queue(queue_t *q);
void enqueue(data d, queue_t *q);
data dequeue(queue_t *q);
//data dequeue_rear(queue_t *q);
data queue_front(const queue_t *q);
int is_empty_queue(const queue_t *q);
int is_full_queue(const queue_t *q);
void replace_element_queue(queue_t *q, int indx, data d);
#endif